#include<iostream>
#include<string>
using namespace std;
int dp[500][500];
int lcs(string s1,string s2,int n,int m)
{
    if(dp[n][m]!=-1)return dp[n][m];
    if(n ==0 )
    {
        dp[n][m]= m;
        return dp[n][m];
    }
    if(m ==0 )
    {
        dp[n][m]= n;
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1])
    {
    dp[n][m]= lcs(s1,s2,n-1,m-1);
    return dp[n][m];
    }

    dp[n][m]= min(min(lcs(s1,s2,n,m-1), lcs(s1,s2,n-1,m)),lcs(s1,s2,m-1,n-1))+1;
    return dp[n][m];

}
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j<500; j++)
        {
            dp[i][j]=-1;
            /* code */
        }
        
        /* code */
    }
    
    string s1,s2;
    cout<<"Enter strings: \n";
    getline(cin,s1);
    getline(cin,s2);
    int n = s1.size();
    int m = s2.size();
    cout<<"Operations required on the strings are: "<<lcs(s1,s2,n,m);
    return 0;
}
