#include<iostream>
using namespace std;

int colorFence(int n, int k)
{
    int last, lastsec,smy;
    last = k;
    lastsec = k*k;
    if(n==1)
    smy = k;

    if (n==2)
    smy = k*k;

    for (int i = 3; i <= n; i++)
    {
        smy = (last+lastsec)* (k-1);
        lastsec = last;
        last = smy;
        /* code */
    }
    return smy;


}



int main(int argc, char const *argv[])
{
    int n,k;
    cout<<"Enter numner of fence post and color: ";
    cin>>n>>k;
    cout<<colorFence(n,k);
    return 0;
}
