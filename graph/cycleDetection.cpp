#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> visited(50, 0);
vector<int> active(50, 0);
bool detectCycle(vector<int> graph[], int s)
{
    visited[s] = 1;
    active[s] = 1;
    for (auto x : graph[s])
    {
        if (visited[x] == 0)
        {
            bool c = detectCycle(graph, x);
            if (c == true)
                return true;
        }
        else if (active[x] == 1)
            return true;
    }
    
    active[s] = 0;
    return false;
}

int main(int argc, char const *argv[])
{
    /* code */
    int v, e;
    cout << "Enter number of vertices and edges\n";
    cin >> v >> e;
    int x, y;
    vector<int> graph[v + 1];
    // lekin ek masla hai,  hm apni ikcha anusar kuch number na ger sake yame ku aayenge aise hi ek do teen char krke hi
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        // graph[y].push_back(x);
        /* code */
    }
    for (int i = 1; i < v; i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
            /* code */
        }
        cout << endl;
        /* code */
    }

    cout << endl;
    if (detectCycle(graph, 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
