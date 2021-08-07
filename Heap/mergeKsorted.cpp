#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(int argc, const char** argv) {
    int k;
    cin>>k;

    int arr[][k] = {{1,2,3,4},{2,3,4,5},{2,7,8,9}};
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> p;
    vector<int> idx(k,0);
    vector<int> ans;
    for(int i=0;i<k;i++)
    p.push(make_pair(i, 0));
    while(!p.empty())
    {   
        pair<int,int> x = p.top();
        p.pop();
        ans.push_back(arr[x.first][idx[x.first]]);
        idx[x.first]++;
        if(idx[x.first] <4 )
        p.push(make_pair(x.first, x.first));
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
        
    }




    return 0;
}