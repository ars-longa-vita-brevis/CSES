#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    ll powFive = 5;
    while(powFive <=n)
    {
        ans += n/powFive;
        powFive*=5;
    }
    cout << ans;
}
