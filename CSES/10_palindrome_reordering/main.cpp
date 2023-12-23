/*
Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).
Input
The only input line has a string of length n consisting of characters A–Z.
Output
Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".
Constraints

1 \le n \le 10^6

Example
Input:
AAAACACBA

Output:
AACABACAA
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void palindrome_reorder(string str)
{
    vector<char> a;
    vector<char> b;
    map<char,ll> M;
    ll odds = 0;

    for (auto c : str)
    {
        M[c] = M[c] + 1;
    }

    for (auto m: M)
    {
        if(m.second % 2 == 1)
        {
            odds++;
        }
    }

    if(odds > 1)
    {
        cout<<"NO SOLUTION"<<endl;
        return;
    }

    for (auto m : M)
    {
        //cout<<"key:"<<m.first<<"val:"<<m.second<<endl;
        if(m.second % 2 == 1)
        {
            ll count = m.second;
            while(count--)
            {
                b.push_back(m.first);
            }
        }
        else
        {
            ll count = m.second / 2;
            while(count--)
            {
                a.push_back(m.first);
            }
        }
        
    }

    for (ll i=0;i<a.size();i++)
        cout<<a[i];
    for (ll i=0;i<b.size();i++)
        cout<<b[i];
    for (ll i=a.size()-1;i>=0;i--)
        cout<<a[i];

    cout<<endl;
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
    string str;
    cin>>str;
    palindrome_reorder(str);
    return 0;
}