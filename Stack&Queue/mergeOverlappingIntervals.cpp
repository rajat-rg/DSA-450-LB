#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
stack<pair<int,int>> s;

void mergeIntervals(vector<pair<int,int>> a, int n)
{
    s.push(a[0]);
    for (int i = 1; i != a.size(); i++)
    {
        pair<int,int> t = s.top();
        s.pop();
        if(t.second > a[i].first)
        {
            s.push({t.first, a[i].second});
        }
        else{
            s.push(t);
            s.push(a[i]);
        }

        /* code */
    }
    

}

int main(int argc, char const *argv[])
{
    int n,f,l;
    cin>>n;
    vector<pair<int,int>> a;
    for (int i = 0; i < n; i++)
    {
        cin>>f>>l;
        a.push_back({f,l});
        /* code */
    }
    sort(a.begin(), a.end());
    
    mergeIntervals(a,n);
    while(!s.empty())
    {
        cout<<"{"<<s.top().first<<", "<<s.top().second<<"}\n";
        s.pop();

    }
    
    return 0;
}
