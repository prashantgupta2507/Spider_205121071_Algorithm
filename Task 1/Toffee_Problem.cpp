// Toffee Problem
// In this problem, Ronny have to purchase toffees of different prices with some given money m. And to maximize the number of toffees to be purchased, Ronny prefer to purchase toffee with lower price.  
// Instead of sorting the input later, I have used multiset to get the prices in sorted order(multiset is used because two or more toffes may have same price).
// After getting the prices in sorted order, we will increment the purchased toffee count by one and reduce our money by the price of that toffee till we are left with no money.



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main() {
    multiset <int > prices;       

    int n,m,x,toffee_count=0; // m is the given money and n is the available toffees in the shop
    cin>>n>>m;          
    while(n--)
    {
        cin>>x;
        a.insert(x); // taken all the prices in set 
    }
    auto p=a.begin();
    
    while(m>0&&p!=a.end())
    {
        m-=*p;              //As the set is already sorted, we get the minimum price at first 
        p++;
        if(m<0)             //when we are left with no money or the current toffee price is greater than available money, we will break out
        break;   
        toffee_count++;
    }
    cout<<toffee_count;    // At the end we will print our final toffee count
    return 0;
}
