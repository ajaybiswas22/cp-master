#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;

bool is_valid(vector<vector<char> > A,int i,int j,int count)
{

    if (count == 8)
        return true;

    if(i>7 || j>7)
        return false;
    
    if(A[i][j] == '*')
        return false;

    // horizontal and vertical
    for(int x=0;x<8;x++)
    {
        if(x!=j && A[i][x] == 'Q')
            return false;

        if(x!=i && A[x][i] == 'Q')
            return false;
    }

    // diagonal
    int a=i-1, b=j-1;

    while(a>=0 && b>=0)
    {
        if(A[a][b] == 'Q')
            return false;
        a--;
        b--;
    }

    a=i-1;
    b=j+1;

    while(a>=0 && b<=7)
    {
        if(A[a][b] == 'Q')
            return false;
        a--;
        b++;
    }

    A[i][j] = 'Q';
    cout<<"i:"<<i<<"j:"<<j<<endl;
    return is_valid(A,i,j+1,count++) || is_valid(A,i+1,j,count++);
}

int ways(vector<vector<char> > A)
{
    vector<vector<char> > B = A;
    vector<vector<int> > pos;

    int count=0;
    int ways = 0;
    int i=0,j=0;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            count = count + is_valid(B,i,j,0);
            cout<<endl;
        }
    }
    return count;
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

    vector<vector<char> > A;
    
    for(int i=0;i<8;i++)
    {
            string row;
            cin>>row;
            vector<char> r(row.begin(),row.end());
            A.push_back(r);
    }
    cout<<ways(A);

    return 0;
}