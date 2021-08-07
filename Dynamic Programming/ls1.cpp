#include<iostream>
using namespace std;

int ls1(int a[], int n)
{
    int num=0;
    for (int i = 0; i < n-1; i++)
    {
        int prev = a[i];
        int c=1;
        for (int j = i+1; j < n; j++)
        {
            if(abs(a[j]- prev) == 1)
            {
                c++;
                prev = a[j];
            }
            /* code */
        }
        if(c>num)
        num = c;
        
        /* code */
    }
    return num;
    
}
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter array: \n";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        /* code */
    }
    // are aise subarray bnana hai isme hr m=number ke aas pas vale se distance 1 ho bs
    cout<<"Length of longest subarray : "<<ls1(a,n);
    return 0;
}
