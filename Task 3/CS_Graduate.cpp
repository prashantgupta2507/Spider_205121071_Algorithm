#include <bits/stdc++.h>
using namespace std;

int build(int ind, int low, int high, int a[],int seg[])
{
    if(high==low)
        return seg[ind]=high;

    int mid = (low+high)/2;
    int left = build(2*ind+1,low,mid,a,seg);
    int right = build(2*ind+2,mid+1,high,a,seg);
    if(a[left]<a[right])
        return seg[ind]=left;
    else
        return seg[ind]=right;
     
}


int findmin(int ind,int low,int high,int l,int r,int seg[], int a[])
{
    //no overlap
    if(low>r||high<l)
        return -1;
    //complete overlap
    if(low>=l&&high<=r)
    {    
        return seg[ind];
    }
    int mid = (low+high)/2;
    int left = findmin(2*ind+1,low,mid,l,r,seg,a);
    int right = findmin(2*ind+2,mid+1,high,l,r,seg,a);
    
    if(left==-1)   //handling no overlap
    return right;
    else if(right==-1) //handling no overlap
    return left;

    if(a[left]<a[right])
    return left;
    else
    return right;
}

void update( int l,int r,int p[],int a[],int seg[], int curr,int n)
{
        
        if(l==r)
        {
            p[l]=curr;
            return;    
        }
        if(r<l||l<0||r>n)
        return;
        int ind = findmin(0,0,n-1,l,r,seg,a);
        p[ind]=curr;

        update(l,ind-1,p,a,seg,curr+1,n);
        update(ind+1,r,p,a,seg,curr+1,n);
}

int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],r[n];
        memset(r,-1,sizeof r);
        for(int i=0;i<n;i++)
            cin>>a[i];

        int seg[4*n];
        
        build(0,0,n-1,a,seg);
        update(0,n-1,r,a,seg,0,n);
                
        for(auto x:r)
            cout<<x<<" ";
        cout<<endl;
    } 
}

