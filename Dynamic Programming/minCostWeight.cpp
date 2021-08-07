#include <iostream>
#include <cstring>
using namespace std;

int dp[500][500];
int minimumCost(int cost[], int N, int W)
{
    // Your code goes here
    // cout<<N<<" ";
    if (N == -1 and W == 0)
        return 0;
    if (N == -1)
        return 1e9;
    if (W == 0)
        return  0;
    if(dp[N][W] != -1)return dp[N][W];
    if (N > W)
        return dp[N][W] = minimumCost(cost, N - 1, W);
    return dp[N][W] = min(minimumCost(cost, N - 1, W),
               minimumCost(cost, N - 1, W-N) +
                   cost[N - 1]);
}

int main(int argc, char const *argv[])
{
    int n, k;
    cout << "Enter size: ";
    cin >> n;
    int a[n];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << "Enter Weight: ";
    cin >> k;
    cout << endl
         << minimumCost(a, n, k);

    return 0;
}
