#include<bits/stdc++.h> 

using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int mx = -1;
    long long output=0;
    for(int i=0;i<n;i++)
    {
        if(a[i] < mx)
            output+=mx-a[i];
        mx=max(mx,a[i]);
    }
    cout << output;
}
