#include <iostream>
#include<string.h>

using namespace std;

void rabin(char a[], char t[], int n, int m)
{
    int i=0,j=0,pos =-1;
    while(i< n)
    {
        if(j==m-1)
        {
            cout<<pos<<" ";
            pos=-1;j=0;
        }
        if(a[i] == t[0] and pos ==-1)
        {
            pos=i;
            i++;j++;
        }

        if(a[i]==t[j])
        {
            i++;j++;
        }
        else
        {
            
            i++;
        }
    }
    // cout<<pos;/
}
int main(int argc, char const *argv[])
{
    char a[100], t[100];
    cin>>a;
    cin>>t;
    int n = strlen(a);
    int m = strlen(t);
    rabin(a,t,n,m);
    return 0;
}
