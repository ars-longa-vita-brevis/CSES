#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n,x;
	cin >> n >> x;
	vector<int> values(n);
    for(int i = 0; i < n; i++)
		cin>>values[i];
	ll sum = 0;
	map<ll,int> seen;
	seen[0]++;
	ll count = 0;
    for(int i = 0; i < n; i++)
    {
		sum += values[i];
		count += seen[sum-x];
		seen[sum]++;
	}
	cout << count;
}
