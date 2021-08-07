#include <stdio.h>
#include <math.h>
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
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i])] >= 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
        {
            printf("--%d\n", i);
            break;
        }
    }
    return 0;
}
