#include<iostream>
using namespace std;
int dp[500][500];
int coinChange(int a[], int n, int k)
{
    if (dp[n][k]!=-1)
    return  dp[n][k];

    if (k ==0)
    return 1;

    if(k<0)
    return 0;

   

    dp[n][k] = coinChange(a,n,k-a[n-1]) + coinChange(a,n-1,k);
    cout<<"--"<<dp[n][k]<<endl;
    return dp[n][k];
}
int main(int argc, char const *argv[])
{
    int n,m,r;
    cout<<"Enter size of first array: "<<endl;
    cin>>n;
    cout<<"Enter first array \n";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        /* code */
    }
    cout<<"Enter k\n";
    cin>>m;
    for (int i=0;i<500;i++)
    {
        for (int j=0;j<500;j++)
        dp[i][j] = -1;
    }
     for (int i = 1; i < 500; i++)
        dp[0][i] = 0;
    dp[0][0] = 1;
    r = coinChange(a,n,m);
    cout<<r;
    
    
    return 0;
}
