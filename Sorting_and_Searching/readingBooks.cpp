#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> books(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>books[i];
        sum += books[i];
    }
    sort(books.begin(), books.end());
    cout << max(sum,(ll)books[n-1]*2);
}
