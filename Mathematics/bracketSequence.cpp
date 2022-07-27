#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;


const int mod = 1e9 + 7;

ll modularBinaryExponentiation(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    ll result = modularBinaryExponentiation(base,exponent/2);
    if (exponent%2==1)
        return (((result * result) % mod) * base) % mod;
    else
        return (result * result) % mod;
}

int main()
{
    ll n;
    cin >> n;
    if (n%2)
    {
        cout << 0;
        return 0;
    }
    n /=2;
    vector<ll> validBracketSequences(n+1);
    validBracketSequences[0] = 1;
    for (int i = 1; i <= n; i++)
        validBracketSequences[i] = (
                                    (((4*i-2)* modularBinaryExponentiation(i+1,mod-2))%mod) 
                                    * validBracketSequences[i-1]
                                   ) % mod;
    cout << validBracketSequences[n];
}
