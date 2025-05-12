#include<iostream>
#include<map>

bool searchanagram(std::string str1, std::string str2) {
    std::map<char, int> word1;
    std::map<char, int> word2;
    if (str1.length() != str2.length()) {
        return false;
    }

    for (int i = 0; i < str1.length(); ++i) {
        if (word1.find(str1[i]) != word1.end()){
            word1[str1[i]]++;
        } else {
            word1.insert(std::make_pair(str1[i], 1));
        }
    }

    for (int i = 0; i < str2.length(); ++i) {
        if (word2.find(str2[i]) != word2.end()){
            word2[str2[i]]++;
        } else {
            word2.insert(std::make_pair(str2[i], 1));
        }
    }

    if (word1 == word2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::cout << "Search for anograms!\n";
    std::string str1, str2;

    std::cout << "Enter two words: ";
    std::cin >> str1 >> str2;

    std::cout << searchanagram(str1, str2);
}
