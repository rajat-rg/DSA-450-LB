#include <iostream>
#include <stack>
#include <string>
using namespace std;

void redunParen(string s)
{
    stack<char> st;
    int c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ')')
        {
            st.push(s[i]);
        }
        else
        {

            cout << st.top() << endl;
            if (st.top() == '(' )
            {
                cout << "YES";
                st.pop();
                return;
            }
            else
            {
                while (!st.empty())
                {
                    if (st.top() == '(')
                    {
                        cout << st.top()<<endl;
                        st.pop();
                        break;
                    }

                    if (st.top() != '+' or st.top() != '-' or st.top() != '*' or st.top() != '/')
                        c++;
                    st.pop();
                }
                if (c == 0)
                {
                    cout << "YES";
                    st.pop();
                    return;
                }
            }
        }

        /* code */
    }
    cout << "NO";
}
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    redunParen(s);
    return 0;
}
