#include<iostream>
#include<vector>
using namespace std;

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
    
    return 0;
}
