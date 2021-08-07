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
        scanf("%d",&arr[i]);
    }

    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        arr[i] = arr[i] + arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] = arr[i] -arr[j];
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}
