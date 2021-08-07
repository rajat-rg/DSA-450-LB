#include<iostream>
using namespace std;
// solution in o(n*n)
void zero_sum(int a[], int num)
{
    int sum = 0;
    for(int i = 0; i < num-1;i++)
    {
        for(int j = i; j <num;j++)
        {
            sum += a[j];
            if(sum ==0)
            {
                cout<<"*\t";
                break;
            }
        }
        sum = 0;
    }
}

int main(int argc, char const *argv[])
{
    int n,num;cin>>n;
    int a[n]= {6,-1,-3,4,-2,2,4,6,-12,-7};
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>a[i];
    // }cout<<"---\n";
    
    zero_sum(a,n);
    return 0;
}
