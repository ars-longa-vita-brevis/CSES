#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> values(n);
    vector<vector<ll>> maximum_difference_for_interval(n,vector<ll>(n));
    ll total_sum_of_values = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
        maximum_difference_for_interval[i][i] = values[i];
        total_sum_of_values += values[i];
    }
    for (int left = n-1; left >= 0; left--)
    {
        for (int right = left + 1; right < n; right++)
        {
            ll choosing_the_first_element_score = values[left] - maximum_difference_for_interval[left + 1][right]; 
            ll choosing_the_last_element_score = values[right] - maximum_difference_for_interval[left][right - 1]; 
            maximum_difference_for_interval[left][right] = max(choosing_the_first_element_score,
                                                               choosing_the_last_element_score);
        }
    }
    cout << (total_sum_of_values + maximum_difference_for_interval[0][n - 1]) / 2;
}
