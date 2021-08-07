#include <iostream>
#include <cstring>

using namespace std;
int dp[500][500];

int saudaKharaKhara(int a[], int n, int s)
{
    if (n == -1)
        if (s == 0)
            return 1;
    return 0;

    if (s < 0)
        return 0;
    if (s == 0)
        return 1;

    if (dp[n][s] != -1)
        return dp[n][s];
    
    dp[n][s] = saudaKharaKhara(a, n - 1, s) || saudaKharaKhara(a, n - 1, s - a[n]);
    cout<<dp[n][s]<<" "; 
    return dp[n][s];
}
void equalPartition(int a[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    if(s & 1)
    {
        cout<<"... "<<0;
        return;
    }
    s = s/2;
    dp[n][s];
    memset(dp, -1, sizeof(dp));
    
    cout << " -> " << saudaKharaKhara(a, n-1, s);
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int a[n];
    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    equalPartition(a, n);
    return 0;
}
