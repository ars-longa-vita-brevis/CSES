#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector <pair<int,int> > events;
    for(int i = 0; i < n; i++)
    {
        int start,end;
        cin >> start >> end;
        events.push_back({start,1});
        events.push_back({end,-1});
    }
    sort(events.begin(),events.end());
    int actualCustomers = 0;
    int maxCustomers = 0;
    for(int i = 0; i < events.size(); i++)
    {
        actualCustomers += events[i].second;
        maxCustomers = max(maxCustomers,actualCustomers);
    }
    cout << maxCustomers << endl;
}
