#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n, x;
    cin >> n >> x;
    map<int,int> positionOfValue;
    for(int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        if (positionOfValue.count(x-value))
        {
            cout << i+1 << " " << positionOfValue[x-value] << endl;
            return 0;
        }
        positionOfValue[value] = i+1;
    }
    cout << "IMPOSSIBLE" ;
}
