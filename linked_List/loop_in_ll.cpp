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
        last = start;
    }
    else
    {
        struct node *temp = start;

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

int detectLoop()
{

    if (start == NULL)
        return 0;
    struct node *slow = start;
    struct node *fast = start;

    while (slow != NULL or fast != NULL or  fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return slow->data;
            break;
        }
    }
    return -1;
}
void removeloop(int a)
{
    struct node* slow = start;
    struct node* fast = start;
    while(fast)
    {
        if(fast->data == a)
        {
            break;
        }
        fast = fast->next;
    }

    while(slow and fast)
    {
        if(slow->next == fast->next){
            fast->next = NULL;
        }
        slow = slow->next;
        fast = fast->next;
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
    last->next = start->next;
    int s = detectLoop();
    if(s>0)
    cout<<"Loop detected: "<<endl;
    else
    cout<<"Loop not detected";
    removeloop(s);
    printLL();
    return 0;
}
