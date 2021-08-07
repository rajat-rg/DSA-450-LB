#include<iostream>
using namespace std;
long long f[500];
long long fact(int x) { 
    if(f[x]!=-1)return f[x];
    if(x==1 || x==0)return f[1];
    f[x]= x*fact(x-1);
    
    return f[x];

}
int nCr(int n, int r)
{
    if(n<r)return -1;

    int fc = fact(n);    
    int fr = fact(r);
    int fnr = fact(n-r);
    

    return fc/(fr*fnr);

}
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 500; i++)
    {
        f[i]=-1;
        /* code */
    }
    f[0]=1;
    f[1]=1;
    int n,r;
    cout<<"Enter n and r: "<<endl;
    cin>>n>>r;
    cout<<endl;
    cout<<nCr(n,r);

    return 0;
}

