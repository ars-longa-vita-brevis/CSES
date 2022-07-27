#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
#define INF 1e9
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> minimumSteps(n+1,INF);
    minimumSteps[0] = 0;
    for(int value = 1; value <= n; value++)
    {
        int tmpValue = value;
        while(tmpValue > 0)
        {
            minimumSteps[value] = min(minimumSteps[value], 
                    minimumSteps[value-tmpValue%10]+1);
            tmpValue /= 10;
        }
    } 
    cout << minimumSteps[n];
}
