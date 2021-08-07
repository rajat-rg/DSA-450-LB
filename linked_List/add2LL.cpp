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

void add1(struct node *first, struct node *second)
{
    reverseLL_iteration(first);
    reverseLL_iteration(second);

    struct node *res1 = first;
    struct node *res2 = second;
    int sum = 0, carry = 0;

    while (res1->next != NULL or res2->next != NULL)
    {

        sum = (res1 ? res1->data : 0) + (res2 ? res2->data : 0) + carry;
        if (sum > 10)
        {
            sum = sum % 10;
            carry = 1;
        }

        res2->data = sum;
        if (res1)
            res1 = res1->next;
        if (res2)
            res2 = res2->next;
    }
    if (carry == 1)
    {
        struct node *ptr = new node(1);
        res2->next = ptr;
    }
    reverseLL_iteration(res1);
    reverseLL_iteration(res2);
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
    // reverseLL_iteration();
    add1(first, second);
    cout<<second->data;
    printLL(second);

    return 0;
}
