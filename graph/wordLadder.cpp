#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;
int wordLadder(string start, string end, vector<string> dict)
{
    unordered_set<string> dic;
    for (int i = 0; i < dict.size(); i++)
    {
        dic.insert(dict[i]);
    }
    int len = 0;
    int qlen = 0;
    if (dic.find(end) == dic.end())
        return 0;

    queue<string> q;
    q.push(start);
    while (!q.empty())
    {
        len++;
        qlen = q.size();
        for (int i = 0; i < qlen; i++)
        {

            string s = q.front();
            q.pop();
            for (int j = 0; j < s.size(); j++)
            {
                char org = s[j];
                /* code */
                for (char a = 'a'; a <= 'z'; a++)
                {
                    s[j] = a;
                    if (s == end)
                        return len + 1;
                    if (dic.find(s) == dic.end())
                        continue;

                    q.push(s);
                    dic.erase(s);
                }
                s[j] = org;
            }
        }
    }
    /* code */

    return 0;
}
int main(int argc, char const *argv[])
{
    string start = "hit";
    string end = "cog";
    vector<string> dict = {"hot", "dog", "log", "lit", "dot", "cog"};

    int res = wordLadder(start, end, dict);
    cout << "\n___-->>___" << res;
    return 0;
}
