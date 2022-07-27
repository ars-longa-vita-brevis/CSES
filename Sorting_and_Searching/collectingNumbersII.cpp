#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> values(n+1);
    vector<int> positionOf(n+1);
    for(int i=1; i<=n; i++)
    {
        cin >> values[i];
        positionOf[values[i]] = i;
    }
    int answer = 1;
    for(int i=1; i<n; i++)
        answer += (positionOf[i] > positionOf[i+1]);
    int l, r;
    set<pair<int,int>> updatedPairs; 
    while(q--)
    {
        cin>>l>>r;
        if (values[l]+1 <= n)
            updatedPairs.insert({values[l], values[l]+1});
        if (values[l]-1 >= 1)
            updatedPairs.insert({values[l]-1, values[l]});
        if (values[r]+1 <= n)
            updatedPairs.insert({values[r], values[r]+1});
        if (values[r]-1 >= 1)
            updatedPairs.insert({values[r]-1, values[r]});
        for(pair<int,int> swapped : updatedPairs)
            answer -= positionOf[swapped.first]>positionOf[swapped.second];
        swap(values[l], values[r]);
        positionOf[values[l]] = l;
        positionOf[values[r]] = r;
        for(pair<int,int> swapped : updatedPairs)
            answer += positionOf[swapped.first]>positionOf[swapped.second];
        cout << answer << ln;
        updatedPairs.clear();
    }
}
