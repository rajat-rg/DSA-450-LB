#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int v, e;
    cin >> v >> e;
    vector<int> graph[v + 1];
    vector<int> indeg(v + 1, 0);
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    for (int i = 1; i < v; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        cout << x << "  ";
        q.pop();
        for (auto it : graph[x])
        {
            indeg[it]--;
            if (indeg[it] == 0)
                q.push(it);
        }
    }

    return 0;
}
