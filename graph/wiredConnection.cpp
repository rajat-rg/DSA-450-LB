#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<int> g[], int n, vector<int> &vis)
{
    vis[n] = 1;
    for (auto i : g[n])
    {
        if (!vis[i])
            dfs(g, i, vis);
    }
}

int connections(int n, vector<pair<int, int>> &edges)
{
    if (edges.size() < n - 1)
        return -1;
    int c = 0;

    vector<int> g[n];
    for (int i = 0; i < edges.size(); i++)
    {

        g[edges[i].first].push_back(edges[i].second);
        g[edges[i].second].push_back(edges[i].first);
        /* code */
    }
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            c++;
            dfs(g, i, vis);
        }
        /* code */
    }

    return c - 1;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<pair<int, int>> edges;
    for (int i = 0; i < 5; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back(make_pair(x, y));
        /* code */
    }
    cout<<"\n___-->___" << connections(n, edges);
    return 0;
}
