#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    vector<int> positionOfNumbers(n);
    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        numbers[i]--;
        positionOfNumbers[numbers[i]] = i;
    }
    int passes = 1;
    for(int i = 1; i < n; i++)
        if(positionOfNumbers[i] < positionOfNumbers[i-1])
            passes++;
    cout << passes;
}
