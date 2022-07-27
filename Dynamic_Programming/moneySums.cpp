#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> values(n);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> values[i];   
        sum += values[i];
    }
    vector<int> reachable(sum+1,0);
    reachable[0] = 1;
    for(int i = 0; i < n; i++)
        for(int value = sum ; value >= values[i]; value--)
            reachable[value] |= reachable[value-values[i]]; 
    int count = 0;
    for (int i = 1; i <= sum; i++)
        if(reachable[i])
            count++;
    cout << count << ln;
    for (int i = 1; i <= sum; i++)
        if(reachable[i])
            cout << i << " ";
}
