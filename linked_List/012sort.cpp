#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
    node(int a)
    {
        data = a;
        next = NULL;
        prev = NULL;
    }
} *start = NULL;

void createLL(int a)
{
    struct node *ptr = new node(a);
    if (start == NULL)
    {
        start = ptr;
        start->prev = NULL;
    }
    else
    {
        struct node *tmp = start;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = ptr;
        ptr->prev = tmp;
    }
}

void printLL()
{
    if (start == NULL)
    {
        cout << "khali!! kh...kha..khali kr denge,... me bta rha hu khali kr denge.";
    }
    struct node *ptr = start;
    while (ptr!= NULL)
    {
        cout << ptr->data<<"-> ";
        ptr = ptr->next;
    }cout<<"->NULL"<<endl;
}

void sort()
{
    struct node* zero = start;
    struct node* two = start;
    while(two->next )
    two = two->next;
    struct node* ptr = start;

    while(ptr!= NULL)
    {
        if(ptr->data == 0 and ptr != zero)
        {
            ptr->data = zero->data;
            zero->data=0;
            zero = zero->next;
        }
        else if(ptr->data == 2 and ptr != two)
        {
            ptr->data = two->data;
            two->data=2;
            two = two->prev;
        }
        cout<<ptr->data<<".";
        ptr = ptr->next;
    }
    cout<<endl;

}
void sort2()
{
    int n0=0;
    int n1=0;
    int n2=0;

    struct node* ptr = start;
    while(ptr)
    {
        if(ptr->data==0)
        n0++;
        
        if(ptr->data==1)
        n1++;
        
        if(ptr->data==2)
        n2++;
        ptr = ptr->next;
    }

    ptr = start;
    while(ptr)
    {
        if(n0)
        {
        ptr->data = 0;
        n0--;
        }
        else if(n1)
        {
        ptr->data =1;
        n1--;
        }
        else if(n2)
        {
        ptr->data = 2;
        n2--;
        }
        ptr = ptr->next;
    }
}



int main(int argc, char const *argv[])
{
    int a, ch;
    do
    {
        cout << "Enter number\n";
        cin >> a;
        createLL(a);
        cout << "Enter 1 to continue\n";
        cin >> ch;
    } while (ch);
    printLL();
    sort2();
    printLL();

    return 0;
}
