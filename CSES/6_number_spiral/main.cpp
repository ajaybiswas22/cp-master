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

long long spiral(long long y, long long x)
{

    // even row: square y right decreasing, y moves
    // odd row: square y + 1 right increasing, y + 1 moves

    // odd column: square x right decreasing, x moves
    // odd col: sq x + 1 right increasing, x + 1 moves
    long long value = 0;

    if (y%2 == 0 && x<=y)
    {
        value = y*y - x + 1;
    }
    else if(y%2 == 1 && x <= y)
    {
        value = (y-1)*(y-1) + 1 + x - 1;
    }
    else if (x%2 == 1 && y<=x)
    {
        value = x*x - y + 1;
    }
    else if(x%2 == 0 && y <= x)
    {
        value = (x-1)*(x-1) + 1 + y - 1;
    }

    return value;
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
    for (int i=0;i<n;i++)
    {
        long long y,x;  
        cin>>y>>x;
        cout<<spiral(y,x)<<endl;
    }

    return 0;
}