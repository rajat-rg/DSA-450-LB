#include<iostream>
#include<Stdio.h>
using namespace std;

struct node{
    int data;
    struct node* next;
     node(int a)
    {
        data = a;
        next = NULL;
    }
}*start = NULL;


struct node* createLL()
{
    int a,ch;
    cout<<"Enter number\n";
    cin>>a;
    cout<<"Enter 1 to continue\n";
    cin>>ch;
    struct node* ptr = new node(a);
    struct node* ptr2 =  NULL;
    if(ch>0)
    ptr2 = createLL();
    
    ptr->next = ptr2;
    return ptr;
}

void printLL(struct node* start)
{
    if(start==NULL)
    return ;

    struct node* ptr = start;

    while(ptr!= NULL)
    {
        cout<<ptr->data<<"-> ";
        ptr = ptr->next;
    }
}

struct node* findMiddle(struct node** start,struct node** first,struct node** second)
{
    if(*start==NULL or *start->next==NULL)return *start;

    struct node* slow = *start;
    struct node* fast = *start;

    while(fast!=NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;

}

void mergeSort(struct node** start)
{
    struct node* first;
    struct node* second;
    struct node* mid = findMiddle(start,&first,&second);
    mergeSort(&first);
    mergeSort(&second);
    
}

int main(int argc, char const *argv[])
{
    start = createLL();   
    printLL(start);
    // mergeSort(start);
    return 0;
}
