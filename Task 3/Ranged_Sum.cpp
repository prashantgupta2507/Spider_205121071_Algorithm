#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll build(ll ind, ll low, ll high, ll a[],ll seg[])
{
    if(high==low)
    {
        seg[ind]=a[high];
        return seg[ind];
    }
    ll mid = (low+high)/2;
    ll left = build(2*ind+1,low,mid,a,seg);
    ll right = build(2*ind+2,mid+1,high,a,seg);
    seg[ind]=left+right;
    return seg[ind];
}


ll query1(ll ind,ll i,ll low,ll high,ll val,ll seg[])
{
    //no overlap
    if(high<i||low>i)
        return seg[ind];

    if(high==low)
    {    
        if(high==i)
          seg[ind]=val;
        
        return seg[ind];
    }
    ll mid = (low+high)/2;
    ll left = query1(2*ind+1,i,low,mid,val,seg);
    ll right = query1(2*ind+2,i,mid+1,high,val,seg);
    seg[ind]=left+right;
    return seg[ind];
}


ll query2(ll ind,ll low,ll high,ll l,ll r,ll seg[])
{
    //no overlap
    if(low>r||high<l)
        return 0;
//complete overlap
    if(low>=l&&high<=r)
    {    
        return seg[ind];
    }
    ll mid = (low+high)/2;
    ll left = query2(2*ind+1,low,mid,l,r,seg);
    ll right = query2(2*ind+2,mid+1,high,l,r,seg);
    return left+right;
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    ll n,q;
    cin>>n>>q;
    ll a[n],seg[4*n];
    for(auto &x:a)
        cin>>x;
    build(0,0,n-1,a,seg);

    while(q--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll i,val;
            cin>>i>>val;
            query1(0,i-1,0,n-1,val,seg);
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            cout<<query2(0,0,n-1,l-1,r-1,seg)<<endl;    
        }
    }
    return 0;
}
