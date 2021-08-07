#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool has(vector<int> v, int a)
{
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] == a)return 1;
        /* code */
    }
    return 0;
    
}
vector<int> visited;
vector<int> dfs;
void DFS(vector<int> graph[], int s)
{
    visited.push_back(s);
    dfs.push_back(s);
    for(auto x : graph[s])
    {
        if(!has(visited, x))
        DFS(graph,x);
    }

}
void BFS(vector<int> graph[], int start)
{
    queue<int> bfs;
    visited.push_back(start);
    bfs.push(start);
    while(!bfs.empty())
    {
        int i = bfs.front();
        bfs.pop();
        cout<<i<<" -> ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            if(!has(visited,graph[i][j]))
            {
        
                bfs.push(graph[i][j]);
                visited.push_back(graph[i][j]);

            }
            
            /* code */
        }
        
        /* code */
    }
    

}
int main(int argc, char const *argv[])
{
    /* code */
    int v,e;
    cout<<"Enter number of vertices and edges\n";
    cin>>v>>e;
    int x,y;
    vector<int> graph[v+1];
    // lekin ek masla hai,  hm apni ikcha anusar kuch number na ger sake yame ku aayenge aise hi ek do teen char krke hi
    for (int i = 0; i < e; i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        /* code */
    }
    for (int i = 1; i < v; i++)
    {
        cout<<i<<" --> ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout<<graph[i][j]<<" ";
            /* code */
        }
        cout<<endl;
        /* code */
    }
    BFS(graph,1);
    visited.clear();
    cout<<endl;
    DFS(graph,1);
    for (auto i : dfs)
    {
        /* code */
    cout<<i<<" -> ";
    }
    
    return 0;
}
