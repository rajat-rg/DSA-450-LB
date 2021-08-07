#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,m;
    cout<<"Enter size of first array: "<<endl;
    cin>>n;
    cout<<"Enter first array \n";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        /* code */
    }
    
    cout<<"Enter size of second array: "<<endl;
    cin>>m;
    cout<<"Enter second array \n";
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin>>b[i];
        /* code */
    }

    for (int i = 0,j=0,k=0; k<m+n;k++)
    {
        if (a[i]>b[j])
        {
            int temp = a[i];
            b[j]=temp;
            a[i] = b[j];
            i++;
         }
         else
         j++;
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
        /* code */
    }
    for (int i = 0; i < m; i++)
    {
        cout<<b[i]<<" ";
        /* code */
    }
    
    
    return 0;
}
