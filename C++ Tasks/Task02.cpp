#include <iostream>
#include <string>

using namespace std;

int main() {
    string tasks[10]; 
    int taskCount = 0;
    int choice;

    cout << "=====================================" << endl;
    cout << "      TASK MANAGER APPLICATION       " << endl;
    cout << "=====================================" << endl;

    do {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Add a New Task" << endl;
        cout << "2. View Current Tasks" << endl;
        cout << "3. Remove Last Task" << endl;
        cout << "4. Exit Program" << endl;
        cout << "Please enter your choice (1-4): ";
        cin >> choice;

        // Clear the input buffer to prevent skipping getline
        cin.ignore(1000, '\n'); 

        if (choice == 1) {
            if (taskCount < 10) {
                cout << "Enter the task description: ";
                getline(cin, tasks[taskCount]);
                taskCount++;
                cout << "SUCCESS: Task added to the list." << endl;
            } else {
                cout << "ERROR: Your task list is full (Limit: 10)." << endl;
            }
        } 
        else if (choice == 2) {
            cout << "\n--- YOUR TO-DO LIST ---" << endl;
            if (taskCount == 0) {
                cout << "[ The list is currently empty ]" << endl;
            } else {
                for (int i = 0; i < taskCount; i++) {
                    cout << i + 1 << ". " << tasks[i] << endl;
                }
            }
        }
        else if (choice == 3) {
            if (taskCount > 0) {
                taskCount--; 
                cout << "SUCCESS: The last task has been removed." << endl;
            } else {
                cout << "ERROR: Nothing to remove. The list is empty." << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting... Thank you for using Task Manager!" << endl;
        }
        else {
            cout << "INVALID CHOICE: Please select a valid option from the menu." << endl;
        }

    } while (choice != 4);

    return 0;
}