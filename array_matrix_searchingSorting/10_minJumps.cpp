#include <stdio.h>
#include<iostream>
using namespace std;
int minJumps(int *arr, int n)
{
    int j=0,jumps=0,max_pos;
    for (int i=0,j=0; i<n;j++)
    {
        max_pos = max(max_pos,arr[j]+j);
        if(max_pos > i and max_pos <n)
        {
            i = max_pos;
            jumps++;
            cout<<i<<" ";
        }



    }
    return jumps;
}
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter size"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter array numbers\n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int jumps = minJumps(arr, n);
    cout<<endl<<"___"<< jumps;
    return 0;
}
