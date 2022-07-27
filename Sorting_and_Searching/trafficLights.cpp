#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int x, n;
    cin >> x >> n;
    set<int> positions;
    multiset<int> lengths;
    positions.insert(0);
    positions.insert(x);
    lengths.insert(x-0);
    for(int i = 0; i < n; i++)
    {
        int added;
        cin >> added;
        positions.insert(added);
        auto iter = positions.find(added);
        int previousVal = *prev(iter);
        int nextVal = *next(iter);
        lengths.erase(lengths.find(nextVal-previousVal));
        lengths.insert(added-previousVal);
        lengths.insert(nextVal-added);
        cout << *lengths.rbegin() << " ";
    }
}
