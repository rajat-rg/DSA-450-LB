#include <iostream>
#include <queue>
using namespace std;

int kLargest(int a[], int n, int k)
{
    int sum[n + 1];
    int s;
    sum[0] = 0;
    sum[1] = a[0];
    for (int i = 2; i <= n; i++)
    {
        s = 0;

        for (int j = i; j <= n; j++)
        {
            s += a[j];
        }
        sum[i] = s;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int mx = sum[j] - sum[i - 1];
            if (pq.size() < k)
            {
                pq.push(mx);
            }
            else
            {
                if (mx > pq.top())
                {
                    pq.pop();
                    pq.push(mx);
                }
            }

            /* code */
        }
        /* code */
    }
    return pq.top();
}
int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int num = kLargest(a, n, k);
    cout<<"num: "<<num<<endl;
    return 0;
}
