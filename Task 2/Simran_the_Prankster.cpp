// I have tried all the possible combination via Recursion and whenever we got our desired answer then break and print YES else NO


#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;


bool calculate(ll a[],ll i,ll d,ll n,ll r)
{

if(r==d)     // Best Case 
    return true;
if(i==n)      // Base Case
    return false;
if(calculate(a,i+1,d,n,r+a[i])) // addition
    return true;
if(calculate(a,i+1,d,n,r-a[i]))   // Substraction
    return true;
if(calculate(a,i+1,d,n,r*a[i]))    // Multipplication
    return true;
if(calculate(a,i+1,d,n,r/a[i]))  // Division
    return true;

return false;         
}

int main() {
ll n,d,r,tt;
cin>>tt;
while(tt--)
{
    cin>>n>>d;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    r=a[0];

    if(calculate(a,1,d,n,r))
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
return 0;
}