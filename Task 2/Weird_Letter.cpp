// I have taken two pointers i and j. We are traversing target string with pointer j. 
// The poimter i to keep track of source string .
//When the charcters of both strings are same, increment i.
//if current chararcter of target string is not equal to source's current or previous char then we have to break with a result NO


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int tt;
    cin>>tt;
    while(tt--)
    {
        string s,t;
        int f=0,j=0;

        
        cin>>s>>t;
        if(s==t)
            f=1;
        else
        {    int i=0,l=s.size();
         
           for( j=0;j<t.size();j++)    
           {   
               if(i<l&&s[i]==t[j])     // if both  have same char
                i++;
           
               else if(s[i-1]!=t[j]) // not equal to current or prev
               {    f=-1;
                   break;
               }

           }
            if(f!=-1&&i==l) // source string reaches end
                 f=1;
        }
    
        if(f>0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
