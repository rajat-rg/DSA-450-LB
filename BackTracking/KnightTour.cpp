#include<iostream>
#include<vector>
using namespace std;

void displayBoard(vector<vector<int>> board)
{
    for(int i=0;i<board.size(); i++)
    {
        for(int j=0; j<board.size();j++)
        cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void knightTour(vector<vector<int>> &chess, int r, int c, int move)
{
    if (r<0 or c< 0 or r>= chess.size() or c >= chess.size() or chess[r][c] >0)return;
    if(move == chess.size()* chess.size())
    {
        chess[r][c]=move;
        displayBoard(chess);
        chess[r][c]=0;
        return;
    }
    // cout<<"> ";
    chess[r][c] = move;
    knightTour(chess, r-2 , c+1, move+1);
    knightTour(chess, r-2 , c-1, move+1);
    knightTour(chess, r+2 , c+1, move+1);
    knightTour(chess, r+2 , c-1, move+1);
    knightTour(chess, r+1 , c+2, move+1);
    knightTour(chess, r+1 , c-2, move+1);
    knightTour(chess, r-1 , c+2, move+1);
    knightTour(chess, r-1 , c-2, move+1);
    chess[r][c]=0;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> chess(n, vector<int>(n,0));

    knightTour(chess,0,0,1);

}