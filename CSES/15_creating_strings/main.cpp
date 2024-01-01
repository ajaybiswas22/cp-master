/*
Given a string, your task is to generate all different strings that can be created using its characters.
Input
The only input line has a string of length n. Each character is between a–z.
Output
First print an integer k: the number of strings. Then print k lines: the strings in alphabetical order.
Constraints

1 \le n \le 8
Example
Input:

aabac
Output:

20
aaabc
aaacb
aabac
aabca
aacab
aacba
abaac
abaca
abcaa
acaab
acaba
acbaa
baaac
baaca
bacaa
bcaaa
caaab
caaba
cabaa
cbaaa

*/

#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;

vector<string> pattern(string str,ll n)
{
    if(n == 1)
    {
        vector<string> S;
        S.push_back(str);
        return S;
    }
    else
    {
        vector<string> k = pattern(str.substr(0,n-1),n-1);
        unordered_set<string> result;
        for(int i=0;i<k.size();i++)
        {
            
            for(int j=0;j<k[i].length();j++)
            {
                char c = str[n-1];
                string s = k[i].substr(0,j) + c + k[i].substr(j);
                result.insert(s);
            }
            char c=str[n-1];
             string s = k[i]+c;
             result.insert(s);

        }

        vector<string> P(result.begin(),result.end());
        return P;
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
    string str;
    cin>>str;

    vector<string> S = pattern(str,str.length());

    cout<<S.size()<<endl;
    sort(S.begin(),S.end());
    for(auto s: S)
    {
        cout<<s<<endl;
    }

    return 0;
}