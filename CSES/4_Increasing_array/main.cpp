/*
You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
On each move, you may increase the value of any element by one. What is the minimum number of moves required?
Input
The first input line contains an integer n: the size of the array.
Then, the second line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Print the minimum number of moves.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9

Example
Input:
5
3 2 5 1 7

Output:
5
*/

#include<bits/stdc++.h>
using namespace std;

unsigned long long increasing(vector<long long> A)
{
    unsigned long long moves = 0;
    for(unsigned long int i=1;i<A.size();i++)
    {
        if(A[i] < A[i-1])
        {
            moves = moves + (A[i-1] - A[i]);
            A[i] = A[i-1];
        }
    }
    return moves;
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
    vector<long long> A;
    while(n--)
    {
        long long int k;
        cin>>k;
        A.push_back(k);
    }
    cout<<increasing(A);

    return 0;
}