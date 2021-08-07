#include<iostream>
using namespace std;

int eggdrop(int n, int k)
{
    if(k==0 or k==1)return k;
    if (n==1)return k;


    int min = INT_MAX, res;


    for (int x=1;x<=k;x++)
    {
        res = max(eggdrop(n-1,x-1), eggdrop(n,k-x));

    if(res < min)
    min =res;

    } 
    return min+1;
}

int main()
{
    int n,k;
    cout<<"Enter numer of eggs and floors: ";
    cin>>n>>k;
    cout<<"Number of drops required: "<<eggdrop(n,k);

    return 0;
}