#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,b,k,t,swaps=0;
    cout<<"Enter number of chicks: ";
    cin>>n;
    cout<<"Enter number K: ";cin>>k;
    cout<<"Enter barn distance: ";cin>>b;
    cout<<"Enter maximum time: ";cin>>t;
    int v[n];
    int x[n];

    cout<<"Enter position of chicks: \n";
    for (int i = 0; i < n; i++)
    {
        cin>>x[i];
    }
    

    cout<<"Enter speed of chicks: \n";
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

        int s=0;
    for (int i = 0; i < n-1; i++)
    {
        s=0;
        for (int j = i+1; j < n; j++)
        {
            //swap
        
            if(v[i]> v[j])
            {
                s=1;
                swap(v[i], v[j]);
                swap(x[i], x[j]);
            }
            
        }
        if(s==1)
        swaps++;
        
    }

cout<<"\nposition of chicks: \n";
    for (int i = 0; i < n; i++)
    {
        cout<<x[i]<<" ";
    }cout<<endl;
    

    cout<<"Enter speed of chicks: \n";
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }cout<<endl;
    for (int i = n-1; i >=0; i--)
    {
        if((v[i]*t) + x[i] >= b)
        {
            cout<<"--"<<(v[i]*t)+x[i]<<endl;
            k--;
        }
        /* code */
    }

    if(k<=0)
    cout<<k<<"ho gya akhir kaar\n"; 
    else
    cout<<k<<"lmao\n";   
    
    swaps = min(swaps,k);
    cout<<"swaps itne hue hai: "<<swaps;







    return 0;
}
