#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	vector<int> cubes(n);
    for(int i = 0; i < n; i++)
        cin >> cubes[i];
	multiset<int> towers;
    for(int i = 0; i < n; i++)
	{
		if (towers.size() == 0)
			towers.insert(cubes[i]);
		else
		{
			auto base = towers.upper_bound(cubes[i]);
			if (base == towers.end())
				towers.insert(cubes[i]);
			else
			{
				towers.insert(cubes[i]);
				towers.erase(base);
			}
		}
	}
	cout << towers.size();
}
