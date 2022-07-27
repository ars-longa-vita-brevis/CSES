#include<bits/stdc++.h> 
 
using namespace std;
#define ln '\n'
typedef long long ll;
 
struct Factorial
{
    vector<ll> factorial;
    int modulo;
    ll modularBinaryExponentiation(int base, int exponent)
    {
        if (exponent == 0)
            return 1;
        ll result = modularBinaryExponentiation(base,exponent/2);
        if (exponent%2==1)
            return (((result * result) % modulo) * base) % modulo;
        else
            return (result * result) % modulo;
    }
    Factorial(int n,int _modulo)
    {
        factorial.resize(n + 1);
        modulo = _modulo;
        factorial[0]=1;
        for(int i = 1; i <= n; i++)
            factorial[i] = (i *  factorial[i-1]) % modulo;
    }
    int factorialOf(int x)
    {
        return factorial[x];
    }
    int inverseFactorialOf(int x)
    {
        return modularBinaryExponentiation(factorialOf(x),modulo-2);
    }
    int binomialCoefficientsOf(int a, int b)
    {
        if (b < 0 || a < b)
            return 0;
        return (((factorial[a]*inverseFactorialOf(a-b))%modulo)*inverseFactorialOf(b))%modulo;
    }
   
};
 
const int modulo = 1e9 + 7;
 
int main()
{
    int n;
    cin >> n;
    Factorial fc = Factorial(n+10, modulo);
    string str;
    cin >> str;
    if (n%2)
    {
        cout << 0;
        return 0;
    }
    int openB = 0;
    int closedB = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            openB++;
        else
            closedB++;
        if (closedB > openB)
        {
            cout << 0;
            return 0;
        }
    }
    if (openB * 2 > n)
    {
        cout << 0;
        return 0;
    }
    n -= str.length();
    int remainingClosedB = (n + openB - closedB)/2;
    int remainingOpenB = n - remainingClosedB;
    cout << (fc.binomialCoefficientsOf(n, remainingClosedB) - fc.binomialCoefficientsOf(n, remainingClosedB + 1) + modulo) % modulo;
}
