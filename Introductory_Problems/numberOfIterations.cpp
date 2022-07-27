#include<bits/stdc++.h> 

using namespace std;
long long maxN = 0;
int numberOfIterations(long long n)
{
    maxN=max(n,maxN);
    if(n==1)
        return 0;
    if (n%2==0)
        return (1+numberOfIterations(n/2));
    else
        return 1+numberOfIterations(3*n+1);
}
int main()
{
    int maxIterations = 0;
    for(int i = 1;i<=1000000;i++)
        maxIterations = max(maxIterations,numberOfIterations(i));
    cout << "MAX ITERATIONS " << maxIterations << endl;
    cout << "MAX N " << maxN << endl;
}
