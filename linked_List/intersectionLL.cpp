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
} *first = NULL, *second = NULL;

struct node *create_ll(struct node *start, int a)
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
    return start;
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

void reverseLL_iteration(struct node *start)
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

void intersection(struct node *first, struct node *second)
{
    struct node *ptr1 = first;
    struct node *ptr2 = second;

    while (ptr1 or ptr2)
    {
        if (ptr1->data == ptr2->data)
            cout << ptr1->data << endl;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
}
int length(struct node *start)
{
    struct node *end = start;
    int count = 0;
    while (end != NULL)
    {
        count++;
        end = end->next;
    }
    return count;
}
int intersectionDP(struct node *first, struct node *second)
{
    int l1 = length(first);
    int l2 = length(second);
    struct node *f = first;
    struct node *s = second;
    if (l1 > l2)
    {
        int count = 0;
        while (count < l1 - l2)
        {
            f = f->next;
            count++;
        }
    }
    else
    {
        int count = 0;
        while (count < l2 - l1)
        {
            s = s->next;
            count++;
        }
    }

    while (f or s)
    {
        if (f->data == s->data)
        {
            cout << f->data;
            return f->data;
        }
        else
            f = f->next;
        s = s->next;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int a, ch;
    cout << "Enter first linked list\n";
    do
    {
        cout << "Enter value\n";
        cin >> a;
        first = create_ll(first, a);
        cout << "Enter 1 to continue: \n";
        cin >> ch;
    } while (ch);

    cout << "Enter second linked list\n";
    do
    {
        cout << "Enter value\n";
        cin >> a;
        second = create_ll(second, a);
        cout << "Enter 1 to continue: \n";
        cin >> ch;
    } while (ch);
    printLL(first);
    printLL(second);

    intersectionDP(first, second);

    return 0;
}
