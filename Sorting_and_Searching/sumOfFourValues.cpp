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
        cin >> values[i];
    map<int,pair<int,int> > valuesToPosision;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
            if (valuesToPosision.count(x-values[i]-values[j]))
            {
                cout << i+1 << " "<< j+1 << " "
                    << valuesToPosision[x-values[i]-values[j]].first + 1 << " "
                    << valuesToPosision[x-values[i]-values[j]].second + 1;
                return 0;
            }
        for (int j = 0; j < i; j++)
            valuesToPosision[values[i]+values[j]] = {i,j};
    }
    cout << "IMPOSSIBLE";
}
