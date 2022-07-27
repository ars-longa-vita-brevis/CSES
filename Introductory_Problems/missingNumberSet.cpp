#include<bits/stdc++.h> 

using namespace std;


int main()
{
    int n;
    cin >> n;
    set<int> st;
    for(int i = 1;i<=n;i++)
        st.insert(i);
    for(int i = 0;i<n-1;i++)
    {
        int x;
        cin >> x;
        st.erase(x);
    }
    cout << *st.begin();
}
