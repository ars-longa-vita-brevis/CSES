#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> applicants(n);
    vector<int> apartments(m);
    for(int i= 0;i<n;i++)cin>>applicants[i];
    for(int i =0; i < m;i++)cin>>apartments[i];
    sort(applicants.begin(),applicants.end());
    sort(apartments.begin(),apartments.end());
    int i = 0;
    int j = 0;
    int matches = 0;
    while (i < n)
    {
        while (j < m && apartments[j] < applicants[i] - k)
            j++;
        if (abs(apartments[j]-applicants[i]) <= k)
        {
            matches++;
            i++;
            j++;
        }
        else
            i++;
    }
    cout << matches;
}
