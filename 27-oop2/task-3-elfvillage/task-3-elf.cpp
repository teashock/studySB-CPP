#include <iostream>
#include <vector>
#include <ctime>

class Branch {
public:
    std::string elfName;
    Branch* parent;
    std::vector<Branch*> children;

    Branch(Branch* parent = nullptr) : parent(parent) {}

    Branch* findElf(std::string elfName) {
        if (this->elfName == elfName) {
            return this;
        }
        for (int i = 0; i < children.size(); ++i) {
            Branch* found = children[i]->findElf(elfName);
            if (found) {
                return found;
            }
        }
        return nullptr;
    }

    Branch* getTopBranch() {
        if (parent == nullptr) return nullptr;
        if (parent->parent == nullptr) return parent;
        return parent->getTopBranch();
    }

    void addChild(Branch* child) {
        children.push_back(child);
    }
};  

class Tree {
public:
    Branch* tree;

    Tree() {
        tree = new Branch();
    }

    void generateTree() {
        int numBigBranches = rand() % 3 + 3;
        for (int i = 0; i < numBigBranches; ++i) {
            Branch* bigBranch = new Branch(tree);
            tree->addChild(bigBranch);
            int numMediumBranches = rand() % 2 + 2;
            for (int j = 0; j < numMediumBranches; ++j) {
                Branch* mediumBranch = new Branch(bigBranch);
                bigBranch->addChild(mediumBranch);
            }
        }
    }
};

int countNeighbors(Branch* branch) {
    int count = 0;
    if (branch->parent) {
        std::vector<Branch*>::iterator it = branch->parent->children.begin();
        std::vector<Branch*>::iterator end = branch->parent->children.end();

        while (it != end) {
            Branch* neighbor = *it;
            if (neighbor != branch && !neighbor->elfName.empty()) {
                count++;
            }
            ++it;
        }
    }
    return count;
}

int main() {
    std::srand(std::time(nullptr));
    Tree forest[5];
    for (int i = 0; i < 5; ++i) {
        forest[i].generateTree();
    }

    for (int i = 0; i < 5; ++i) {
        int treeIndex = i + 1;
        for (int j = 0; j < forest[i].tree->children.size(); ++j) {
            auto bigBranch = forest[i].tree->children[j];
            int bigBranchIndex = j + 1;
            for (int k = 0; k < bigBranch->children.size(); ++k) {
                auto mediumBranch = bigBranch->children[k];
                int mediumBranchIndex = k + 1;
    
                std::cout << "Enter the name of the elf living on medium branch " << mediumBranchIndex << " of big branch " << bigBranchIndex << " of tree " << treeIndex << " (or none for an empty house)" << std::endl;
                std::string elfName;
                std::cin >> elfName;
                if (elfName != "None") {
                    mediumBranch->elfName = elfName;
                }
            }
        }
    }

    while (true) {
        std::cout << "Enter the name of the elf for searching (or 'exit' to closed program): ";
        std::string searchElfName;
        std::cin >> searchElfName;

        if (searchElfName == "exit") break;

        Branch* foundBranch = nullptr;
        for (int i = 0; i < 5; ++i) {
            foundBranch = forest[i].tree->findElf(searchElfName);
            if (foundBranch) {
                break;
            }
        }

        if (foundBranch) {
            int neighbors = countNeighbors(foundBranch);
            std::cout << "The number of neighbors of elf " << searchElfName << " on the branch is " << neighbors << std::endl;
        } else {
            std::cout << "The elf named " << searchElfName << " has not been found." << std::endl;
        }
    }
    return 0;
}