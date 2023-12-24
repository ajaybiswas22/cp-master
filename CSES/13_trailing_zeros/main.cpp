/*
Your task is to calculate the number of trailing zeros in the factorial n!.
For example, 20!=2432902008176640000 and it has 4 trailing zeros.
Input
The only input line has an integer n.
Output
Print the number of trailing zeros in n!.
Constraints

1 \le n \le 10^9

Example
Input:
20

Output:
4
*/

#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;

ll zeros(ll n)
{
  ll five_p = 5;
  ll count = 0;

  while(floor(n/five_p) != 0)
  {
    count = count + n/five_p;
    five_p*=5;
  }
  return count;
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
    cout<<zeros(n)<<endl;
    return 0;
}