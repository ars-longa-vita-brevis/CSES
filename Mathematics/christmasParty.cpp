#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;
const int mod = 1e9+7;

int main()
{
    int n;
    cin >> n;
    vector<ll> derangementsOf(n+1);
    derangementsOf[1] = 0;
    for(int i = 2; i <= n; i++)
        derangementsOf[i] = (i * derangementsOf[i-1] + (i%2?-1:1))%mod;
    cout << derangementsOf[n];
}
