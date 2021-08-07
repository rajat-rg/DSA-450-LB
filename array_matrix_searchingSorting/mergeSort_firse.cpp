#include <iostream>
using namespace std;

void merging(int *a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int b[100];
    while (i <= mid && j <= high)
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
    for (int i = low; i < high; i++)
    {
        a[i] = b[i];
    }
}

void merge(int *a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge(a, low, mid);
        merge(a,  mid + 1,high);
        merging(a, low, mid, high);
    }
}
int main(int argc, char const *argv[])
{
    int count;
    cin >> count;
    cout << "++" << endl;
    int a[count];
    for (int i = 0; i < count; i++)
    {
        cin >> a[i];
        /* code */
    }
    merge(a, 0, count - 1);
    cout << endl;
    for (int i = 0; i < count; i++)
    {
        cout << a[i] << " ";
        /* code */
    }

    return 0;
}
