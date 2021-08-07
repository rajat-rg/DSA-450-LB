#include<iostream>
#include<climits>
using namespace std;
bool isPossible(int a[], int n, int m,  int min)
{
    int studentRequired = 1, sum=0;

    for (int i = 0; i < n; i++)
    {
        if(a[i] > min)
        return false;

        if(sum + a[i] > min)
        {
            studentRequired++;
            sum = a[i];
        }
        if(studentRequired > m)
        return false;
        else
        sum+= a[i];
    }
    return true;
    
}

int minimumBookAllocation(int a[], int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        /* code */
    }

    int start = 0, end = sum;
    int mid,ans=INT_MAX;
    while(start < end)    
    {
        mid = (start + end)/2;
        if(isPossible(a,n,m,mid))
        {
            ans = min(ans, mid);

        end = mid -1;
        }
        else
        start = mid+1;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n,m;
    cout<<"Enter number of books\n";
    cin>>n;
    int a[n];
    cout<<"Enter number of students\n";
    cin>>m;
    cout<<"Enter number of pages in books\n";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    cout<<minimumBookAllocation(a,n,m);

    

    return 0;
}
