#include <iostream>
#include<string>
#include "to_do_list.h"

using namespace std;


int main()
{
    to_do_list todoList;
    int choice, id;
    string task;


    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. Delete Task by Id\n";
        cout << "3. Display Tasks\n";
        cout << "4. Mark Task as Done\n";
        cout << "5. Check if Task is Done\n";
        cout << "6. count tasks\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter task ID: ";
            cin >> id;
            cout << "Enter task description: ";
            cin.ignore(); 
            getline(cin,task);

            //    cin >> task; 
            todoList.Add_task(id, task);
            break;
        case 2:
            cout << "Enter task Id to delete: ";
            getline(cin, task);
             cin >> id; 
            todoList.Delete_task_by_id(id);
            break;
        case 3:
            todoList.display();
            break;
        case 4:
            cout << "Enter task ID to mark as done: ";
            cin >> id;
            todoList.markDone(id);
            break;
        case 5:
            cout << "Enter task ID to check status: ";
            cin >> id;
            if (todoList.Check_task(id)) {
                cout << "Task is done.\n";
            }
            else {
                cout << "Task is not done.\n";
            }
            break;

        case 6:
            todoList.count_tasks();
            break;

        case 7:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;









    }
        } while (choice >= 1 && choice <= 7);
}