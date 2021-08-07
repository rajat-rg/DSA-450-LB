#include<iostream>

using namespace std;
int dp[500][500];
int knapsack(int o[],int p[] ,int n,int k)
{
    if(dp[n][k] !=-1)return dp[n][k];
    if(n<=0)dp[n][k] = 0;
    if(k<=0 and n>=0)dp[n][k] = 0;


    if(o[n-1]>k)
   {
       dp[n][k] = knapsack(o,p,n-1,k);
       return dp[n][k]; 
   } 
       

    dp[n][k] = max(knapsack(o,p,n-1, k-o[n-1])+p[n-1],knapsack(o,p,n-1, k)) ;
    return dp[n][k];



}
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 500; j++)
        dp[i][j]=-1;
    }
    int n,k;
    cout<<"Enter number of items: ";
    cin>>n;
    int o[n];
    int p[n];
    cout<<"Enter object weights and profit: ";
    for (int i = 0; i < n; i++)
    {
        cin>>o[i];
        cin>>p[i];
    }
    cout<<"Enter weight of knapsack: ";
    cin>>k;

    cout<<"Maximum profit is :"<<knapsack(o,p,n,k);
    
    return 0;
}
