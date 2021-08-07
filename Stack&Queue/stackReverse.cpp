#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int a)
{
    if (st.empty())
    {
        st.push(a);
        return;
    }
    // cout << a << " .";
    int top = st.top();
    st.pop();
    insertAtBottom(st, a);
    st.push(top);
}

void reverse(stack<int> &st)
{
    if (st.empty())
        return;

    int a = st.top();
    st.pop();

    reverse(st);
    insertAtBottom(st, a);

}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        st.push(h);
        /* code */
    }

    reverse(st);
    cout<<"___________\n";
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}
