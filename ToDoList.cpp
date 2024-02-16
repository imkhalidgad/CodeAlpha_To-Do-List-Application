#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back({ description, false });
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
        }
        else {
            cout << "Invalid task index." << endl;
        }
    }

    void displayTasks() {
        cout << "Current Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[X] ";
            }
            else {
                cout << "[ ] ";
            }
            cout << tasks[i].description << endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;

    do {
        cout << "_______________________________" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task Completed" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "_______________________________" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "_______________________________" << endl;

        switch (choice) {
        case 1: {
            string description;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, description);
            todoList.addTask(description);
            break;
        }
        case 2: {
            int index;
            cout << "Enter task index to mark as completed: ";
            cin >> index;
            todoList.markTaskCompleted(index - 1);
            break;
        }
        case 3: {
            todoList.displayTasks();
            break;
        }
        case 4: {
            cout << "Exiting..." << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
