#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> machines(n);
    for(int i = 0; i < n; i++)
		cin >> machines[i];
	ll low = 0;
	ll hi = 1e18;
	ll answer = 1e18;
	while (low <= hi)
	{
		ll mid = (low+hi)/2;
		ll products = 0;
        for(int i = 0; i < n; i++)
			products += min(mid/machines[i],(ll)1e9);
		if (products >= m)
		{
			if (mid < answer)
				answer = mid;
			hi = mid-1;
		}
		else
			low = mid+1;
	}
	cout << answer; 
}
