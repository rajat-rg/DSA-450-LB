#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

void NGE(int a[], int n)
{
    stack<int> s;
    s.push(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.empty())
        {
            s.push(a[i]);
        }
        else
        {
            while (!s.empty() and s.top() < a[i])
            {
                cout << s.top() << " -> " << a[i] << endl;
                s.pop();
            }

            s.push(a[i]);
        }
    }
    while (!s.empty())
    {
        cout << s.top() << " -> " << -1 << endl;
        s.pop();
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        /* code */
    }
    // NGE(a,n);
    NGE(a, n);
    return 0;
}
