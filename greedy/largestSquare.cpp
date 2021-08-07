#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n=6, m=5, max = 0;
    int s[n][m];
    int mat[n][m] = {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};;
    // uncomment this code to read input from user XD
    // cout << "Enter rows and columns :";
    // cin >> n >> m;
    // int mat[n][m];
    // cout << "Fill marix of 0 and 1\n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cin >> mat[i][j];
    //     }
    // }

    for (int i = 0; i < n; i++)
        s[i][0] = mat[i][0];
    for (int i = 0; i < m; i++)
        s[0][i] = mat[0][i];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (mat[i][j] == 1)
            {

                s[i][j] = min(s[i][j - 1], min(s[i - 1][j], s[i - 1][j - 1])) + 1;
                if (s[i][j] > max)
                    max = s[i][j];
            }
            else
                s[i][j] = 0;
        }
    }
    cout<<"Maximum size of matrix of 1 is :"<<max;
    return 0;
}
