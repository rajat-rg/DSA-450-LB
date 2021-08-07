#include <iostream>
using namespace std;
bool dp[500];

int dearrangementPermutation(int n)
{
    if (dp[n] != -1)
        return dp[n];
    if (n == 1)
    {
        dp[1] = 0;
        return dp[n];
    }
    if (n == 2)
    {
        dp[2] = 1;
        return dp[n];
    }
    dp[n] = (n - 1) * (dearrangementPermutation(n - 1), dearrangementPermutation(n - 2));
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    for (int i = 0; i < 500; i++)
    {
        dp[i] = -1;
        /* code */
    }

    cout << dearrangementPermutation(n);
    return 0;
}
