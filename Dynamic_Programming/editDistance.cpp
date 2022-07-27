#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
#define INF 1e9
typedef long long ll;

const int nax = 5005;

int minMoves[nax][nax];

int main()
{
	string str,ptr;
	cin >> str >> ptr;
    for (int i = 0; i < ptr.length()+1; i++)
        minMoves[0][i] = i;
    for (int i = 0; i < str.length()+1; i++)
        minMoves[i][0] = i;
    for(int i = 1; i < str.length() + 1; i++)
    {
        for(int j = 1; j < ptr.length() + 1; j++)
        {
            minMoves[i][j] = INF;
            minMoves[i][j] = min({minMoves[i-1][j-1] +(str[i-1] != ptr[j-1]), 
                                  minMoves[i-1][j]+1, 
                                  minMoves[i][j-1]+1});
        }
    }
    cout << minMoves[str.length()][ptr.length()];
}
