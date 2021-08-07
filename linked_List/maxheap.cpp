#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}
void heapify(int a[], int n, int i)
{
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int largest = i;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {

        swap(a[i], a[largest]);

        heapify(a, n, largest);
    }
}

// 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17
// 17 15 13 9 6 5 10 4 8 3 1

void maxHeap(int a[], int n)
{

    int l = (n / 2) - 1;
    for (int i = l; i >= 0; i--)
        heapify(a, n, i);
}



void printHeap(int arr[], int n)
{
    cout << "Array representation of Heap is:\n";
  
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter size\n";
    cin >> n;
    cout << "Enter array\n";
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    maxHeap(a, n);
printHeap(a,n);
    return 0;
}
