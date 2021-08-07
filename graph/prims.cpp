#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;
int mini(vector<int> vis,unordered_set<int> mst)
{
    int mx = vis[0], pos = 0;
    for (int i = 1; i < vis.size(); i++)
    {
        cout<<vis[i]<<" ";
        if (vis[i] < mx and mst.find(vis[i]) == mst.end())
        {
            pos = i;
        }
    }
cout<<endl;
    return pos;
}
int prims(vector<vector<pair<int, int>>> graph, int v, int source)
{
    cout<<"<>\n";
    unordered_set<int> mst;
    vector<int> vis(v + 1);
    for (int i = 0; i < vis.size(); i++)
    {
        if (i == source)
            vis[i] = 0;
        else
            vis[i] = INT_MAX;
        // vis[i][1] = INT_MAX;
    }

    mst.insert(source);
    int x = source;
    while (mst.size() != graph.size())
    {
        for (int j = 0; j < graph[x].size(); j++)
        {
            if (vis[graph[x][j].first] > graph[x][j].second and mst.find(graph[x][j].first) == mst.end())
                vis[graph[x][j].first] = graph[x][j].second;
        }
        x = mini(vis, mst);
        mst.insert(x);
        // cout<<mst<<" ";
    }

    int span=0;
    for(int i=0; i< vis.size();i++)
    span+= vis[i];
    return span;
}

int main(int argc, char const *argv[])
{
    int v, e;
    cin >> v >> e;
    vector<vector<pair<int, int>>> graph(v + 1);
    for (int i = 0; i < v + 1; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    cout<<"!\n";
    int wt = prims(graph, v, 0);
    cout<<"Prim bhai ke hisab se mminimum cost jo hai vo hai :"<<wt;
    return 0;
}
