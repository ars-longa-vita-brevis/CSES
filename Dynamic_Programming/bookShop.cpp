#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
    int books, totalPrice;
    cin >> books >> totalPrice;
    vector<int> priceOfBook(books);
    vector<int> pagesOfBook(books);
    for(int i = 0; i < books; i++)
        cin >> priceOfBook[i];
    for(int i = 0; i < books; i++)
        cin >> pagesOfBook[i];
    vector<vector<int>> maxPages(books+1,vector<int>(totalPrice+1,0));
    for(int i = 0; i < books; i++)
        for(int price = 0; price <= totalPrice;price++)
        {
            maxPages[i+1][price] = maxPages[i][price];
            if (price >= priceOfBook[i])
                maxPages[i+1][price] = max(maxPages[i+1][price],pagesOfBook[i]+maxPages[i][price-priceOfBook[i]]);
        }
    cout << maxPages[books][totalPrice];
}
