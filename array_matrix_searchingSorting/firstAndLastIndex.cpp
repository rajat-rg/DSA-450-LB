#include <iostream>
using namespace std;

void findX(int a[], int n, int x)
{
    int f, l;
    int low = 0, high = n;
    int mid = (low + high) / 2;
    while (mid > low or mid < high)
    {
        if (a[mid] == x)
        {
            f = l = mid;
            break;
        }
        if (x > a[mid])
        {
            mid = (mid + high) / 2;
        }
        else
            mid = (low + mid) / 2;
    }
    int i=f,j=l;
    while(1)
    {
        i--;
        if(a[i] == a[f])
        {
            f=i;
        }
        else
        break;
    }
    while(1)
    {
        j++;
        if(a[j] == a[l])
        {
            l = j;
        }
        else
        break;
    }

    cout<<"f is - "<<f<<" and l is-"<<l;
}

int main(int argc, char const *argv[])
{
    int n, x;
    cout << "Enter size\n";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter X\n";
    cin >> x;
    findX(a, n, x);
    return 0;
}
