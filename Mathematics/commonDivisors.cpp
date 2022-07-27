#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> range(1e6+1,0);
    for(int i = 0; i< n; i++)
    {
        int x;
        cin >> x;
        range[x]++;
    }
    for(int gcd = 1e6; gcd >= 1; gcd--)
    {
        int multiples = 0;
        for(int pointer = gcd; pointer <= 1e6; pointer += gcd)
            multiples += range[pointer];
        if (multiples > 1)
        {
            cout << gcd;
            return 0;
        }
    }
}
