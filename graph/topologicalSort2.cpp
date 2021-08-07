#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int v,e;
    cin>>v>>e;

    vector<int> graph[v+1];
    vector<int> job(v+1, 1);
    vector<int> indeg(v+1, 0);

    for (int i = 0; i < v; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        indeg[v] = 1;
    }
    queue<int> js;
    for (int i = 0; i <= v; i++)
    {
        if(indeg[i] == 0)
        {
            js.push(i);
            job[i]=1;
        }
    }
    
    while(!js.empty())
    {
        int x = js.front();
        js.pop();
        for(auto i: graph[x])
        {
            indeg[i]--;
            if(indeg[i]==0)
            {
                job[i] = job[x]+1;
                js.push(i);

            }
        }
    }
    cout<<endl;
    for (int i = 1; i < job.size(); i++)
    {
        cout<<job[i]<<" ";
        /* code */
    }
    

    return 0;
}
