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
void reverseLL_recursion(struct node *ptr, struct node *nxt)
{
    if (nxt->next == NULL)
    {

        vod = nxt;
        nxt->next = ptr;
        return;
    }
    if (nxt->next != NULL)
    {
        reverseLL_recursion(nxt, nxt->next);
    }
    nxt->next = ptr;
    if (ptr == start)
    {
        start->next = NULL;
        start = vod;
    }
}

void reverseLL_iteration()
{
    struct node *prev = NULL;
    struct node *curr = start;
    struct node *nxt = NULL;

    while (curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    start = prev;
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
    reverseLL_recursion(start, start->next);
    printLL();
    reverseLL_iteration();
    printLL();

    return 0;
}
