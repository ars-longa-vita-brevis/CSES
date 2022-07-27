#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
const int mod = 1e9+7;
typedef long long ll;

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

int geomtricSum(int base, int power)
{
    ll numerator = (modularBinaryExponentiation(base,power+1)-1+mod)%mod;
    ll denominatorInverse = modularBinaryExponentiation(base-1,mod-2);
    return (numerator*denominatorInverse)%mod;
}
int main()
{
    int n;
    cin >> n;
    vector<int> prime(n);
    vector<int> exponent(n);
    for(int i = 0; i < n; i++)
        cin >> prime[i] >> exponent[i];
    ll numberOfDivisors = 1;
    for(int i = 0; i < n; i++)
        numberOfDivisors = (numberOfDivisors * (exponent[i]+1)) % mod;
    ll sumOfDivisors = 1;
    for(int i = 0; i < n; i++)
        sumOfDivisors = (sumOfDivisors * geomtricSum(prime[i],exponent[i]))%mod;
    ll productOfDivisors = 1;
    bool oddExponent = false;
    int positionOfOddExponent;
    for(int i = 0; i < n; i++)
        if(exponent[i]%2==1)
        {
            oddExponent = true;
            positionOfOddExponent = i;
        }
    if (oddExponent)
    {
        ll outerExponent = 1;
        for(int i = 0; i < n; i++)
        {
            if (i == positionOfOddExponent)
                outerExponent = (outerExponent * (exponent[i]+1)/2)%(mod-1);
            else
                outerExponent = (outerExponent * (exponent[i]+1))%(mod-1);
        }
        for(int i = 0; i < n; i++)
            productOfDivisors = (productOfDivisors * modularBinaryExponentiation
                                                    (prime[i],
                                                    (exponent[i]*outerExponent)%(mod-1)))%mod;
    }
    else
    {
        ll outerExponent = 1;
        for(int i = 0; i < n; i++)
            outerExponent = (outerExponent * (exponent[i]+1))%(mod-1);
        for(int i = 0; i < n; i++)
            productOfDivisors = (productOfDivisors * modularBinaryExponentiation
                                                    (prime[i],
                                                    ((exponent[i]/2)*outerExponent)%(mod-1)))%mod;
    }
    cout << numberOfDivisors << " " << sumOfDivisors << " " << productOfDivisors; 
}
