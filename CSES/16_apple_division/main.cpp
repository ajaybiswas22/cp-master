/*
There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.
Input
The first input line has an integer n: the number of apples.
The next line has n integers p_1,p_2,\dots,p_n: the weight of each apple.
Output
Print one integer: the minimum difference between the weights of the groups.
Constraints

1 \le n \le 20
1 \le p_i \le 10^9

Example
Input:
5
3 2 7 4 1

Output:
1

Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).
*/

#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;

ll subset(vector<ll> arr,ll currsum,ll totalsum,ll i){
    if (i==0)
        return abs((totalsum-currsum) - currsum);

        return min(subset(arr,currsum+arr[i],totalsum,i-1),subset(arr,currsum,totalsum,i-1));

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
    vector<ll> weights;
    ll t_sum = 0;
    while(n--)
    {
        ll w;
        cin>>w;
        weights.push_back(w);
        t_sum += w;
    }

    cout<<subset(weights,0,t_sum,weights.size()-1)<<endl;

    return 0;
}