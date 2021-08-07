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

long multiply2(struct node *first, struct node *second)
{
    int n1 = 0;
    int n2 = 0;

    while (first || second)
    {
        if (first)
        {
            n1 = (n1 * 10) + first->data;
            first = first->next;
        }
        if (second)
        {
            n2 = (n2 * 10) + second->data;
            second = second->next;
        }
    }

    return n1 * n2;
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
    long ans = multiply2(first, second);
    cout<<ans;
    return 0;
}
