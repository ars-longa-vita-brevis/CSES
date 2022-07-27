#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

bool valueOf(int number,int pos)
{
    return (number&(1<<pos))!=0;
}

int main()
{
    int n;
    cin >> n;
    for(int number = 0; number < (1<<n); number++)
    {
        cout << valueOf(number,n-1);
        for(int power = n-2;power>=0;power--)
            cout << (valueOf(number,power)^valueOf(number,power+1));
        cout << ln;
    }
}
