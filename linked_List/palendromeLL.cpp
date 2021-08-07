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
} *start = NULL, *vod = NULL;

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

struct node *reverseLL_iteration(struct node *first)
{
    struct node *prev = NULL;
    struct node *curr = first;
    struct node *nxt = NULL;

    while (curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    first = prev;
    return first;
}

void palendrome(struct node *first)
{
    struct node *ptr1 = first;
    struct node *second = reverseLL_iteration(first);
    struct node *ptr2 = second;
    while (ptr1 != NULL)
    {
        if (ptr1->data != ptr2->data)
        {
            cout << "Not palendrome";
            return;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    cout << "Palendrome hai ye to";
    return;
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
    // reverseLL_recursion(start, start->next);
    palendrome(start);

    return 0;
}
