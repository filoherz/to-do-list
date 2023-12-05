#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};


void addTask(std::vector<Task>& tasks, const std::string& description) {
    Task newTask = {description, false};
    tasks.push_back(newTask);
}


void viewTasks(const std::vector<Task>& tasks) {
    std::cout << "Tasks:\n";
    int count = 1;
    for (const auto& task : tasks) {
        std::cout << count << ". " << task.description;
        if (task.completed) {
            std::cout << " - Completed";
        } else {
            std::cout << " - Pending";
        }
        std::cout << std::endl;
        count++;
    }
}


void markAsCompleted(std::vector<Task>& tasks, int taskNumber) {
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}


void removeTask(std::vector<Task>& tasks, int taskNumber) {
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "\nOptions:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 5) {
            break;
        }

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                int taskNum;
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskNum;
                markAsCompleted(tasks, taskNum);
                break;
            }
            case 4: {
                int taskNum;
                std::cout << "Enter task number to remove: ";
                std::cin >> taskNum;
                removeTask(tasks, taskNum);
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
