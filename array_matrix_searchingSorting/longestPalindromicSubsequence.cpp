#include <iostream>
#include <string.h>
using namespace std;
int dp[100][100];
int longestPalindromicSubsequence(char a[], int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i > j)
        return 0;

    if (i == j)
        return 1;

    if (a[i] == a[j])
        dp[i][j] = longestPalindromicSubsequence(a, i+1, j-1) + 2;
    else
        dp[i][j] = max(longestPalindromicSubsequence(a, i+1, j), longestPalindromicSubsequence(a, i, j-1));

    return dp[i][j];
}
int main(int argc, char const *argv[])
{
    char a[100];
    cin >> a;
    int n = strlen(a);
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
            dp[i][j] = -1;
    }

    cout << longestPalindromicSubsequence(a, 0, n - 1);
    return 0;
}
