#include<iostream>
using namespace std; 
int dp[500][500];
int coinChange(int c[], int n, int x)
{
    if(dp[n][x]!=-1)return dp[n][x];
    if(x==0)
    dp[n][x]= 1;
    
    if(x<0) 
    dp[n][x]= 0;
    
    if(n<=0 and x>=1) dp[n][x]= 0;


    dp[n][x]= coinChange(c,n,x-c[n-1])+coinChange(c,n-1,x);
    return dp[n][x];
}



int main()
{
    int n,x;
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        dp[i][j]=-1;
    }
    cout<<"Enter number of coins: ";
    cin>>n;
    cout<<"Enter coins: ";

    int c[n];

    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
    }
    cout<<"Enter amount: ";
    cin>>x;
    int r = coinChange(c,n,x);
    cout<<"Number of possible combinations are: "<<r;
    

    return 0;
}