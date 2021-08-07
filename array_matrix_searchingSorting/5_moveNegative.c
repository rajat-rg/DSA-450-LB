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
    for (int i = 1; i < n - 1; i++)
    {
        arr[i] = arr[i] + arr[i + 1];
        arr[i + 1] = arr[i] - arr[i + 1];
        arr[i] = arr[i] - arr[i + 1];
    }
    arr[0] = arr[0] + arr[n - 1];
    arr[n - 1] = arr[0] - arr[n - 1];
    arr[0] = arr[0] - arr[n - 1];

    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
