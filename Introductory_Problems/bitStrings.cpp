#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;
const int mod = (int)(1e9+7);
int main()
{
    ll n;
    cin >> n;
    ll ans = 1;
    for(int i=0;i<n;i++)
    {
        ans*=2;
        ans %= mod;
    }
    cout << ans;
}
