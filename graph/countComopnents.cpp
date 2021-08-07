#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;


void dfs(int u, vector<vector<int>> &graph, unordered_set<int> &vis)
{
    for(auto i: graph[u])
    {
        if(vis.find(i)==vis.end())
        {
            vis.insert(i);
            cout<<i<<" ";
            dfs(i, graph, vis);
        }
    }
}





int main(int argc, char const *argv[])
{
    int v,e,compo=0;
    cout<<"nter vertices n edges\n";
    cin>>v>>e;
    vector<vector<int>> graph(v+1);
    vector<int> vertex;
    unordered_set<int> vis;
    cout<<"Create graph\n";
    for (int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        if(vis.find(u) == vis.end())
        {
        vertex.push_back(u);
        vis.insert(u);
        }
    }
    vis.clear();
    for (int i=0;i<vertex.size();i++)
    {
        
        if(vis.find(vertex[i]) == vis.end())
        {
            vis.insert(vertex[i]);
            cout<<vertex[i]<<" ";
            dfs(vertex[i],graph, vis);
            compo++;
        }
        /* code */
    }
    
    cout<<"\nComponents in graph are: "<<compo;


    return 0;
}
