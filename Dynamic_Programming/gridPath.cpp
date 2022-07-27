#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;
const int mod = 1e9+7;

int main()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n ; i++)
        cin >> grid[i];
    vector< vector<ll> > numberOfPaths(n,vector<ll>(n,0));
    numberOfPaths[0][0] = (grid[0][0] == '.');
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (grid[i][j] != '*')
            {
                if (i-1 >= 0 && grid[i-1][j] != '*')
                    numberOfPaths[i][j] =
                        (numberOfPaths[i][j]+numberOfPaths[i-1][j])% mod;
                if (j-1 >= 0 && grid[i][j-1] != '*')
                    numberOfPaths[i][j] =
                        (numberOfPaths[i][j]+numberOfPaths[i][j-1])% mod;
            }   
        }
    }
    cout << numberOfPaths[n-1][n-1];
}
