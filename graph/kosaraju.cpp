// stronglu connected component of graph
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<int> &order, unordered_set<int> &vis, int sr)
{
        vis.insert(sr);
        for (auto i : graph[sr])

            if (vis.find(i) == vis.end())
                dfs(graph, order, vis, i);

}

void dfsrev(vector<vector<int>> &graph, vector<int> &order, unordered_set<int> &vis, int sr)
{
        vis.insert(sr);
        for (auto i : graph[sr])
            if (vis.find(i) == vis.end())
                dfsrev(graph, order, vis, i);
}
int main(int argc, char const *argv[])
{
    int v, e;
    cout << "Enter vertices and edges: ";
    cin >> v >> e;
    vector<vector<int>> graph(v + 1);
    vector<vector<int>> revgraph(v + 1);
    vector<int> order;
    unordered_set<int> vis;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        /* code */
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }

    dfs(graph, order, vis, 1); // apne graph ke lie dfs
    // or ab chalao reverse ke lie'
    int str_com = 0;
    vis.clear();
    for (int i = order.size() - 1; i >= 0; i--)
    {
        if (vis.find(order[i]) == vis.end())
        {
            cout << order[i] << " ";
            vis.insert(order[i]);
            str_com++;
            dfsrev(revgraph, order, vis, order[i]);
        }
        /* code */
    }

    cout << "Itne hai strongly connected components apne graph me: " << str_com;

    return 0;
}
