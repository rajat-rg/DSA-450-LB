#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int a)
    {
        data = a;
        next = NULL;
        ;
    }
} *start = NULL;

void create_ll(int a)
{
    struct node *ptr = new node(a);
    if (start == NULL)
        start = ptr;
    else
    {
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void printLL()
{
    if (start == NULL)
        cout << "Empty\n";
    else
    {
        struct node *tmp = start;

        while (tmp != NULL)
        {
            cout << tmp->data << "-> ";
            tmp = tmp->next;
        }
        cout << endl;
    }
}

void remove_duplicate()
{
    struct node *tmp = start;
    while (tmp->next != NULL)
    {
        if (tmp->next->data == tmp->data)
        {
            struct node *del = tmp->next;
            tmp->next = tmp->next->next;
            free(del);
            // cout<<tmp->data;
        }
        tmp = tmp->next;
    }
}
void remove_unsorted()
{
    struct node *tmp = start;
    while (tmp->next != NULL)
    {
        struct node *ptr = tmp;
        while (ptr->next != NULL)
        {
            if (ptr->next->data == tmp->data)
            {
                struct node *del = ptr->next;
                ptr->next = ptr->next->next;
                free(del);
            }
            ptr = ptr->next;
        }
        tmp = tmp->next;
    }
}
int main(int argc, char const *argv[])
{
    int a, ch;
    do
    {
        cout << "Enter value\n";
        cin >> a;
        create_ll(a);
        cout << "Enter 1 to continue: \n";
        cin >> ch;
    } while (ch);
    printLL();
    remove_unsorted();
    printLL();
    return 0;
}
