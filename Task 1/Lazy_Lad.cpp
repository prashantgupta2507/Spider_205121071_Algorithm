// LAZY LAD
// In this problem, we are given some N and for each N we have to find the number of levels of increasing numbers can created using these N like 1,2,3,4,....
// As we know that sum of this series is given by x*(x+1)/2 and it is already given to us in N. 
// We have to find the x by solving the equation x*(x+1)/2 = N
// I have used the quadratic formula to solve the equation.
// x is our final answer. 

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long cal(long long y)  // function to calculate the equation and find the y
{
    y*=8;
    y++;
    long long p=sqrt(y);   
        p--;                 
    return p/2;                 // FORMULA USED  x=(-1+sqrt(1+8*N))/2
    
}

int main() {
    long long q;
    cin>>q;
    long long y;
        for(int i=0;i<q;i++)
        {
            cin>>y;                     // TAKING INPUT OF EACH N
            cout<<cal(y)<<"\n";         // SOLVING EQUATION FOR EACH N and printing the result
        }
        
    return 0;
}
