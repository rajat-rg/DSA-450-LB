#include <iostream>
#include <queue>

using namespace std;

int ghoda(int x1, int x2, int y1, int y2, int n)
{
    queue<pair<int, int>> q;
    int moves[100][100];
    if(x1==x2 and y1==y2)return 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            moves[i][j] = 0;
            /* code */
        }
        /* code */
    }

    q.push(make_pair(x1 - 1, y1 - 1));
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (i - 2 > 0 and i - 2 < n and j - 1 > 0 and j - 1 < n)
        {
            q.push(make_pair(i - 2, j - 2));
            moves[i - 2][j - 1] += moves[i][j] + 1;
        }

        if (i + 2 > 0 and i + 2 < n and j + 1 > 0 and j + 1 < n)
        {
            q.push(make_pair(i + 2, j + 1));
            moves[i + 2][j + 1] += moves[i][j] + 1;
        }

        if (i - 1 > 0 and i - 1 < n and j + 2 > 0 and j + 2 < n)
        {
            q.push(make_pair(i - 1, j + 2));
            moves[i - 1][j + 2] += moves[i][j] + 1;
        }

        if (i + 1 > 0 and i + 1 < n and j - 2 > 0 and j - 2 < n)
        {
            q.push(make_pair(i + 1, j - 2));
            moves[i + 1][j - 2] += moves[i][j] + 1;
        }

        if (i - 2 > 0 and i - 2 < n and j + 1 > 0 and j + 1 < n)
        {
            q.push(make_pair(i - 2, j + 1));
            moves[i - 2][j + 1] += moves[i][j] + 1;
        }

        if (i + 2 > 0 and i + 2 < n and j - 1 > 0 and j - 1 < n)
        {
            q.push(make_pair(i + 2, j - 1));
            moves[i + 2][j - 1] += moves[i][j] + 1;
        }

        if (i - 1 > 0 and i - 1 < n and j - 2 > 0 and j - 2 < n)
        {
            q.push(make_pair(i - 1, j - 2));
            moves[i - 1][j - 2] += moves[i][j] + 1;
        }

        if (i + 1 > 0 and i + 1 < n and j + 2 > 0 and j + 2 < n)
        {
            q.push(make_pair(i + 1, j + 2));
            moves[i + 1][j + 2] += moves[i][j] + 1;
        }
    }
    return moves[x2-1][y2-1];
}

int main(int argc, char const *argv[])
{
    int n, x1, x2, y1, y2;
    cout << "Enter chess board dimensions: \n";
    cin >> n;

    cout << "Enter starting coordinates :\n";
    cin >> x1 >> y1;
    cout << "Enter Target coordinates :\n";
    cin >> x2 >> y2;
    cout << "Total moves required to reach: " << ghoda(x1, x2, y1, y2, n);
    return 0;
}
