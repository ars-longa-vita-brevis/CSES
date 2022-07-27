#include<bits/stdc++.h> 

using namespace std;


int main()
{
    int n;
    cin >> n;
    if (n==1)
        cout << 1;
    else if (n==2||n==3)
        cout << "NO SOLUTION";
    else if (n==4)
        cout << "2 4 1 3";
    else
    {
        for(int i=1;i<=n;i+=2)
            cout << i << " ";
        for(int i=2;i<=n;i+=2)
            cout << i << " ";
    }
}
