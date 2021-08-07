#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, cost = 0;
    cin >> n;
    int g[n];

    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
        /* code */
    }
    vector<pair<int, int>> buy;
    vector<pair<int, int>> sell;

    for (int i = 0; i < n; i++)
    {
        if (g[i] >= 0)
        {
            buy.push_back(make_pair(g[i], i));
        }
        else
            sell.push_back(make_pair(g[i], i));
    }
    int i = 0, j = 0;
    while (i < buy.size() and j < sell.size())
    {
        int x = min(buy[i].first, -sell[j].first);
        buy[i].first -= x;
        sell[j].first += x;

        int diff = abs(buy[i].second - sell[j].second);
        cost += x * diff;

        if (buy[i].first == 0)
            i++;
        if (sell[j].first == 0)
            j++;
    }

    cout << cost;

    return 0;
}
