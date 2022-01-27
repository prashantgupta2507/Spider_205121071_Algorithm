// I have converted the given input tree in an complete binary tree to access each node and its chid via indexes
// For conversion into complete binary tree, I have stored -1 in place of left and right nodes of leaf nodes or NULL nodes
// Initialized the whole array to -2 to avoid segmentation faults because we are accessing child nodes(2*i+1 and 2*i+2 )

#include <bits/stdc++.h>
using namespace std;

int sum=0;   //this sum variable is storing the current sum in our recursion

void traverse(vector<int> a,vector<int> &r,int i,int d,int &sum)
{
    
   r.push_back(a[i]);    // storing the traversals in r vector
   sum+=a[i];      // adding node value to current sum
    
    if(sum==d&&a[i*2+1]<0&&a[i*2+2]<0)  // if we get our desired sum, printing the nodes
    {
        for(auto x:r)
            cout<<x<<" ";
        cout<<endl;
    }
    

        if(a[i*2+1]>=0)
        {  
             traverse(a,r,i*2+1,d,sum);
            sum-=a[i*2+1];
            r.pop_back();
        }

        if(a[i*2+2]>=0)
        {
             
            traverse(a,r,i*2+2,d,sum); 
            sum-=a[i*2+2];
            r.pop_back();
        }
}    
int main() {
    int n,d,t,k=0,sum=0;
    vector<int> r,a(30009,-2);
    cin>>n;    // count of valid nodes
    int i=0;
    while(1)
    {
        
        cin>>t;    // current node value
        while(a[i]==-1)
            i++;
        a[i]=t;     
        if(t>0)      // if its a valid value then increment k counter by 1      
            k++; 
        else
        {
            a[i*2+1]=-1;
            a[i*2+2]=-1;
        }
        if(k==n+1)     // If we got the desired number of nodes, next input is our desired sum d.
            {
                d=t;    
                a[i]=-1;
                break;
            }
            i++;
    }
    traverse(a,r,0,d,sum);
    return 0;
}