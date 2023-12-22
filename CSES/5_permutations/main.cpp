/*
A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.
Given n, construct a beautiful permutation if such a permutation exists.
Input
The only input line contains an integer n.
Output
Print a beautiful permutation of integers 1,2,\ldots,n. If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".
Constraints

1 \le n \le 10^6

Example 1
Input:
5

Output:
4 2 5 3 1
Example 2
Input:
3

Output:
NO SOLUTION
*/

#include<bits/stdc++.h>
using namespace std;

void permutations(int n)
{
    if (n  == 1)
        cout<<1;
    else if (n <= 3)
        cout<<"NO SOLUTION";
    else if (n == 4)
        cout<<"2 4 1 3";
    else
    {
        vector<int> A(n,0);

        for(int i=1, j= ((n%2)==0)?n:n-1, k=0; i <= n; i+=2,j-=2,k++)
        {
            A[k] = j;
            A[n-k-1] = i;
        }
        for(int i=0; i<n;i++)
        {
            cout<<A[i]<<" ";
        }
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
    int n;
    cin>>n;
    permutations(n);

    return 0;
}