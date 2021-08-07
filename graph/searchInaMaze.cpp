#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> ans;

void dfs(int i, int j, int m[100][100], int n, vector<vector<int>> vis, string s)
{
    if(i<0 or j<0 or i>n or j>n)return;
    if(m[i][j] ==0 or vis[i][j]==1)return;

    if(i==n-1 and j==n-1)
    {
        ans.push_back(s);
        return;
    }
    vis[i][j] =1;
    dfs(i-1, j, m, n,vis,s+'U');
    dfs(i, j-1, m, n,vis,s+'L');
    dfs(i+1, j, m, n,vis,s+'D');
    dfs(i, j+1, m, n,vis,s+'R');

    vis[i][j]=0;

}
void searchInMaze(int m[100][100], int n)
{
    if(m[0][0] ==0 or m[n-1][n-1]==0)return;
 
    string s = "";
    vector<vector<int>> vis(100, vector<int>(100));
    dfs(0,0,m,n,vis, s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
        /* code */
    }
    
}
int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;
    cout<<"Enter matrix: ";
    int m[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            cin>>m[i][j];
            /* code */
        }
        
        /* code */
    }
    
    searchInMaze(m, n);

    return 0;

}