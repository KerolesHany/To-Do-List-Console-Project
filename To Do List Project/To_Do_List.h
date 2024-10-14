

#ifndef TO_DO_LIST_H
#define TO_DO_LIST_H

#include <string>
using namespace std;

class to_do_list {
private:
    struct node {
        int id;
        string task;
        bool isDone;
        node* next;
    };

    node* head;
    int count;
public:
    to_do_list();

    //  add a task
    void Add_task(int id, string task);

    // delete a task by  id
    int Delete_task_by_id(int taskId);

    //  display tasks
    void display();

    // mark a task as done
    void markDone(int taskId);

    //  check if a task is done
    bool Check_task(int taskId);
    void count_tasks();
};

#endif 




