#include <iostream>
using namespace std;
int a[100][100];
int matrixSearch(int a[100][100], int n, int m, int x)
{
    int i = 0, j = 0;
    for (i = 0; i < m;)
    {

        if (x > a[i][m - 1])
            i++;
        else
        {
            for (j = 0; j < m; j++)
            {
                if (x == a[i][j])
                    return 1;
            }
            return 0;
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    int n,m, x, r;
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
    cout << "Aur bhaisaab vo number jo dhundna hai !" << endl;
    cin >> x;

    r = matrixSearch(a, n, m, x);
    cout << r;

    return 0;
}
