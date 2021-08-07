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
void reverse()
{
    struct node* tmp;
    struct node* ptr = start;
    
    while(ptr->next!=NULL)
    {
        tmp = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = tmp;
        ptr = ptr->prev;
        // cout<<ptr->data;

    }
    
    start = tmp->prev;

}
int findTriplet(int a)
{
    struct node* l = start;
    struct node* r = start;
    while(r->next)
    r = r->next;

        int count=0;
    for(;l->next != NULL; l=l->next)
    {
        count+= findPair(al->data);
    }
    return count;





}
int findPair(struct node* first,struct node* last,int a)
{
    struct node* l = first;
    struct node* r = last;
    int c=0;
    while(first != NULL && last != NULL && first->next!= NULL && last->next != first)
    {
        // cout<<r->data;
        if(l->data+r->data == a)
        {
            cout<<l->data<<"+"<<r->data<<endl;
            l = l->next;
            r = r->prev;

        }
        if(l->data+r->data < a)
        l= l->next;
        if(l->data+r->data > a)
        r = r->prev;
    }
    return c;
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
    
    int c =findPair(7);

    return 0;
}