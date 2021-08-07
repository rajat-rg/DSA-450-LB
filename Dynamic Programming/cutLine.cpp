#include<iostream>
using namespace std;
int cutLine(int n, int x, int y, int z)
{
    if(n==0)return 0;
    int o1 = INT_MIN;
    int o2 = INT_MIN;
    int o3 = INT_MIN;

    if(n>=x) o1 = cutLine(n-x, x, y, z);
    if(n>=y) o2 = cutLine(n-y, x, y, z);
    if(n>=z) o3 = cutLine(n-z, x, y, z);

    return 1+max(o1,max(o2,o2));
}



int main(int argc, char const *argv[])
{
    int n,x,y,z;
    cout<<"Enter n: ";cin>>n;
    cout<<"\nEnter x, y, z: ";cin>>x>>y>>z;
    cout<<cutLine(n,x,y,z);
    
    return 0;
}
