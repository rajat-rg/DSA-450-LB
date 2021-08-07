#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({u, v, w});
        /* code */
    }

    vector<vector<int>> dist(v, vector<int>(v, 1e9));
    for (int i = 0; i < dist.size(); i++)
    {
        dist[i][i] = 0;
    }

    for (auto it : graph)
    {
        int i = it[0];
        int j = it[1];
        int w = it[2];
        dist[i][j] = w;
    }

    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

                /* code */
            }
            /* code */
        }

        /* code */
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << dist[i][j] << " ";
        }
        /* code */
        cout << endl;
    }

    return 0;
}
