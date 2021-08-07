#include <iostream>
#include <string.h>
using namespace std;
void swap(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
void permutation(int a[], int i, int n)
{
    if (i == n)
    {
        for (int j = 0; j < n; j++)
            cout << a[j] << " ";
        cout << endl;
        return ;
    }
    for (int j = i; j < n; j++)
    {

        swap(a, j, i);
        permutation(a, i + 1, n);
        swap(a, j, i);
    }
}

int main(int argc, char const *argv[])
{
    int a[100], n;
    cout <<"enter size\n";
    cin >> n;
    cout << "Enter array \n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    permutation(a,0, n);

    return 0;
}
