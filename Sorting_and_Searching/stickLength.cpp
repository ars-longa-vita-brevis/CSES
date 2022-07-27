#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n;
	cin >> n;
	vector<int> length(n);
    for(int i = 0 ; i < n; i++)
		cin >> length[i];
	sort(length.begin(),length.end());
	ll cost = 0;
    for(int i = 0 ; i < n; i++)
		cost += abs(length[i]-length[n/2]);
	cout << cost;
}
