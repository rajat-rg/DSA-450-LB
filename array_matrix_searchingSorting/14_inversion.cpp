#include <iostream>
using namespace std;
void merging(int *a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int b[100];

    while (j <= high && i <= mid)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
void merge(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge(a, low, mid);
        merge(a, mid + 1, high);
        merging(a, low, mid, high);
    }
}
int main(int argc, const char **argv)
{
    int count, n = 0;
    cin >> count;
    int a[count];
    cout << "++" << endl;
    for (int i = 0; i < count; i++)
    {
        cin >> a[i];
        /* code */
    }
    // for (int i = 0; i < count - 1; i++)
    // {
    //     for (int j = i + 1; j < count; j++)
    //     {
    //         if (a[i] > a[j])
    //             n++;
    //         /* code */
    //     }

    //     /* code */
    // }
    merge(a, 0, count - 1);
    for (int i = 0; i < count; i++)
    {
        cout << a[i] << " ";
        /* code */
    }
    cout << "---" << n;

    return 0;
}