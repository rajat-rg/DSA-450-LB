#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, k;
    int max, min;
    printf("Enter size\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array numbers\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter K\n");
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j < n - 1; j++)
        {
            if (arr[j] > arr[i])
            {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }
    
    max = arr[k - 1];
    min = arr[n - k - 1];
    printf("\nmax --%d\nmin --%d\n", max, min);
    return 0;
}
