#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
#define INF 1e9;
typedef long long ll;

const int nax = 505;

int minCut[nax][nax];

int main()
{
    int width,height;
    cin >> width >> height;
    for (int w = 1; w <= width; w++)
        for (int h = 1; h <= height; h++)
            minCut[w][h] = INF;
    for (int i = 1; i < nax; i++)
        minCut[i][i] = 0;
    for (int w = 1; w <= width; w++)
        for (int h = 1; h <= height; h++)
        {
            for (int cut = 1; cut < w; cut++)
                minCut[w][h] = min(minCut[w][h],minCut[cut][h]+minCut[w-cut][h]+1);
            for (int cut = 1; cut < h; cut++)
                minCut[w][h] = min(minCut[w][h],minCut[w][cut]+minCut[w][h-cut]+1);
        }
    cout << minCut[width][height];
}
