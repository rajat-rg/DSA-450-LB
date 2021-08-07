#include<iostream>
using namespace std;

int maxAdj(int a[], int n)
{
    int inc =a[0];
    int exc = 0;
    int exc_new = 0;

    for(int i=1;i<n;i++)
    {
        exc_new = (inc>exc)?inc:exc;
        inc  = exc + a[i];
        exc = exc_new;
    }
    return (inc>exc)?inc:exc;
}

int main(int argc, const char** argv) {
    int n;cin>>n;
    int a[n];
    cout<<"----"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        /* code */
    }
    int mx = maxAdj(a,n);
    cout<<"##->"<<mx<<endl;
    return 0;
}