#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n, x;
	cin >> n >> x;
	vector<int> values(n);
    for(int i = 0; i < n; i++)
		cin>>values[i];
	int j = 0;
	ll sum = 0;
	int i = 0;
	int cnt = 0;
	while (i < n)
	{
		sum += values[i];
		while (sum >= x)
		{
			if (sum == x)
				cnt++;
			sum -= values[j];
			j++;
		}
		i++;
	}
	cout << cnt;
}
