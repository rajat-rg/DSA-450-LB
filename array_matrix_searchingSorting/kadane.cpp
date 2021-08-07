#include <iostream>
using namespace std;
//Maximum sum subarray** kadane's algorithmm
int kadane(int a[], int count)
{
    int max_count = 0;
    int cur_count = 0;
    for (int i = 0; i < count; i++)
    {
        cur_count += a[i];
        if (cur_count > max_count)
            max_count = cur_count;

        if (cur_count < 0)
            cur_count = 0;
    }
    return max_count;
}

int main(int argc, char const *argv[])
{
    int count;
    cin >> count;
    cout << "++" << endl;
    int a[count];
    for (int i = 0; i < count; i++)
    {
        cin >> a[i];
        /* code */
    }
    int ans = kadane(a, count);
    cout<<endl<<ans;
    return 0;
}
