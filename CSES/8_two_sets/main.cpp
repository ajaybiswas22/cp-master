/*
Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.
Input
The only input line contains an integer n.
Output
Print "YES", if the division is possible, and "NO" otherwise.
After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.
Constraints

1 \le n \le 10^6

Example 1
Input:
7

Output:
YES
4
1 2 4 7
3
3 5 6
Example 2
Input:
6

Output:
NO
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void two_sets(ll n) {

    ll sum = (n*(n+1))/2;

    if(sum % 2 == 1)
        cout<<"NO\n";
    else {
        cout<<"YES\n";

        vector<ll> set1, set2;

        ll sum2 = sum/2;
        ll n2 = n;
        int v=-1;
        while (sum2 >= 1)
        {
            sum2 = sum2 - n2;
            if(sum2 < 0) {
                v=sum2 + n2;
                set1.push_back(v);
                break;
            }
            else
            {
                set1.push_back(n2);
                n2--;
            }
        }
        while(n2>=1)
        {
            if(n2!=v){
            set2.push_back(n2);
            } 
         n2--;
        }

        cout<<set1.size()<<endl;
        for(int i=0;i<set1.size();i++)
            cout<<set1[i]<<" ";
        cout<<endl;
        cout<<set2.size()<<endl;
        for(int i=0;i<set2.size();i++)
            cout<<set2[i]<<" ";
        cout<<endl;


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
    two_sets(n);
    return 0;
}