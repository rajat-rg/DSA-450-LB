#include <iostream>

using namespace std;

int d[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
long long dp[10][1000];

long long solve(int i, int j, int n)
{

    if (n == 1)
        return 1;
    if (dp[d[i][j]][n] != -1)
        return dp[d[i][j]][n];
    long long a = solve(i, j, n - 1);

    long long b, c, de, e;
    b = c = de = e = 0;

    if (j - 1 >= 0 and d[i][j - 1] != -1)
        b = solve(i, j - 1, n - 1);
    if (j + 1 < 3 and d[i][j + 1] != -1)
        c = solve(i, j + 1, n - 1);
    if (i - 1 >= 0 and d[i - 1][j] != -1)
        de = solve(i - 1, j, n - 1);
    if (i + 1 < 4 and d[i + 1][j] != -1)
        e = solve(i + 1, j, n - 1);

    dp[d[i][j]][n] = a + b + c + de + e;
    return dp[d[i][j]][n];
}

long long dialpad(int n)
{
    long long max = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            dp[i][j] = -1;
        }

        /* code */
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(d[i][j]!=-1)
            max += solve(i, j, n);
        }

        /* code */
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int n;
    long long w;
    cin >> n;
    w = dialpad(n);
    cout<<endl<<w;
    return 0;
}
