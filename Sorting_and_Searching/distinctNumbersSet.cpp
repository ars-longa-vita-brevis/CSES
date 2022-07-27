#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    set<int> values;
    for(int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        values.insert(value);
    }
    cout << values.size();
}
