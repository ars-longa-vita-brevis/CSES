#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    string str;
    cin >> str;
    vector<int> cnt(26,0);
    for(int i=0;i<str.length();i++)
        cnt[str[i]-'A']++;
    int oddPos = -1;
    for(int i=0;i<26;i++)
    {
        if (cnt[i]%2==1)
        {
            if(oddPos==-1)
            {
                oddPos=i;
            }
            else
            {
                cout << "NO SOLUTION";
                return 0;
            }
        }
    }
    if (oddPos!=-1 && str.length()%2==0)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    if (oddPos==-1 && str.length()%2==1)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    string ans;
    for(int i=0;i<26;i++)
        for(int j=0;j<cnt[i]/2;j++)
            ans+=(char)('A'+i);
    cout << ans;
    if (oddPos != -1)
        cout << (char)('A'+oddPos);
    reverse(ans.begin(),ans.end());
    cout << ans;
}
