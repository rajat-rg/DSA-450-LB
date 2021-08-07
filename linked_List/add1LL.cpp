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

void add1()
{
    reverseLL_iteration();
    
    struct node* res = start;
    

    int carry = 0, sum;
    while( 1 )
    {
        if(res->next== NULL and carry==1)
        {
            res->data = 0;
            struct node* p = new node(1);
            res->next = p;
            break;


        }
        if(res->data <9)
        {
            res->data+=1;
            carry=0;
            break;
        }
        else
        {
            res->data = 0;
            carry = 1;
            res = res->next;
        }
    }


    reverseLL_iteration();
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
    // reverseLL_iteration();
    add1();
    printLL();

    return 0;
}
