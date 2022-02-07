#include <bits/stdc++.h>
#define modi 1000000007
#define ll long long
using namespace std;

int steps(unordered_map<int,int> m,int i,int e,ll dp[])
{
    if(m[i]==1||i>e)
        return 0;
    if(i==e)
        return dp[i]=1;
    if(dp[i]!=-1)
        return dp[i];

    ll one=steps(m,i+1,e,dp);        
    ll two=steps(m,i+2,e,dp);        
    dp[i]=(one+two);
    dp[i]%=modi;
    return dp[i];
}
int main()
{
    ll n,k,x;
    cin>>n>>k;

    ll dp[n];
    memset(dp,-1,sizeof dp);
    
    unordered_map<int,int> m;    
    for(int i=0;i<k;i++)
    {
        cin>>x;
        m[x]=1;
    }    
    cout<<steps(m,0,n,dp);

return 0;
}            