#include <iostream>

using namespace std;

void fight(int sol, int power[], int round, int bishu[])
{
    for (int i = 0; i < round; i++)
    {
        int sum = 0;
        int knockout = 0;
        for (int j = 0; j < sol; j++)
        {
            if (power[j] <= bishu[i])
            {
                sum += power[j];
                knockout++;
            }
        }
        cout << sum << "===" << knockout<<endl;
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1, j = high;

    while (i < j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[j];
    a[j] = a[low];
    a[low] = temp;
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

int main()
{
    int sol, rounds;
    cout << "Enter number of soldiers\n";
    cin >> sol;
    int power[sol]; // Reading input from STDIN
    cout << "Enter powers" << endl;
    for (int i = 0; i < sol; i++)
    {
        cin >> power[i];
    }
    sort(power, 0, sol - 1);
    for (int i = 0; i < sol; i++)
    {
        cout << power[i] << ' ';
    }
    cout << "Enter rounds:\n";
    cin >> rounds;
    int bishu[rounds];
    cout << "Enter bishu ki power in each round\n";
    for (int i = 0; i < rounds; i++)
    {
        cin >> bishu[i];
    }
    fight(sol, power, rounds, bishu);
    return 0;
}
