#include<bits/stdc++.h> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ln '\n'
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> values(n);
    for(int i = 0; i < n; i++)
        cin >> values[i];
    ordered_set< pair<int,int> > window;
    for(int i = 0; i < k; i++)
        window.insert({values[i],i});
    cout << window.find_by_order((k-1)/2)->first << " ";
    for(int i = 1; i < n-k+1; i++)
    {
        window.erase({values[i-1],i-1});
        window.insert({values[i+k-1],i+k-1});
        cout << window.find_by_order((k-1)/2)->first << " ";
    }
}
