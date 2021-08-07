#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(int argc, char const *argv[])
{
    int v, e;
    int cn = 1;

    cin >> v >> e;
    vector<vector<int>> graph(v + 1);
    for (int i = 0; i < e; i++)
    {
        /* code */
        int o, p;
        cin >> o >> p;
        graph[o].push_back(p);
        graph[p].push_back(o);
    }

    unordered_set<int> vis;
    vector<int> res(v, -1);
    vector<bool> available(v, false);
    res[0] = 0;
    for (int i = 1; i < v; i++)
    {
        for (auto j : graph[i])
        {
            if (res[j] != -1)
                available[res[j]] = true;
        }

        int color;
        for ( color = 0; color < v; color++)
        {
            if (res[color] == -1)
            break;
        }
        res[i] = color;
        cn = max(cn, color + 1);

        for (auto j : graph[i])
        {
            if (res[j] != -1)
                available[res[j]] = false;
        }
    }
    cout<<"Bai itne color vaapre hai: "<<cn;
    return 0;
}
