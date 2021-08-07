#include<iostream>
using namespace std;

int stocks(int s[], int f, int l)
{
    if(f == l)return 0;

    for (int i = f+1; i < l; i++)
    {
        return max(stocks(s,f,i-1), stocks(s,i+1, l))+s[i]-s[f];
        /* code */
    }
    

}



int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int s[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>s[i];
        /* code */
    }

    int pro = stocks(s,0,n);
    
    return 0;
}
