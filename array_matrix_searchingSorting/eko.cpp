#include <iostream>

using namespace std;
int max(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}
int eko(int a[], int n, int m)
{
    int low = 0, high = max(a, n);

    int ans = 0;
    while (low <= high)
    {
        int sum = 0;
        int mid = (low + high) / 2;
        for (int i = 0; i < n; i++)
        {
            if(a[i]>mid)
            sum += a[i] - mid;
        }
        if (sum >= m)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cout << "Enter number of trees\n";
    cin >> n;
    int a[n];
    cout << "Enter heights of trees\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter required wood amount\n";
    cin >> m;
    cout << eko(a, n, m);

    return 0;
}
