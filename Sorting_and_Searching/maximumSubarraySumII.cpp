#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
#define INF 1e18
typedef long long ll;

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    vector<ll> values(n+1);
    for(int i = 1; i <=n; i++)
        cin >> values[i];
    for(int i = 1; i <= n; i++)
        values[i] += values[i-1];
    set<pair<ll,int>> rightBoundaries;
    for(int i = a; i<= b;i++)
        rightBoundaries.insert({values[i],i});
    ll maxSum = -INF;
    for(int i= 1 ;i <= n-a+1; i++)
    {
        maxSum = max(maxSum,rightBoundaries.rbegin()->first-values[i-1]);
        rightBoundaries.erase({values[i+a-1],i+a-1});
        if (i+b <= n)
            rightBoundaries.insert({values[i+b],i+b});
    }
    cout << maxSum; 
}
