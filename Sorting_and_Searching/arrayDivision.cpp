#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> values(n);
    int maxValue = 0;
    for(int i = 0; i < n; i++)
    {
		cin>>values[i];
        maxValue = max(maxValue,values[i]);
    }
	ll low = maxValue;	
	ll hi = 1e18;
	ll maximumSum = 1e18;
	while (low<=hi)
	{
		ll mid = (low+hi)/2;
		int blocks = 1;
		ll sum = 0;
        for(int i = 0; i < n; i++)
		{
			if (sum + values[i] > mid)
			{
				sum = 0;
				blocks++;
			}
			sum += values[i];
		}
		if (blocks > k)
			low = mid+1;
		else
        {
			if (mid < maximumSum)
				maximumSum = mid;
			hi = mid-1;
		}
	}
	cout << maximumSum;
}
