#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int queries;
    cin >> queries;
    while(queries--)
    {
        int number;
        cin >> number;
        vector<int> powersOfPrimeFactors;
        for(int i = 2; i*i <= number; i++)
        {
            if (number % i == 0)
            {
                int power = 0;
                while(number % i == 0)
                {
                    power++;
                    number /= i;
                }
                powersOfPrimeFactors.push_back(power);
            }
        }
        if (number != 1)
            powersOfPrimeFactors.push_back(1);
        int numberOfDivisors = 1;
        for(int z : powersOfPrimeFactors)
            numberOfDivisors *= (z+1);
        cout << numberOfDivisors << ln;
    }
}
