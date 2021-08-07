#include <iostream>
#include <algorithm>
using namespace std;

void costCutting(int am[], int an[], int m, int n)
{
    int hc = 1, vc = 1;
    int i = 0, j = 0;
    m--;
    n--;
    int ans = 0;
    sort(am, am + m, greater<int>());
    sort(an, an + n, greater<int>());

    while (i < m and j < n)
    {
        if (am[i] < an[j])
        {
            ans += vc * am[i];
            i++;
            hc++;
        }
        else
        {
            ans += hc * am[j];
            j++;
            vc++;
        }
    }

    while (i < m)
    {
        ans += vc * an[i];
        i++;
        hc++;
    }

    while (j < n)
    {
        ans += hc * an[j];
        j++;
        vc++;
    }

    cout << "inimum cutting cost is : " << ans << endl;
}

int main(int argc, char const *argv[])
{
    int m, n;
    cout << "Enter number of columns: ";
    cin >> m;
    cout << "Enter number of rows: ";
    cin >> n;
    int cm[m], cn[n];
    cout << "Enter cost of cutting columns: ";
    for (int i = 0; i < m; i++)
    {
        cin >> cm[i]; /* code */
    }
    cout << "Enter cost of cutting rows: ";
    for (int i = 0; i < n; i++)
    {
        cin >> cn[i]; /* code */
    }

    costCutting(cm, cn, m, n);

    return 0;
}
