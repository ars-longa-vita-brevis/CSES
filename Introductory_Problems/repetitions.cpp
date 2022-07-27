#include<bits/stdc++.h> 

using namespace std;


int main()
{
    string str;
    cin >> str;
    vector<int> value(str.length(),0);
    value[0]=1;
    int mx=1;
    for(int i=1;i<str.length();i++)
    {
        if (str[i]==str[i-1])
            value[i]=value[i-1]+1;
        else
            value[i]=1;
        mx=max(mx,value[i]);
    }
    cout << mx;
}
