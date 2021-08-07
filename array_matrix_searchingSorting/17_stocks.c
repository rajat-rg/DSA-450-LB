#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int min=0;
    for (int i = 1; i < n; i++)
    {
        if(a[i] < a[min])
        min= i;
    }
    int max=min;
    for (int i = max; i < n; i++)
    {
        if(a[i] > a[max])
        max = i;
    }
    printf("%d",a[max]-a[min]);
    return 0;
}
