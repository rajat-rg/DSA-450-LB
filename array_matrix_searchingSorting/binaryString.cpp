#include<iostream>
#include<string.h>
using namespace std;

int binarySplit(char a[], int n)
{
    int  zero=0,one=0;
    int num=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='0')
        zero++;
        if(a[i]=='1')
        one++;
        if(one ==zero)
        {
            zero=0;
            one=0;
            num++;
        }

    }
    return (num>0)?num:-1;
}
int main(int argc, char const *argv[])
{
    char a[100];
    cin>>a;
    int n= strlen(a);

    cout<<binarySplit(a,n);
    return 0;
}

