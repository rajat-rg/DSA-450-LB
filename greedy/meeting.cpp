#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

void maxMeetings(vector<pair<int,int>> m)
{
    sort(m.begin(), m.end(),sortbysec);
    int start=0,count=0;
    for (int i = 0; i < m.size(); i++)
    {
        if(start<m[i].first)
        {
            count++;
            start = m[i].second;
            cout<<i+1<<" ";
        }        
    }
}


int main(int argc, char const *argv[])
{
    int n;
    int s,f;
    vector<pair<int,int>> m;
    cout<<"Enter number of meetings: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter starting time of meeting: ";
        cin>>s;
        cout<<"Enter ending time of meeting: ";
        cin>>f;

        m.push_back(make_pair(s,f));
    }
    maxMeetings(m);    
    return 0;
}
