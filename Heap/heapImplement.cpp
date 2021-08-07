#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void usingSTL()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(3);
    pq.push(23);
    pq.push(32);
    pq.push(13);
    pq.pop();
    cout << pq.top();
    cout << endl
         << pq.size();
    cout << endl
         << pq.empty();
}
void swap(int arr[], int &x, int &y)
{
    int t=arr[x];
    arr[x]=arr[y];
    arr[y]=t;
}

void insertHeap(int arr[], int n, int x)
{
    arr[n] = x;
    int parent = n / 2;
    if (parent < 1)
        return;

    while (n >= 1)
    {
        parent = n / 2;
        if (arr[n] > arr[parent])
        {
            swap(arr, n, parent);
            n = parent;
        }
        else
            break;
    }
}

int deleteHeap(int ar[], int &n)
{
    int x = ar[1];
    ar[1] = ar[n];
    n = n - 1;
    int largest = 1;
    while (largest <= n)
    {
        int left = largest * 2;
        int right = largest * 2 + 1;
        int bdaBeta = ar[left] > ar[right] ? left : right;
        if (ar[bdaBeta] > ar[largest])
        {
            swap(ar, bdaBeta, largest);
            largest = bdaBeta;
        }
        else
        break;
    }
    return x;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        insertHeap(arr, i, x);
    }
    cout << "-->>" << deleteHeap(arr, n) << endl;
    cout << "-->>" << deleteHeap(arr, n) << endl;
    cout << "-->>" << deleteHeap(arr, n) << endl;
    cout << "-->>" << deleteHeap(arr, n) << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
