#include <iostream>
#include<string.h>
using namespace std;

void revString(char a[],int n)
{
    int i=0,j=n-1;
    while(i<j)
    {
        char t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;j--;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<a[i];
        /* code */
    }cout<<endl;
    

}
void palindrome(char a[], int n)
{
    int i=0,j=n-1;
    while(i<j)
    {
        if(a[i] != a[j])
        {
            cout<<"Not palindrome!";
            return;
        }
        else
        {
            i++;
            j--;
        }
    }
    cout<<"palindrome !";
}
int main(int argc, char const *argv[])
{
    cout << "++" << endl;
    char a[100];
    gets(a);
    int count = strlen(a);
    revString(a,count);
    palindrome(a,count);
    return 0;
}
