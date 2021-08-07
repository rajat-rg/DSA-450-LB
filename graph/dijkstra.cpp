#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(int argc, char const *argv[])
{
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>> graph(v+1);
    for (int i = 0; i < e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    vector<int> dist(v+1, INT_MAX);
    int source;
    cin>>source;
    dist[source]=0;
    set<pair<int,int>> s;
    s.insert({0, source});
    while(!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for(auto it: graph[x.second])
        {
            if(dist[it.first] > dist[x.second] + it.second)
            {
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second]+ it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }
    
    for (int i = 1; i < v+1; i++)
    {
        if(dist[i] != INT_MAX)
        cout<<dist[i]<<" ";
        else
        cout<<-1<<" ";
        /* code */
    }
    
 
 
 
 
 
 
    return 0;
}
