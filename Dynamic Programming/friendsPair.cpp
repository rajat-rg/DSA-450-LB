#include<iostream>
using namespace std;
int dp[500];
long long friendsPair(int n)
{
    if(dp[n]!= -1)return dp[n];
    if(n==0 or n==1)
    {
        dp[n]=1;
        return dp[n];
    }



    dp[n]=  friendsPair(n-1)+ friendsPair(n-2)*n-1;
    return dp[n];
}
int main(int argc, char const *argv[])
{
    for(int i=0;i<500;i++)
    dp[i]=-1;

    int n;
    cout<<"Enter number of friends: ";
    cin>>n;
    cout<<friendsPair(n);
    return 0;
}
