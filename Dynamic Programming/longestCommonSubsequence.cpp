#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int dp[100][100];
int longestCommonSubsequence(char s1[], char s2[], int n, int m)
{
    if (dp[n][m] != -1)
        return dp[n][m];
    if (n == 0 or m == 0)
    {
        dp[n][m] = 0;
        return dp[n][m];
    }
    if (s1[n - 1] == s2[m - 1])
    {
        dp[n][m] = longestCommonSubsequence(s1, s2, n - 1, m - 1) + 1;
        return dp[n][m];
    }
    else
    {
        dp[n][m] = max(longestCommonSubsequence(s1, s2, n, m - 1), longestCommonSubsequence(s1, s2, n - 1, m));
        return dp[n][m];
    }
}

int LongestRepeatingSubsequence(string str, int n, int m)
{
    if (dp[n][m] != -1)
        return dp[n][m];
    if (n == 0 or m == 0)
    {
        dp[n][m] = 0;
        return dp[n][m];
    }

    if (str[n - 1] == str[m - 1] and n != m)
    {
        dp[n][m] = LongestRepeatingSubsequence(str, n - 1, m - 1) + 1;
        return dp[n][m];
    }
    else
    {
        dp[n][m] = max(LongestRepeatingSubsequence(str, n, m - 1), LongestRepeatingSubsequence(str, n - 1, m));
        return dp[n][m];
    }
}
int main(int argc, char const *argv[])
{
    int n, m;

    char s1[100], s2[100];
    cout << "Enter strings: \n";
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    n = strlen(s1);
    m = strlen(s2);

    cout << "Longest common subsequence is of length: " << longestCommonSubsequence(s1, s2, n, m);
    memset(dp, -1, sizeof(dp));
    cout << "\nLongest repeating subsequence is of length: " << LongestRepeatingSubsequence(s1, n, n - 1);

    return 0;
}
