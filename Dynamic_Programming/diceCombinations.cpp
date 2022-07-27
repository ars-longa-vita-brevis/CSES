#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;
const int mod = 1e9+7;

int main()
{
    int n;
    cin >> n;
    vector<ll> combinations(n+1,0);
    combinations[0] = 1;
    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= 6; j++)
            if(i-j >=0)
                combinations[i] = (combinations[i]+combinations[i-j]) % mod;
    cout << combinations[n];
}
