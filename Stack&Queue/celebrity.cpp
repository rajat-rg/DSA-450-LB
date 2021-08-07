#include <iostream>
#include <stack>

using namespace std;

int knows(int a[10][10], int x, int y)
{
    return a[x][y];
}
int celebrity(int a[10][10], int n)
{

    stack<int> stack;
    for (int i = 0; i < n; i++)
    {
        stack.push(i);
        /* code */
    }

    while (stack.size()>1)
    {
        int A = stack.top();
        stack.pop();
        int B = stack.top();
        stack.pop();

        if (knows(a, A, B))
            stack.push(B);
        else
            stack.push(A);
    }
    if(stack.empty())return -1;

    int C = stack.top();
    stack.pop();
    for (int i = 0; i < n; i++)
    {
        if (i!=C and (knows(a, C, i) or !knows(a, i, C)))
            return -1;
    }
    return C;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        /* code */
    }
    cout <<"-->>" <<celebrity(a, n);
    return 0;
}
