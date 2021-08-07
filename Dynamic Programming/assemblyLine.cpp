#include <iostream>
using namespace std;
int s=100;

int min(int a,int b) {
    return (a<b)?a:b;
}
int gadiBanao(int a[][100], int t[][100], int e[], int ex[])
{
    int t1[s]; 
    int t2[s];

    t1[0] = e[0]+ a[0][0]; 
    t2[0] = e[1]+ a[1][0];
    for (int i = 1; i < s; i++)
    {
        t1[i] = min(t1[i-1]+ a[0][i], t2[i-1]+t[1][i]+a[1][i]);
        t2[i] = min(t2[i-1]+ a[1][i], t1[i-1]+t[0][i]+a[0][i]);
        /* code */
    }

    return min(t1[s-1]+ex[0], t2[s-1]+ex[1]);
     



}

int main(int argc, char const *argv[])
{
    int a[2][100];
    int t[2][100];
    int e[2], ex[2];
    cout << "Enter number of services: ";
    cin >> s;
    cout << "Enter entry and exit times: ";
    cin >> e[0];
    cin >> ex[0];
    cin >> e[1];
    cin >> ex[1];
    for (int j = 0; j < 2; j++)
    {
        /* code */

        cout << "Enter the service time and change time for " << j + 1 << " : ";
        for (int i = 0; i < s; i++)
        {
            cin >> a[j][i];
            cin >> t[j][i];
            /* code */
        }
    }
    int time = gadiBanao(a,t,e,ex);
    cout<<"\nDekho bhaiya itna time to lgega hi vrna khi or se krva lo: "<<time;
    return 0;
}

// int a[][NUM_STATION] = {{4, 5, 3, 2},
//                             {2, 10, 1, 4}};
//     int t[][NUM_STATION] = {{0, 7, 4, 5},
//                             {0, 9, 2, 8}};
//     int e[] = {10, 12}, x[] = {18, 7};
 
