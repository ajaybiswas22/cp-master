/*Your task is to calculate the number of bit strings of length n.
For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.
Input
The only input line has an integer n.
Output
Print the result modulo 10^9+7.
Constraints

1 \le n \le 10^6

Example
Input:
3

Output:
8
*/

#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;

#define mode 1000000007
ull bit_string(ll n)
{
    ull ans=1;
   for(ull i=1;i<=n;i++){
    ans=(ans*2)%mode;
   }
   return ans;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    cout<<bit_string(n)<<endl;
    return 0;
}