#include<iostream>
#include<map>

using namespace std;


int knapsack(map<int,int> wp, int k)
{
    int pro=0;
    for (auto  it = wp.rbegin(); it != wp.rend(); it++)
    {
        wp.insert({it->first/it->second, it->second});
        wp.erase(it->first);
        
        
    }
    for (auto  it = wp.rbegin(); it != wp.rend(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
        
    }
    



return 1;

}
int main(int argc, char const *argv[])
{
    int n,w,p,k;
    cout<<"Enter size: ";
    cin>>n;
    map<int,int> wp;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter weight: ";
        cin>>w;
        cout<<"Enter profit: ";
        cin>>p;
        wp.insert({p,w});
    }
    cout<<"Enter size pf knapsack: ";
    cin>>k;

    knapsack(wp,k);    
    return 0;
}
