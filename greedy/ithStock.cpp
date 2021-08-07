#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void istocks(int a[], int k, int n)
{
    vector<pair<int, int>> pairs;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        pairs.push_back(make_pair(a[i], i + 1));
    }
    sort(pairs.begin(), pairs.end());

    for (int i = 0; i < pairs.size(); i++)
    {
        c += min(pairs[i].second, k / pairs[i].first);
        k -= min(pairs[i].second, k / pairs[i].first);
    }

    cout << "Maximum stocks bought: " << c << endl;
}

int main(int argc, char const *argv[])
{
    cout << "Enter number of days\n";
    int k, n;
    cin >> n;
    int a[n];
    cout << "Enter cost of stocks\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter pocket: ";
    cin >> k;
    istocks(a, k, n);

    return 0;
}
