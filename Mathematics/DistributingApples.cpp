#include<bits/stdc++.h> 
 
using namespace std;
#define ln '\n'
typedef long long ll;

int modulo = 1e9+7;
ll modularBinaryExponentiation(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    ll result = modularBinaryExponentiation(base,exponent/2);
    result = (result*result)%modulo;
    if (exponent%2==1)
        return (result * base) % modulo;
    else
        return result;
}


int main()
{
    int a,b;
    cin >> a >> b;
    vector<ll> factorial(a+b);
    factorial[0]=1;
    for(int i = 1; i < a+b; i++)
        factorial[i] = (factorial[i-1]*i)%modulo;
    cout << (((factorial[a+b-1]
                    * modularBinaryExponentiation(factorial[b],modulo-2))%modulo)
                    * modularBinaryExponentiation(factorial[a-1],modulo-2))%modulo;
}
