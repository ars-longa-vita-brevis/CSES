#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;


void solve(int src,int dest,int aux,int n)
{
    if (n <= 0)
        return;
    solve(src, aux, dest,n-1);
    cout << src << " " << dest << ln;
    solve(aux, dest, src,n-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << (1<<n)-1 << ln;
    solve(1, 3, 2, n);
}
