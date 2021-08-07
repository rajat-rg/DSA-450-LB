#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter array size:"; 
    cin>>n;
    vector<int> arr(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    cout<<"Enter array elements";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
        pq.push(x);
        /* code */
    }
    arr.clear();
    while(!pq.empty())
    {
        arr.push_back(pq.top());
        pq.pop();

        /* code */
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
        /* code */
    }
        
    return 0;
}
