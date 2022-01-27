// I have stored the no. of upward and downward triangles of previous state to compute the upward  and downward triangle in current state

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define mod 1000000007 
using namespace std;


int main() {
   long long n;
    cin>>n;
   long long u0=0,d0=0,u1=0,d1=0; 
    u0=1;    // Initial Previous State
    d0=0;
    
    for(int i=1;i<=n;i++)
    {
        u1=u0*3;    // calculating current upward triangle with help of previous upward and downward triangle
        u1+=d0;
        d1=u0;
        d1+=d0*3;
        u0=u1%mod;   
        d0=d1%mod;
    }  
    cout<<u0;
    return 0;
}