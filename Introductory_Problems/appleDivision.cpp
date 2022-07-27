#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<int> all(n);
    for(int i = 0; i<n; i++)
		cin >>all[i];
	ll ans = 1e18;
	for (int mask = 0; mask <(1<<n); mask++)
	{
		ll sumA = 0;
		ll sumB = 0;
		for (int position = 0; position < n;position++)
		{
			if (mask&(1<<position))
				sumA += all[position];
			else
				sumB += all[position];
		}
		ans = min(ans,abs(sumA-sumB));
	}
	cout << ans;
}
