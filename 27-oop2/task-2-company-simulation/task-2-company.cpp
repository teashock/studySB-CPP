#include <iostream>
#include <vector>
#include <ctime>

enum class TaskType {
    A,
    B,
    C
};

struct Task {
    TaskType type;
    Task(TaskType t) : type(t) {}
    std::string getTaskName() {
        switch (type) {
            case TaskType::A: return "\"Task A\"";
            case TaskType::B: return "\"Task B\"";
            case TaskType::C: return "\"Task C\"";
        }
        return "Unknown task";
    }
};

class Worker {
public:
    std::string name;
    Task currentTask;
    bool busyWorker = false;
    
    Worker(std::string valueName) : name(valueName), currentTask(Task(TaskType::A)) {}

    bool isBusy() {
        return busyWorker;
    }

    void receiveTask(Task task) {
        currentTask = task;
        busyWorker = true;
        std::cout << "Worker " << name << " received task " << task.getTaskName() << std::endl;
    }
};

class Manager {
public:
    std::string name;
    std::vector<Worker*> workers;
    int taskId;

    Manager(std::string voidName, int voidTaskId) : name(voidName), taskId(voidTaskId) {}

    void addWorker(Worker* worker) {
        workers.push_back(worker);
    }

    void receiveTask(int directive) {
        int hash = taskId + directive;
        std::srand(hash);
        int tasksCount = std::rand() % (workers.size() + 1);

        if (tasksCount == 0 && workers.size() > 0) {
            tasksCount = 1;
        }
    
        int freeWorkersCount = 0;
        for (int i = 0; i < workers.size(); ++i) {
            if (!workers[i]->isBusy()) {
                freeWorkersCount++;
            }
        }
    
        if (freeWorkersCount == 0) {
            std::cout << "The manager " << name << " does not have any available workers. Cannot assign tasks." << std::endl;
            std::cout << "----------------------\n";
            return;
        }
    
        tasksCount = std::min(tasksCount, freeWorkersCount);
    
        int assignedTasks = 0;
        std::cout << "Manager " << name << " received directive " << directive << " and assigned " << tasksCount << " tasks." << std::endl;
    
        while (assignedTasks < tasksCount) {
            int workerIndex = std::rand() % workers.size();
            if (!workers[workerIndex]->isBusy()) {
                Task task(static_cast<TaskType>(std::rand() % 3));
                workers[workerIndex]->receiveTask(task);
                assignedTasks++;
            }
        }

        int remainingFreeWorkers = 0;
        for (int i = 0; i < workers.size(); ++i) {
            if (!workers[i]->isBusy()) {
                remainingFreeWorkers++;
            }
        }
        std::cout << "After assigning tasks, " << remainingFreeWorkers << " workers are still free." << std::endl;
        std::cout << "------------------------------\n";
    }
};

class Director {
public:
    std::string name;
    std::vector<Manager*> managers;
    
    Director(std::string valueName) : name(valueName) {}
    
    void giveDirective(int directive) {
        std::cout << "Director " << name << " gives directive number " << directive << std::endl;
        for (int i = 0; i < managers.size(); ++i) {
            managers[i]->receiveTask(directive);
        }
    }   
};

bool allWorkersBusy(const std::vector<Worker*>& workers) {
    for (int i = 0; i < workers.size(); ++i) {
        if (!workers[i]->isBusy()) {
            return false;
        }
    }
    return true;
}

int main() {
    int numTeams, numWorkers;
    while (true) {
        std::cout << "Enter number of teams: ";
        std::cin >> numTeams;
        std::cout << "Enter number of workers per team: ";
        std::cin >> numWorkers;
        if (numWorkers <= 0 || numTeams <= 0) {
            std::cout << "Number of teams and number of workers must be greater than 0! Try again!\n";
            continue;
        } else {
            break;
        }
    }
    
    Director director("Ilya");
    std::vector<Manager*> managers;
    std::vector<Worker*> workers;
    
    for (int i = 0; i < numTeams; ++i) {
        Manager* manager = new Manager(std::to_string(i + 1), i + 1);
        director.managers.push_back(manager);
        managers.push_back(manager);
        
        for (int j = 0; j < numWorkers; ++j) {
            Worker* worker = new Worker(std::to_string(i + 1) + "-" + std::to_string(j + 1));
            manager->workers.push_back(worker);
            workers.push_back(worker);
        }
    }
    
    int directive;
    while (true) {
        std::cout << "!!!!!!!!!!!!!!!!\n";
        std::cout << "Enter directive: ";
        std::cin >> directive;
        if (directive <= 0) {
            std::cout << "The number of directives must be greater than 0!\n";
        } else {
            director.giveDirective(directive);
            if (allWorkersBusy(workers)) {
                std::cout << "All workers are busy. Exiting program." << std::endl;
                break;
            }
        }
    }

    for (int i = 0; i < workers.size(); ++i) {
        delete workers[i];
    }
    for (int i = 0; i < managers.size(); ++i) {
        delete managers[i];
    }
    return 0;
}