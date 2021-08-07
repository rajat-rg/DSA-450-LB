#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interLevel(queue<int> q, int size)
{
    stack<int> stack;
    int h = size/2;
    for (int i = 0; i < h; i++)
    {
        stack.push(q.front());
        q.pop();
    }
    while(stack.size())
    {
        q.push(stack.top());
        stack.pop();
    }
    
    for (int i = 0; i < h; i++)
    {
        q.push(q.front());
        q.pop();
    }
    
    for (int i = 0; i < h; i++)
    {
        stack.push(q.front());
        q.pop();
    }
    
    while(!stack.empty())
    {
        q.push(stack.top()); 
        stack.pop();
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < size; i++)
    {
        cout<<q.front()<<" ";
        q.pop();       /* code */
    }
    
    

}



int main()
{
    int n, a;
    cin>>n;
    queue<int> q;    
    for(int i=0;i<n;i++)
    {
        cin>>a;
        q.push(a);
    }

    interLevel(q,n);
    return 0;
}
