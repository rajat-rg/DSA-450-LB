#include<iostream>
#include<queue>
using namespace std;

void slidingWindow(int a[], int k, int n)
{
    deque<int> dq;
    int i=0;
    for(;i<k;i++)
    {
        while(!dq.empty() and a[dq.front()] <a[i])
        {
            dq.pop_front();
        }
        dq.push_back(i);
    }
        cout<<a[dq.front()]<<" ";
    for(;i<n;i++)
    {
        
        while(!dq.empty() and dq.front() <= i-k)
        {
            dq.pop_front();
        }
        while(!dq.empty() and a[dq.front()] <a[i])
        {
            dq.pop_front();
        }
        dq.push_back(i);
        cout<<a[dq.front()]<<" ";

    }

}
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        /* code */
    }
    
    slidingWindow(a,k, n);
    }