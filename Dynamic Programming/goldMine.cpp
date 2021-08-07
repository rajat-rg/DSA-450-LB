#include <iostream>
// Ye solution abhi galt hai kuch khami hai yaame,  sbke lie na chle shi se or me bna bhi na rha ab ise shi.
using namespace std;
const int maxm = 500;
int goldMine(int g[][maxm], int n, int m, int p)
{
    int i = p, j = 0;
    int gold = g[p][0];
    while (j <= m-1)
    {
        cout<<";";
        int r = g[i][j + 1];
        int ru = g[i - 1][j + 1];
        int rd = g[i + 1][j + 1];

        if (r >= ru and r >= rd)
        {
            gold += r;
            j += 1;
        }
        else if ((ru > r and ru > rd) and i!= 0)
        {
            gold += ru;
            i--;
            j++;
        }
        else if ((rd > r and rd > ru) and i!= n-1)
        {
            gold += rd;
            i++;
            j++;
        }
    }

    return gold;
}


int main(int argc, char const *argv[])
{
    int n,m;
    cout << "Enter row and column: ";
    cin >> n >> m;
    int g[n][maxm];
    cout << "Enter the gold weight:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            /* code */
        }

        /* code */
    }
    int px = 0;
    for (int i = 1; i < m; i++)
    {
        if (g[i][0] > g[px][0])
        {
            px = i;
        }
        /* code */
    }

    cout << "Maximum gold nikala hai malik: " << goldMine(g, n, m, px);

    return 0;
}

