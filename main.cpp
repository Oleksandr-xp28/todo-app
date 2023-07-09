#include "intro_screen.h"

#include <iostream>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

struct Menu {
    void print() {
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Complete task\n";
        cout << "4. Quit\n";
    }
};

void addTask(Task* tasks, int& taskCount, int maxTasks) {
    if (taskCount == maxTasks) {
        cout << "Task list is full!\n";
        return;
    }
    string input;
    cout << "Enter task description: ";
    getline(cin, input);
    tasks[taskCount].description = input;
    tasks[taskCount].completed = false;
    taskCount++;
}

void viewTasks(Task* tasks, int taskCount) {
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " [COMPLETED]";
        }
        cout << "\n";
    }
    cout << "Press enter to continue...";
    cin.ignore();
}

void completeTask(Task* tasks, int taskCount) {
    int taskNumber;
    cout << "Enter task number to complete: ";
    cin >> taskNumber;
    cin.ignore();
    if (taskNumber < 1 || taskNumber > taskCount) {
        cout << "Invalid task number!\n";
        return;
    }
    tasks[taskNumber - 1].completed = true;
}

int main() {
    int maxTasks = 100;
    Task* tasks = new Task[maxTasks];
    int taskCount = 0;
    Menu menu;
    while (true) {
        menu.print();
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            addTask(tasks, taskCount, maxTasks);
        }
        else if (choice == 2) {
            viewTasks(tasks, taskCount);
        }
        else if (choice == 3) {
            completeTask(tasks, taskCount);
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    delete[] tasks;
    return 0;
}
