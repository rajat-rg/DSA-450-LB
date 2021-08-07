#include<iostream>
#include<queue>
using namespace std;

    queue<int> queue1;
    queue<int> queue2;
void push(int a)
{
    queue1.push(a);
}

int pop()
{
    if(queue1.size()==0)return -1;
    if(queue1.size()==1)
    {
        int x = queue1.front();
        queue1.pop();
        return x;
    }
    while(queue1.size()>1)
    {
        queue2.push(queue1.front());
        queue1.pop();
        /* code */
    }
    int x =  queue1.front();
    queue1.pop();
    while(queue2.size())
    {
        queue1.push(queue2.front());
        queue2.pop();
    } 
    return x;


}
int main(int argc, char const *argv[])
{

    push(1);
    push(2);
    push(3);
    push(4);
    cout<<pop()<<" "<<pop()<<" ";
    cout<<pop()<<" "<<pop()<<" ";
    push(30);
    push(47);
    cout<<pop()<<" "<<pop()<<" ";
    return 0;
}
