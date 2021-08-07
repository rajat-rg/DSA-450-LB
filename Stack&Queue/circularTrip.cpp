#include <iostream>
#include <vector>
using namespace std;

void circular_trip(vector<pair<int, int>> trip)
{

    int f = 0, i = 0;
    int r = f - 1;
    int bal = 0;
    while (f != r)
    {
        bal += trip[i].second - trip[i].first;
        if (bal <= 0)
        {
            bal = 0;
            f = i;
            r = f - 1;
        }

        i = (i + 1) % trip.size();
    }
    cout << "-->> " << i;
}

int main(int argc, char const *argv[])
{
    int n, d, p;
    vector<pair<int, int>> trip;

    for (int i = 0; i < n; i++)
    {
        cin >> d >> p;
        trip.push_back(make_pair(d, p));
        /* code */
    }
    circular_trip(trip);

    return 0;
}
