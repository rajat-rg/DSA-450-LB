#include <iostream>
using namespace std;
int a[100][100];
int rotate90(int a[100][100], int n, int m)
{
    int b[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0, k = n - 1; j < n; j++, k--)
        {
            // b[i][j] = a[k][i];
            cout << a[k][i] << " ";

        }
        cout << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         cout << b[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cout << "Enter row: " << endl;
    cin >> n;
    cout << "Enter coulmn: " << endl;
    cin >> m;
    cout << "Enter array \n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << "------" << endl
         << endl;
    rotate90(a, n, m);

    return 0;
}
