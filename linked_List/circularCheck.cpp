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
} *start = NULL, *last = NULL;

void create_ll(int a)
{
    struct node *ptr = new node(a);
    if (start == NULL)
    {
        start = ptr;
        last = ptr;
    }
    else
    {
        last->next = ptr;
        last = ptr;
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


void deleteKrdo()
{

    int n;
    cout<<"\nEnter a number to delete\n";
    cin>>n;
    struct node* ptr = start;
    while(ptr->next != start){
        if (ptr->next->data == n)
        {
            struct node* tmp = ptr->next;
            ptr->next = ptr->next->next;
            free(tmp);
            cout<<"\ndeleted";
            break;

        }
        ptr = ptr->next;
    }
    cout<<"Number hai hi na ye vala\n";
}








void isCircular()
{
    struct node *ptr = start;
    struct node *s = start;
    while (ptr != NULL)
    {
        if (ptr->next == s)
        {
            cout << "Circular linked list";
            deleteKrdo();
            return;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    cout << "This list is not circular";
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
    last->next = start;
    isCircular();
    return 0;
}
