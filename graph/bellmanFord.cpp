#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int v,e;
    cout<<"Enter number of vertices and edges\n";
    cin>>v>>e;
    vector<vector<int>> edges;
    cout<<"enter edges\n";
    for (int i = 0; i < e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    vector<int> dist(v+1,1e9);
    int source;
    cout<<"Enter source: \n";
    cin>>source;
    dist[source]=0;
    for (int i = 0; i < v-1; i++)
    {
        for (auto x: edges)
        {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            dist[v] = min(dist[v], dist[u]+w);
            
         
        }
    }
    
    for (int i = 1; i < dist.size(); i++)
    {
        cout<<dist[i]<<" ";
        /* code */
    }
    
    return 0;
}
