/*
Your task is to count for k=1,2,\ldots,n the number of ways two knights can be placed on a k \times k chessboard so that they do not attack each other.
Input
The only input line contains an integer n.
Output
Print n integers: the results.
Constraints

1 \le n \le 10000

Example
Input:
8

Output:
0
6
28
96
252
550
1056
1848
*/

#include<bits/stdc++.h>
using namespace std;

long long fact(long long n){
    if(n==0) return 1;
    if (n>0) return n*fact(n-1);
};

long long NCR(long long n,int r){
    if(n==r) return 1;
    if (r==0&&n!=0) return 1;
    else return (n*fact(n-1))/fact(n-1)*fact(n-r);
};

long long two_knight(long long n)
{
    if(n == 1)
        return 0;
    else if(n == 2)
        return 6;
    
    long long X[4][2] = { 
        {1, 2}, 
        {-1, 2},
        {2, 1},
        {-2, 1}
    }; 

    long long count = 0;
    vector<vector<long long> > A(n,vector<long long> (n,0)); 
    for (long long a_i = 0; a_i< n; a_i++)
    {
        for (long long a_j=0;a_j< n;a_j++)
        {
            long long b_i, b_j;
            for (auto pos : X)
            {
                b_i = a_i + pos[0];
                b_j = a_j + pos[1];

                if(b_i < 0 || b_j < 0 || b_i >= n || b_j >= n )
                {

                }
                else
                {
                    if(A[b_i][b_j] == 0) {
                    //cout<<"x:"<<b_i<<"y:"<<b_j<<endl;
                        count++;
                        A[b_i][b_j] = 1;
                    }
                }
            }
        }
    }

    return NCR(n,2) - count;
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
    long long n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cout<<two_knight(i)<<endl;
    }

    return 0;
}