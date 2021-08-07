#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int minCoins(int a,vector<int> coins)
{
    int n,tc=0;
    sort(coins.begin(),coins.end(),greater<int>());

    for(int i = 0; i < coins.size(); i++)
    {
        n = a/coins[i];
        a -= n*coins[i];
        tc+=n;
    }
    return tc;

}

int main(int argc, char const *argv[])
{
    int a,x;
    int n;
    cout<<"Enter amount: ";
    cin>>a;
    cout<<"Enter number of coins: ";
    cin>>n;
    vector<int> coin;
    cout<<"Enter coins\n";
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        coin.push_back(x);
    }
    cout<<"Minimum coins required are: "<<minCoins(a,coin);
    




    return 0;
}
