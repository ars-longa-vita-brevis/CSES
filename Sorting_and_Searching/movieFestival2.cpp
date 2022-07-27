#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return a.second < b.second;
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> movies(n);
    for(int i = 0; i < n; i++)
        cin >> movies[i].first >> movies[i].second;
    sort(movies.begin(), movies.end(),cmp);
    set<pair<int,int>> available;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if (available.size() == 0)
            available.insert({movies[i].second*-1,i});
        else
        {
            auto t = available.lower_bound({movies[i].first*-1,-1});
            if (t != available.end())
            {
                available.erase(t);
                available.insert({movies[i].second*-1,i});
            }
            else if (t == available.end() && available.size() < k)
                available.insert({movies[i].second*-1,i});
            else
                cnt++;
        }
    }
    cout << n-cnt;
}
