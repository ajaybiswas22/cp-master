/*
You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.
Your task is to efficiently find out if you can empty both the piles.
Input
The first input line has an integer t: the number of tests.
After this, there are t lines, each of which has two integers a and b: the numbers of coins in the piles.
Output
For each test, print "YES" if you can empty the piles and "NO" otherwise.
Constraints

1 \le t \le 10^5
0 \le a, b \le 10^9

Example
Input:
3
2 1
2 2
3 3

Output:
YES
NO
YES
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool coin_piles(ll a,ll b)
{
    if(a < 0 || b < 0)
    {
        return false;
    }
    else if(a == 0 && b == 0)
    {
        return true;
    }
    else
    {
        return coin_piles(a-1,b-2) || coin_piles(a-2,b-1);
    }
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
    while(n--)
    {
        ll a,b;
        cin>>a>>b;
        if (coin_piles(a,b))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}