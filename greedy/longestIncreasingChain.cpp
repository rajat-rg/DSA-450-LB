#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxChain(vector<pair<int, int>> link)
{
    if (link.size() == 0 || link.size() == 1)
        return link.size();

    int num = 1;
    int prev = link[0].second;
    for (int i = 1; i < link.size(); i++)
    {
        
        if (link[i].first >= prev)
        {
            prev = link[i].second;
            num++;
        }
    }
    return num;
}

int main(int argc, char const *argv[])
{
    int n, f, s;
    vector<pair<int, int>> link;
    cout << "Enter number of pairs in chain: ";
    cin >> n;
    cout << "Enter n pairs: ";
    for (int i = 0; i < n; i++)
    {
        cin >> f >> s;
        link.push_back(make_pair(f, s));
    }
    sort(link.begin(), link.end());
    int d = maxChain(link);
    cout << "Max length of chain is :" << d << endl;
    return 0;
}
