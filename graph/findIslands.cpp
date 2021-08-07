#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &grid, int n, int m, vector<vector<int>> &vis)
{
    int a[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int b[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int j = 0; j < 8; j++)
    {
        if ((grid[n + a[j]][m + b[j]] == 1 and !vis[n + a[j]][m + b[j]]) and (n + a[j] >= 0 and n + b[j] < n) and (m + a[j] >= 0 and m + b[j] < n)) 
            vis[n + a[j]][m + b[j]] = 1;
        cout << "! ";
    }
}

int findIsland(vector<vector<int>> &grid, int n, int m)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " " << vis[i][j] << endl;
            if (grid[i][j] == 1 and !vis[i][j])
            {
                bfs(grid, i, j, vis);
                l++;
            }
            cout << ". ";
            /* code */
        }

        /* code */
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }

    return l;
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            grid[i][j] = x;
        }
    }

    int l = findIsland(grid, n, m);
    cout << "\n__-->>__" << l;
    return 0;
}
