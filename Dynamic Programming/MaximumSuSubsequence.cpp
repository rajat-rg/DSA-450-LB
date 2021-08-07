#include <iostream>
using namespace std;

int lis(int  a[], int n)
{
    int max, max_yet=0,prev;

    for(int i=0;i<n;i++)
    {
        max= a[i];
        prev = a[i];
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>prev)
            {
                max+=a[j];
                prev = a[j];
            }
        }
        if(max> max_yet)
        {
            max_yet = max;
        }
    }
    return max_yet;


}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter array length: ";
    cin >> n;
    int arr[n];
    cout << "Enter array numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        /* code */
    }
    cout << "Maaximum sum subsequence is :" << lis(arr, n);

    return 0;
}
