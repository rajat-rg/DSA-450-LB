#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int>&st, int a)
{
    if(st.empty() or a>st.top())
    {
        st.push(a);
        return ;
    }

    int tmp = st.top();
    st.pop();
    insertSorted(st, a);
    st.push(tmp);
}

void sortkaro(stack<int> &st)
{
    if(st.empty())return ;

    int a = st.top();
    st.pop();
    sortkaro(st);
    insertSorted(st,a);




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

    sortkaro(st);
    cout<<"___________\n";
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}
