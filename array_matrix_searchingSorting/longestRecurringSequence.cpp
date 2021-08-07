#include<iostream>
#include<string.h>
using namespace std;
int dp[100][100];
int longestRecurringSequence(char a[], int n) {

    
    for (int  i = 0; i<=n; i++)
    {
        for (int  j = 0; j<=n; j++)
        {
            if (i==0 or j==0)dp[i][j]=0;
            if(a[i-1]== a[j-1] and i != j)
            dp[i][j] = dp[i-1][j-1]+1;
            else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        }
        
        /* code */
    }
    return dp[n][n];
    
}
int main(int argc, char const *argv[])
{
    char a[100];
    cin>>a;
    int n = strlen(a);
   for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
            dp[i][j] = -1;
    }

    cout <<longestRecurringSequence(a,n);
    return 0;
}
