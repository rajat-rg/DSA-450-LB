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

void printLL(struct node *start)
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

struct node *oddEven()
{
    struct node *ptr = start;

    struct node *r = NULL;
    struct node *r1 = r;

    while (ptr )
    {
        
        if (ptr->data % 2 != 0)
        {
                struct node* tmp = new node(ptr->data);
            if (r == NULL)
            {
                r = tmp;
                r1 = tmp;
        

            }
            else
            {
                r1->next = tmp;
                r1 = r1->next;
        
            }
        }
        ptr = ptr->next;
    }
    ptr = start;
    
    while (ptr)
    {
        if (ptr->data % 2 == 0)
        {
                struct node* tmp = new node(ptr->data);
            r1->next = tmp;
            r1 = r1->next;
        
        }
        ptr = ptr->next;
    }

        
    return r;
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
    printLL(start);
    struct node *r = oddEven();

    printLL(r);

    return 0;
}
