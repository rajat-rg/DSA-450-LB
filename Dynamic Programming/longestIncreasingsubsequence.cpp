#include <iostream>
using namespace std;

// int lis(int a[], int n)
// {
//     int prev,s,mx=0;

//     for (int i = 0; i < n; i++)
//     {
//         prev=i;
//         s=1;
//         for (int j=i+1; j < n; j++)
//         {
//             if(a[j]> a[prev])
//             {
//                 s++;
//                 prev = j;
//             }
//             /* code */
//         }
//         if(s > mx)
//         mx=s;
//         /* code */
//     }
//     return mx;

// }
int dp[100];

int lis(int a[], int n)
{

    if (dp[n] != -1)
        return dp[n];
    dp[n] = 1;

    for (int i = 0; i < n; i++)
    {
        if (a[n] > a[i])
        {
            dp[n] = max(dp[n], lis(a, i) + 1);
        }
        
    }
    return dp[n];
}
int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int a[n];
    cout << "Enter array numbers: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        
    }
    for (int i = 0; i < 100; i++)
    {
        dp[i] = -1;
        /* code */
    }
    
    cout << "Length of longest increasing subsequence is: " << lis(a, n-1);
    return 0;
}