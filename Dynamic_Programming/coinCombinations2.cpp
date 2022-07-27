#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;
const int mod = 1e9+7;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++)
        cin >> coins[i];
    vector<ll> numberOfCombinations(x+1,0);
    numberOfCombinations[0] = 1;
    for(int j = 0; j < n; j++)
        for(int value = 1; value <= x; value++)
            if (value - coins[j] >= 0)
                numberOfCombinations[value] = (numberOfCombinations[value] + 
                                        numberOfCombinations[value-coins[j]]) % mod;
    cout << numberOfCombinations[x];
}
