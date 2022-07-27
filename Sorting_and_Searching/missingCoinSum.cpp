#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++)
        cin >> coins[i];
    sort(coins.begin(), coins.end());
    ll smallestSum = 1;
    for (int i = 0; i < n && smallestSum >= coins[i]; i++)
        smallestSum += coins[i];
    cout << smallestSum;
}
