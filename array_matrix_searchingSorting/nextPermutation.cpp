#include <iostream>
using namespace std;
void swap(int a, int b)
{
    int t = a;
    a = b;
    b = a;
}
void reverse(int a[], int l, int r)
{
    int i = l, j = r;
    while (i <= j)
    {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}
void nextPermutation(int a[], int n)
{
    int idx = -1;
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] > a[i - 1])
            idx = i;
    }
    if (idx == -1)
    {
        reverse(a, 0, n);
    }
    else
    {
        int prev = idx;
        for (int i = idx + 1; i < n; i++)
        {
            if (a[i] > a[idx - 1] and a[i] > prev)
            {
                prev = i;
            }
        }
        swap(a[idx - 1], a[prev]);
        reverse(a, idx, n);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    nextPermutation(a, n);

    return 0;
}
