#include<bits/stdc++.h> 

using namespace std;

#define ln '\n'
int main()
{
    int n;
    cin >> n;
    for(long long k=1;k<=n;k++)
        cout << (k*k*(k*k-1))/2-4*(k-1)*(k-2) << ln;
}

