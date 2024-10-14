#include <iostream>
#include <string>
#include "to_do_list.h"
using namespace std;


    to_do_list::  to_do_list() {
        head = nullptr;
        count = 0; 
    }

    // add task
    void to_do_list::Add_task(int id, string task) {
        node* new_node = new node;
        new_node->id = id;
        new_node->task = task;
        new_node->isDone = false;
        new_node->next = head;   
        head = new_node; // new node 
        cout << "Task added successfully." << endl;
        count++;

    }


    //  delete a task by  id
    int  to_do_list::Delete_task_by_id(int taskId) {
        if (head == nullptr) {
            cout << "No tasks to remove." << endl;
            return -1; 
        }

        node* current = head;
        node* previous = nullptr;

        while (current != nullptr && current->id != taskId)

        {
            // current != null -> موصلش لنهاية الليست
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            // current = null -> وصل للنهاية وملقيش اللي عاوزه

            cout << "Task not found." << endl;
            return -1; 
        }

        // Remove the task
        // The task to delete is the head task
        if (previous == nullptr) {
            head = head->next;// points to next node 
        }
        else
        {
            previous->next = current->next;
        }

        cout << "Task removed successfully. ID: " << current->id << ", Task: " << current->task << endl;
        count--;

        delete current;
        return 0; 
    }

    // Function to display tasks
    void  to_do_list:: display() {
        if (head == nullptr) {
            cout << "No Tasks" << endl;
            return;
        }

        node* current = head;
        while (current != nullptr) {
            cout << "ID: " << current->id << ", Task: " << current->task << ", Status: " << (current->isDone ? "Done" : "Not Done") << endl;
            current = current->next;
        }
    }

    // mark a task as done
    void  to_do_list:: markDone(int taskId) {
        node* current = head;
        while (current != nullptr) {
            if (current->id == taskId) {
                current->isDone = true;
                cout << "Task marked as done. ID: " << current->id << ", Task: " << current->task << endl;
                return;
            }
            current = current->next;
        }
        cout << "Task ID not found." << endl;
    }

    // check if a task is done
    bool  to_do_list:: Check_task(int taskId) {
        node* current = head;
        while (current != nullptr) {
            if (current->id == taskId) {
                return current->isDone;
            }
            current = current->next;
        }
        cout << "Task ID not found." << endl;
        return false;
    }

    void  to_do_list:: count_tasks()
    {
        cout << "Number of Tasks : " << count << endl;
    }

    


