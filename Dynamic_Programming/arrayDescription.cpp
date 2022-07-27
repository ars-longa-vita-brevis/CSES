#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;
const int mod = 1e9+7;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> values(n);
    for(int i = 0; i < n; i++)
        cin >> values[i];
    vector<vector<ll>> numberOfArrays(n,vector<ll>(m+1,0));
    if (values[0] != 0)
        numberOfArrays[0][values[0]] = 1;
    else
        for(int i = 1; i <= m; i++)
            numberOfArrays[0][i] = 1;
    for(int i = 1; i < n; i++)
    {
        if (values[i] == 0)
        {
            for(int j = 1; j<= m; j++)
            {
                if (j-1 >= 1)
                    numberOfArrays[i][j] = (numberOfArrays[i][j] + numberOfArrays[i-1][j-1])%mod;
                numberOfArrays[i][j] = (numberOfArrays[i][j] + numberOfArrays[i-1][j])%mod;
                if (j+1 <= m)
                    numberOfArrays[i][j] = (numberOfArrays[i][j] + numberOfArrays[i-1][j+1])%mod;
            }
        }
        else
        {
            if (values[i]-1 >= 1)
                numberOfArrays[i][values[i]] = (numberOfArrays[i][values[i]] + numberOfArrays[i-1][values[i]-1])%mod;
            numberOfArrays[i][values[i]] = (numberOfArrays[i][values[i]] + numberOfArrays[i-1][values[i]])%mod;
            if (values[i]+1 <= m)
                numberOfArrays[i][values[i]] = (numberOfArrays[i][values[i]] + numberOfArrays[i-1][values[i]+1])%mod;
        }
    }
    ll totalNumberOfArrays = 0;
    for(int i = 1; i <= m; i++)
        totalNumberOfArrays = (totalNumberOfArrays + numberOfArrays[n-1][i]) % mod;
    cout << totalNumberOfArrays;
}
