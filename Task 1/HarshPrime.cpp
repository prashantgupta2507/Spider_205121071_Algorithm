// HARSHPRIME
// In this problem, we are given with two integers n and x. We have count the pairs of neighbouring prime numbers upto n whose sum +1 is also a prime number. We have to find whether the count of these pairs is greater than or equal to x or not and print YES and NO accordingly 

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    int n,x,a=0;
    cin>>n>>x;
    vector<int> v;
  
    for(int i=2;i<=n;i++)  
    {
        int k=(int)sqrt(i);
        bool p=1;
        for(int j=2;j<=k;j++)
        {
            if (i%j==0)
            {
                p=0;
                break;
            }
        }
        if(p)
            v.emplace_back(i);    // Storing Prime numbers upto n in the vector v
    }
    int l=v.size();
    l--;
    for(int i=0;i<l;i++)
    {
       int k = (v[i]+v[i+1]+1);      //  adding neighbouring prime numbers +1
        auto it=find(v.begin(),v.end(),k);   // check if that sum is prime or not
            if(it!=v.end())
                a++;                //counting the prime pairs
    }
    if (a>=x)               // if count exceeds x print YES else NO
        cout<<"YES\n";
    else 
        cout<<"NO\n";    
    return 0;
}
