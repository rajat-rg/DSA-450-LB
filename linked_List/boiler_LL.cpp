#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node* next;
    node(int a)
    {
        data =a;
        next = NULL;
    }
}*start=NULL;

void create_ll(int a)
{
    struct node* ptr = new node(a);
    if(start == NULL)
    start=ptr;
    else
    {
        struct node* temp = start;
        while(temp->next != NULL)
        {
            temp  = temp->next;
        }
        temp->next = ptr;
    }
}

void printLL()
{
    if(start == NULL)
    cout<<"Empty\n";
    else
    {
        struct node* tmp = start;

        while(tmp!= NULL)
        {
            cout<<tmp->data<<"-> ";
            tmp = tmp->next;
        }
        cout<<endl;

    }
}

int main(int argc, char const *argv[])
{
    int a,ch;
    do
    {
        cout<<"Enter value\n";
        cin>>a;
        create_ll(a);
        cout<<"Enter 1 to continue: \n";
        cin>>ch;
    }while(ch);
    printLL();
    return 0;
}
