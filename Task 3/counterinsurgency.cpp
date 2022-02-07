#include <bits/stdc++.h>

using namespace std;

int arrange(int a[], int low, int high)
{
    if(low==high)
        return (a[low]%low==0||low%a[low]==0)? 1:0;  //checking last elemenyt

    int c=0;
    for(int i=low;i<=high;i++)
    {    
        swap(a[i],a[low]);
        if(a[low]%low==0||low%a[low]==0)    //if swapping lead to correct arrangement
        c+=arrange(a,low+1,high);
        swap(a[i],a[low]);
    }    
    
    return c;    
}

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<=n;i++)
        a[i]=i;
    cout<<arrange(a,1,n);
return 0;
}
