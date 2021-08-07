#include <stdio.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}
int partition(int *arr, int low, int high)
{
    int p = arr[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (arr[i] < p)
            i++;
        while (arr[j] > p)
            j--;

        if (i < j)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = arr[i];
        }
    } while (i < j);

    int temp;
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = arr[low];
    return j;
}
void sorting(int *arr, int low, int high)
{
    int p;
    if (low < high)
    {
        p = partition(arr, low, high);
        sorting(arr, low, p - 1);
        sorting(arr, p + 1, high);
    }
}

int main(int argc, char const *argv[])
{
    int n, k;
    printf("Enter size\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array numbers\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter k\n");
    scanf("%d", &k);
    sorting(arr, 0, n - 1);
    int mn, mx;
    int res = arr[n - 1] - arr[0];

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
        /* code */
    }
    printf("\n");

    for (int i = 1; i < n; i++)
    {
        mn = arr[i - 1] + k - arr[n - 1] - k;
        mx = arr[0] + k - arr[i] - k;
        res = min(res, mx - mn);
    }
    printf("%d", res);

    return 0;
}
// 3 4 5 6 7 8
// 8