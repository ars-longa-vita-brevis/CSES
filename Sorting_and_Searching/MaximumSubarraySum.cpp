#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<ll> value(n);
	for(int i = 0; i < n; i++)
		cin >>value[i];
	ll best = -1e18;
	ll past = 0;
	for(int i = 0; i < n; i++)
	{
		if (past+value[i] >= value[i])
			past += value[i];
		else
			past = value[i];
		best = max(best,past);
	}
	cout << best;
}
