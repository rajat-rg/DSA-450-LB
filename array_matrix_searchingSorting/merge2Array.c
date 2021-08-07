#include<stdio.h>

int merge(int a[], int n , int b[], int m)
{
    int i=0,j=0;
    while(i <n && j < m)
    {
        if(a[i]>b[j])
        {
            a[i] = a[i]+b[j];            
            b[j] = a[i]-b[j];            
            a[i] = a[i]-b[j];            
        }
    }
}

int main(int argc, char const *argv[])
{
    int n,m;
    scanf("Enter size of both arrays\n");
    scanf("%d",&n);
    scanf("%d",&m);
    int a[n],b[m];
    printf("Enter array 1: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter array 2: \n");
    for (int i = 0; i < m ;i++)
    {
        scanf("%d",&b[i]);
    }
    merge(a,n,b,m);
    for (int i = 0; i < n ;i++)
    {
        printf("%d ",a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d ",b[i]);
    }
    
    return 0;
}

