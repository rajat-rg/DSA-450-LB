#include <iostream>
using namespace std;

void findX(int a[], int n)
{
    int repeat, missing;

    for (int i = 0; i < n; i++)
    {
        int pos = a[i] - 1;
        if (i != pos)
        {
            if (a[pos] == a[i])
            {
                repeat = a[i];
            }
            else
            {
                int temp = a[i];
                a[i] = a[pos];
                a[pos] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] - 1 != i)
            missing = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\n___" << repeat << endl;
    cout << "\n___" << missing << endl;
}

int main(int argc, char const *argv[])
{
    int n, x;
    cout << "Enter size\n";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    findX(a, n);
    return 0;
}
