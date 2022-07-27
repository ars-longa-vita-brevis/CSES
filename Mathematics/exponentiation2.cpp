#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;
const int mod = 1e9 + 7;

ll modularBinaryExponentiation(int base, int exponent,int modulo)
{
    if (exponent == 0)
        return 1;
    ll result = modularBinaryExponentiation(base,exponent/2, modulo);
    if (exponent%2==1)
        return (((result * result) % modulo) * base) % modulo;
    else
        return (result * result) % modulo;
}

int main()
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int exponent = modularBinaryExponentiation(b,c,mod-1);
        cout << modularBinaryExponentiation(a,exponent,mod) << ln;
    }
}
