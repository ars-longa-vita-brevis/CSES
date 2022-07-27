#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

const int maxValue = 1e6+10;

int main()
{
    int n;
    cin >> n;
    vector<int> values(n);
    for(int i = 0; i < n; i++)
        cin >> values[i];
    vector<int> sieve(maxValue);
    vector<vector<int>> divisorsOf(maxValue);
    for (int i = 2; i < maxValue; i++)
    {
        if (divisorsOf[i].size() == 0)
        {
            divisorsOf[i].push_back(i);
            for(int j = 2*i; j < maxValue; j += i)
                divisorsOf[j].push_back(i);
        }
    }
    vector<int> valuesDivisibleBy(maxValue);
    vector<int> primeDivisorsOf(maxValue);
    for(int i = 0; i < n; i++)
    {
        for (int mask = 1; mask < (1<<(divisorsOf[values[i]].size())); mask++)
        {
            int combination  = 1;
            int primeDivisors = 0;
            for (int pos = 0 ; pos < divisorsOf[values[i]].size(); pos++)
            {
                if ((1<<pos)&mask)
                {
                    combination *= divisorsOf[values[i]][pos];
                    primeDivisors++;
                }
            }
            valuesDivisibleBy[combination]++;
            primeDivisorsOf[combination] = primeDivisors;
        }
    }
    ll totalNumberOfPairs = ((ll)n*((ll)(n-1)))/2;
    ll validPairs = 0;
    for(int i = 0; i < maxValue; i++)
    {
        if (primeDivisorsOf[i]%2)
            validPairs += ((ll)valuesDivisibleBy[i]*((ll)valuesDivisibleBy[i]-1))/2;
        else
            validPairs -= ((ll)valuesDivisibleBy[i]*((ll)valuesDivisibleBy[i]-1))/2;
    }
    cout << totalNumberOfPairs - validPairs;
}
