#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

unordered_map<string, int> dp;

int wordBreak(string a, vector<string> &b)
{
    int sz = a.length();
    if (sz == 0)
        return dp[a] = 1;
    
    if(dp[a]!=0)
        return dp[a];

    for (int i = 0; i <= sz; i++)
    {
        int f = 0;
        string ss = a.substr(0, i);
        for (int j = 0; j < b.size(); j++)
        {
            
            if (ss.compare(b[j]) == 0)
            {
                f = 1;
                break;
            }
        }
            if (f == 1 and wordBreak(a.substr(i, sz - i), b) == 1)
                return dp[a] = 1;
    }
    return dp[a] = -1;
}
int main()
{
    string a;
    vector<string> b = {"a", "b", "ab", "bc", "cd", "bcd", "e"};
    cin >> a;
    if (wordBreak(a, b) == 1)
        cout << "Hai ga";
    else
        cout << "Na hai";
    return 0;
}