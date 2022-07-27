#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    stack<pair<int,int> > stk;
    vector<int> values(n);
    for(int i = 0; i < n; i++)
        cin >> values[i];
    for(int i = 0; i < n; i++)
    {
        while(stk.size() > 0 && stk.top().first >= values[i])
            stk.pop();
        if(stk.size() > 0)
            cout << stk.top().second << " ";
        else
            cout << 0 << " ";
        stk.push({ values[i], i + 1});
    }
}
