#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int stackPermutation(int ip[], int op[], int n)
{
    queue<int> input;
    queue<int> output;
    stack<int> temp;
    for(int i = 0; i < n;i++)
    {
        input.push(ip[i]);
        output.push(op[i]);
    }

    while(!input.empty())
    {
        if(input.front() == output.front())
        {
            input.pop();
            output.pop();
            while(!temp.empty())
            {
                if(temp.top() == output.front())
                {
                    temp.pop();
                    output.pop();
                }else break;

            }
        }
        else
        {
        temp.push(input.front());
        input.pop();
        }

    }
    return(input.empty() and temp.empty());
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<"___________\n";
    int in[n], op[n];
    for (int i = 0; i < n; i++)
    {
        cin>>in[i];
        /* code */
    }
    cout<<"___________\n";
    for (int i = 0; i < n; i++)
    {
        cin>>op[i];
        /* code */
    }
    cout<<"___________\n";
    
    if(stackPermutation(in, op,n))
    cout<<"Stack perutation hai ga\n";
    else
    cout<<"Na hai koi permutation fermutatation\n";
    return 0;
}
