#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> values(n);
    for(int i = 0; i < n ; i++)
        cin>>values[i];
    ll sum = 0;
    map<ll,int> seen;
    seen[0]++;
    ll cnt = 0;
    for(int i = 0; i < n ; i++)
    {
        sum += values[i]%n;
        sum = (sum+n)%n;
        cnt += seen[sum];
        seen[sum]++;
    }
    cout << cnt;
}
