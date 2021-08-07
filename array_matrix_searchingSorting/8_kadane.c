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
int max_so_far = -100;
int max=0;

for (int i = 0; i <n;i++)
{
    max += arr[i];
    if (max_so_far< max)
    {
        max_so_far = max;
    }
    if (max < 0)
    max = 0;
}
printf("%d\n",max_so_far);
return 0;
}
