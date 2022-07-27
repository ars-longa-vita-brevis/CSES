#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> values(n);
    for(int i = 0; i < n; i++)
        cin >> values[i];
    ll ans = 0;
    int j = 0;
    map<int, int> occurences;
    for(int i = 0; i < n; i++)
    {
        while(j < n && ((int)occurences.size() < k || occurences.count(values[j]) > 0))
        {
            occurences[values[j]]++;
            j++;
        }
        ans += j - i;
        occurences[values[i]]--;
        if(occurences[values[i]] == 0)
            occurences.erase(values[i]);
    }
    cout << ans;
}
