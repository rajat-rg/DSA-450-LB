#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    
    {
        cout<<12;
    }
    int n;
    cin>>n;
    int a[n];
    int left[n];
    int right[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        /* code */
    }
    
    // find the left limit of each bar
    stack<int> st;
    for (int  i = 0; i < n; i++)
    {
        if(st.empty())
        {
            st.push(0);
            left[i]= 0;
        }
        if(a[i] >a[i-1])
        {
            left[i] = i-1;
            st.push(i);

        }
        else
        {
            left[i] = st.top()+1;
            st.pop();
        }
        /* code */
    }
        
    return 0;
}
