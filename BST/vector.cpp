#include<iostream>
#include<vector>

using namespace std;


void push(vector<int> &v)
{
    int n,num;
    cout<<"Enter number"<<endl;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>num;
        v.push_back(num);
        /* code */
    }
    
}
void print(vector<int> v)
{
    vector<int>::iterator it;
    for(int i=0; i<v.size();i++)
    {
        cout<<v[i];
    }
}

int main(int argc, char const *argv[])
{
    vector<int> v;
    push(v);
    print(v);
    return 0;
}
