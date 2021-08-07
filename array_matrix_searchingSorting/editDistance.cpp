#include <iostream>
#include <string.h>
using namespace std;
int minn(int a, int b, int c)
{
    if (a < b)
    {
        if (a < c)
            return a;
    }
    else
    {
        if (b < c)
            return b;
    }

    return c;
}
int editDistance(char a[], int n, char b[], int m)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;

    if (a[n - 1] == b[m - 1])
    {
        return editDistance(a, n - 1, b, m - 1);
    }
    return minn(editDistance(a, n - 1, b, m),
                editDistance(a, n, b, m - 1),
                editDistance(a, n - 1, b, m - 1)) +1;
}
int main(int argc, char const *argv[])
{
    char a[100];
    cin >> a;
    int n = strlen(a);
    char b[100];
    cin >> b;
    int m = strlen(b);

    int ls = editDistance(a, n, b, m);
    cout<<"--"<<ls;
    
    return 0;
}
