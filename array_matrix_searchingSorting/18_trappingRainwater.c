#include<stdio.h>
int min(int a, int b)
{
    if(a<b) return a;
    else return b;
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int left[n],right[n];
    left[0] = a[0];
    for (int i = 1; i < n; i++){
        if(a[i]>left[i-1])
        left[i] = a[i];
        else
        left[i] = left[i-1];
    }
    right[n-1]=a[n-1];
    for (int i = n-1; i >=0; i--){
        if(a[i]>right[i+1])
        right[i] = a[i];
        else
        right[i] = right[i+1];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ",left[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ",right[i]);
    // }
    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water+=min(left[i],right[i]) - a[i];
    }
printf("%d ",water);
    return 0;
}
