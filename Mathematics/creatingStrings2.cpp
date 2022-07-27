#include<bits/stdc++.h> 
 
using namespace std;
#define ln '\n'
typedef long long ll;
 
struct Factorial
{
    vector<ll> factorial;
    vector<ll> inverseFactorial;
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
        factorial.resize(n+1);
        inverseFactorial.resize(n+1);
        modulo = _modulo;
        factorial[0]=1;
        inverseFactorial[0]=1;
        for(int i = 1; i <= n; i++)
        {
            factorial[i] = (i *  factorial[i-1]) % modulo;
            inverseFactorial[i] = modularBinaryExponentiation(factorial[i],modulo-2);
        }       
    }
    int factorialOf(int x)
    {
        return factorial[x];
    }
    int inverseFactorialOf(int x)
    {
        return inverseFactorial[x];
    }
    int binomialCoefficientsOf(int a, int b)
    {
        return (((factorial[a]*inverseFactorial[a-b])%modulo)*inverseFactorial[b])%modulo;
    } 
    int multinomialCoefficientsOf(vector<int> &buckets)
    {
        int sum = 0;
        for(int bucket : buckets)
            sum += bucket;
        ll result = factorialOf(sum);
        for(int bucket : buckets)
            result = (result*inverseFactorialOf(bucket))%modulo;
        return result;
    }
};
 
 
int main()
{
    string str;
    cin >> str;
    Factorial fc = Factorial(1e6,1e9+7);
    vector<int> occurencesOf(26,0);
    for(char c : str)
        occurencesOf[c-'a']++;
    cout << fc.multinomialCoefficientsOf(occurencesOf);
}
