#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    ll n;
    int k;
    cin >> n >> k;
    vector<ll> primes(k);
    for(int i = 0; i < k; i++)
        cin >> primes[i];
    vector<ll> countByNumberOfDivisors(k+1);
    for(int mask = 1; mask < (1<<k); mask++)
    {
        int numberOfDivisors = 0;
        ll tmp = n;
        for(int i = 0; i < k; i++)
        {
            if ((1<<i)&mask)
            {
                numberOfDivisors++;
                tmp /= primes[i];
            }
        }
        //int numberOfDivisors = __builtin_popcount(mask);
        countByNumberOfDivisors[numberOfDivisors] += tmp;
    }
    ll answer = 0;
    for(int i = 1; i <= k; i++)
    {
        if (i%2==0)
            answer -= countByNumberOfDivisors[i];
        else
            answer += countByNumberOfDivisors[i];
    }
    cout << answer;
}
