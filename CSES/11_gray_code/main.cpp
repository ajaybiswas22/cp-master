/*
A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
Your task is to create a Gray code for a given length n.
Input
The only input line has an integer n.
Output
Print 2^n lines that describe the Gray code. You can print any valid solution.
Constraints

1 \le n \le 16

Example
Input:
2

Output:
00
01
11
10
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<string> magic(ll n)
{
    if(n==1)
    {
        vector<string> s;
        s.push_back("0");
        s.push_back("1");
        return s;
    }
    else
    {
        vector<string> k = magic(n-1);
        vector<string> k2;
        int alternate = 0;

        for(ll i=0; i<k.size();i++)
        {
            vector<string> s2 {"0","1"};
            for(ll j=0; j<2; j++)
            {
                if(alternate == 0)
                {
                    k2.push_back(s2[j]+k[i]);
                }
                else
                {
                    k2.push_back(s2[1-j]+k[i]);
                }
                
            }
            
            if(alternate == 0)
                alternate = 1;
            else
                alternate = 0;
        }

        return k2;

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
    vector<string> S = magic(n);

    for(auto s: S)
    {
        cout<<s<<endl;
    }
    return 0;
}