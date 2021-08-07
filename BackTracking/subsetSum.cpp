#include<iostream>
using namespace std;

bool subsetSum(int ar[], int n,int sum, int halfsum)
{
    if(sum == halfsum)return true;
    if(n<0 and sum != halfsum)return false;
    if( ar[n] > halfsum)
    subsetSum(ar, n-1, sum,halfsum);

    return subsetSum(ar, n-1, sum,halfsum) or subsetSum(ar, n-1, sum+ar[n],halfsum);
}
int main(int argc, const char** argv) {
    int n;
    cin>>n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin>>ar[i];                                                                         
    }

    int sum=0;
    bool res;
    for(int i=0;i<n;i++)sum+=ar[i];
    if(sum%2 == 0 )
    res = subsetSum(ar, n-1,0, sum/2);
    else
    res = false;
    cout<<res;



    return 0;
}