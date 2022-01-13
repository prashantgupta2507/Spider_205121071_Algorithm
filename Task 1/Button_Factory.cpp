// Button Factory
// In this problem, we are given four integers p,q,r,s. Alice's button is kept pressed from p seconds to q seconds and Bob's button is kept pressed from r seconds to s seconds. We have to count the seconds when both the buttons are pressed simultaneously.

// In a simple manner, we just have to print the elements in the common region of the intervals [p,q] and [r,s]


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int p,q,r,s,ans=0;
    cin>>p>>q>>r>>s;
    
    int l=max(p,r);   //taking lower bound of common region
    int u=min(q,s);    //taking upper bound of common region     
    ans=u-l;
    
    if(ans<0)           //for NO COMMON REIGON
        ans=0;

    cout<<ans;
    return 0;
}
