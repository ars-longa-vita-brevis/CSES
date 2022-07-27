#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> values(n);
    for(int i = 0;i < n; i++)
        cin >> values[i];
    sort(values.begin(),values.end());
    int uniqueValues = 0;
    for(int i = 0;i < n; i++)
        if (i == 0 || values[i] != values[i-1])
            uniqueValues++;
    cout << uniqueValues;
}
