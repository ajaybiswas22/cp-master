/*
The Tower of Hanoi game consists of three stacks (left, middle and right) and n round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom. 
The goal is to move all the disks to the right stack using the middle stack. On each move you can move the uppermost disk from a stack to another stack. In addition, it is not allowed to place a larger disk on a smaller disk.
Your task is to find a solution that minimizes the number of moves.
Input
The only input line has an integer n: the number of disks.
Output
First print an integer k: the minimum number of moves.
After this, print k lines that describe the moves. Each line has two integers a and b: you move a disk from stack a to stack b.
Constraints

1 \le n \le 16

Example
Input:
2

Output:
3
1 2
1 3
2 3
*/

#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;

void hanoi(vector<string> &h,int n, int start, int end)
{
    if(n==1)
    {
        h.push_back(to_string(start)+" "+to_string(end));
        return;
    }
    int other = 6 - (start + end);
    hanoi(h,n-1,start,other);
    h.push_back(to_string(start)+" "+to_string(end));
    hanoi(h,n-1,other,end);
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
    vector<string> h;
    hanoi(h,n,1,3);
    cout<<h.size()<<endl;
    for(auto s: h)
    {
        cout<<s<<endl;
    }
    return 0;
}