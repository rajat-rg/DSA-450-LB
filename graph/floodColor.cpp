#include <iostream>
#include <vector>
using namespace std;

void dfs(int arr[100][100], int sr, int sc, int n, vector<vector<int>> &vis, int newColor, int oldColor)
{
    if (sr < 0 or sr >= n or sc < 0 or sc >= n)
        return;

    if (vis[sr][sc] or arr[sr][sc] != oldColor)
        return;
    // cout<<vis[sr][sc];
    vis[sr][sc] = 1;
    arr[sr][sc] = newColor;
    dfs(arr, sr - 1, sc, n, vis, newColor, oldColor);
    dfs(arr, sr + 1, sc, n, vis, newColor, oldColor);
    dfs(arr, sr, sc - 1, n, vis, newColor, oldColor);
    dfs(arr, sr, sc + 1, n, vis, newColor, oldColor);
}
void floodColor(int arr[100][100], int n, int sr, int sc, int newColor)
{
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int oldColor = arr[sr][sc];

    dfs(arr, sr, sc, n, vis, newColor, oldColor);
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the dimension of array: ";
    cin >> n;
    int arr[100][100];
    cout << "Enter color in pixels: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            /* code */
        }
        /* code */
    }
    int sr, sc;
    cout << "Enter source: \n";
    cin >> sr >> sc;
    int newColor;
    cin >> newColor;
    floodColor(arr, n, sr, sc, newColor);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
            /* code */
        }
        cout << endl;
    }
    return 0;
}
