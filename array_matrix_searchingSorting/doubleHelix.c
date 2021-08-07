#include <stdio.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int maxSum(int a[], int n, int b[], int m)
{
    int i = 0, j = 0, s1 = 0, s2 = 0, ans = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            s1 += s1 + a[i];
            i++;
        }
        else if (a[i] > b[j])
        {

            s2 += s2 + b[j];
            j++;
        }
        else
        {

            ans += max(s1, s2) + a[i];
            i++;
            j++;
            s1 = 0;
            s2 = 0;
        }
    }

    while (i < n)
        s1 += s1 + a[i++];
    while (j < m)
        s2 += s2 + b[j++];
    ans += max(s1, s2);
    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 13, m = 11;
    // printf("Enter size of the arrays\n");
    // scanf("%d %d", &n, &m);
    // int a[n], b[m];
    // printf("Enter first arrray\n");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &a[i]);
    //     /* code */
    // }
    // printf("Enter second arrray\n");
    // for (int i = 0; i < m; i++)
    // {
    //     scanf("%d", &b[i]);
    //     /* code */
    // }
    // 3 5 7 9 20 25 30 40 55 56 57 60 62
    // 1 4 7 11 14 25 44 47 55 57 100
    int a[] = {3, 5, 7, 9, 20, 25, 30, 40, 55, 56, 57, 60, 62};
    int b[] = {1, 4, 7, 11, 14, 25, 44, 47, 55, 57, 100};
    printf("-->%d", maxSum(a, n, b, m));

    return 0;
}
