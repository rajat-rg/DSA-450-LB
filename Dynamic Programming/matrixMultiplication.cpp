#include<iostream>

using namespace std;
int matrixMultiply(int m[], int i, int j) {
    if(i==j)return 0;
    int count=0;
    int min = INT_MAX;
    for (int k=i ; k<j; k++)
    {
        count = matrixMultiply(m,i,k)+matrixMultiply(m,k+1,j)+m[i-1]*m[k]*m[j];
        if(count< min) min= count;
    }
    return min;
    


}
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter number of matrix: ";
    cin>>n;
    int m[n+1];
    for (int i = 0; i < n+1; i++)
    {
        cin>>m[i];
    }
    cout<<"Operations required to multiply matrices are: "<<matrixMultiply(m,1,n);
    
    return 0;
}
