#include<iostream>
#include<algorithm>

using namespace std;


int main(int argc, char const *argv[])
{
    int n,sum=0,k;
    cout<<"Enter size: ";
    cin>>n;
    int a[n];
    cout<<"Enter array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a, a+n);
    cout<<"Enter K: ";
    cin>>k;
    for (int i = n; i >=0; i--)
    {
        if(a[i] - a[i-1] <=k)
        sum += a[i];
        sum += a[i-1];
        /* code */
    }
    cout<<endl<<sum;
    

    
    return 0;
}
