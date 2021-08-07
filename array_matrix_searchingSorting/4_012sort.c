#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter size\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array numbers\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int low = 0, mid = 0, high = n - 1;
    for (int i = 1; i < n && mid <= high; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = arr[i] + arr[low];
            arr[low] = arr[i] - arr[low];
            arr[i] = arr[i] - arr[low];
            low++;
        }
        if (arr[i] == 1)
        {
            mid++;
        }
        if (arr[i] == 2)
        {
            arr[i] = arr[i] + arr[high];
            arr[high] = arr[i] - arr[high];
            arr[i] = arr[i] - arr[high];
            high--;
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
