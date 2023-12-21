/*
You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.
Input
The only input line contains a string of n characters.
Output
Print one integer: the length of the longest repetition.
Constraints

1 \le n \le 10^6

Example
Input:
ATTCGGGA

Output:
3
*/

#include<bits/stdc++.h>
using namespace std;

int repitition(string str)
{
    vector<int> A(26,0);
    int max = 1;
    int i=0,j=1;
    int count = 1;

    while(j<=str.length())
    {
        if (count > max)
        {
            max = count;
        }

        if(j == str.length())
            break;

        if(str[i] == str[j])
        {
            count++;
            j++;
        }
        else
        {
            count=1;
            i=j;
            j++;
        }
    }
    return max;

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
    cout<<repitition(str);

    return 0;
}