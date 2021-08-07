// A and B are playing a game. At the beginning there are n coins. Given two more numbers x and y.
// In each move a player can pick x or y or 1 coins. A always starts the game. The player who picks the last coin wins the game or the person who is not able to pick any coin loses the game. 
// For a given value of n, find whether A will win the game or not if both are playing optimally.

#include <iostream>
using namespace std;
bool dp[500];
void coinPicking(int n, int x, int y)
{

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {

        if ((i - 1 >= 0 and !dp[i - 1] )or (i - x >= 0 and !dp[i - x] ) or (i - y >= 0 and !dp[i - y] )) 
            dp[i] = 1;
        else
            dp[i] = 0;
    }
    cout << dp[n];
}

int main(int argc, char const *argv[])
{
    int n, x, y;
    cout << "Enter number of coins: ";
    cin >> n;
    cout << "Enter X and Y: ";
    cin >> x >> y;
    coinPicking(n, x, y);
    return 0;
}
