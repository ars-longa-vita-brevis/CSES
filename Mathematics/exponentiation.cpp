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
    int cases;
    cases = 1;
    while(cases--)
    {
        int base,exponent;
        cin >> base >> exponent;
        cout << modularBinaryExponentiation(base,exponent) << ln;
    }
}
