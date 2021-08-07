#include <iostream>
using namespace std;
int partition(int a[], int low, int high)
{
    int i = low + 1, j = high;
    int p = a[low];
    while (i < j)
    {
        while (a[i] < p and i <= j)
            i++;
        while (a[j] > p)
            j--;

        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
void sort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        sort(a, low, p - 1);
        sort(a, p + 1, high);
    }
}

int aggressiveCows(int stall[], int s, int c)
{
    sort(stall, 0, s - 1);
    int lower = 0;
    int upper = stall[s - 1] - stall[0];
    int ans = 0;
    while (lower <= upper)
    {
        int mid = (upper + lower) / 2;
        int cow = 1;
        int prev = stall[0];
        for (int i = 1; i < s; i++)
        {
            if (stall[i] - prev >= mid)
            {
                cow++;
                prev = stall[i];
            }
            if (cow == c)
                break;
        }
        if (cow == c)
        {
            ans = mid;
            lower = mid + 1;
        }
        else
            upper = mid - 1;
    }

    return ans;
}

int main()
{
    int c, s;
    cout << "Enter number of stalls :" << endl;
    cin >> s;
    int stall[s];
    cout << "Enter number of cows :" << endl;
    cin >> c;
    cout << "Enter stall locations :" << endl;
    for (int i = 0; i < s; i++)
    {
        cin >> stall[i];
    }

    cout << aggressiveCows(stall, s, c);

    return 0;
}