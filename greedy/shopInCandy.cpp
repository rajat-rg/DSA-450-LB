#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void candies(vector<int> a, int k)
{
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
    int all=0,min=0,max=0;
    for (int i = 0,j=a.size()-1; i < a.size(); i++,j--)
    {
        if(all<a.size())
        {
            max+=a[j];
            min+=a[i];
            all += 1;
        }
        if(all != a.size())
        all+=k;
    
    }
    cout<<min<<"-->>"<<max;
    
}

int main(int argc, char const *argv[])
{
    int k, n;
    cout << "Enter number of candies\n";
    cin >> n;
    vector<int> a;
    cout << "Enter cost of candies\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout << "Enter free scheme: ";
    cin >> k;
    candies(a, k);

    return 0;
}
