#include<bits/stdc++.h> 

using namespace std;
#define ln '\n'
typedef long long ll;

int main()
{
	vector<string> chessBoard(8);
	for (int i = 0; i < 8;i++)
		cin >> chessBoard[i];
	int count = 0;
	vector<int> columns(8);
	iota(columns.begin(), columns.end(),0);
	do{
		bool valid = true;
		for(int i = 0; i < 8; i++)
		{
			if (chessBoard[i][columns[i]] != '.')
            {
				valid = false;
                break;
            }       
		}
		vector <bool> diagonalOccupied(15,false);
		for(int i = 0; i < 8; i++)
		{
			if (diagonalOccupied[i+columns[i]])
				valid = false;
			diagonalOccupied[i+columns[i]] = true;
		}
		for(int i = 0; i < 15; i++)
			diagonalOccupied[i] = false;
		for(int i = 0; i < 8; i++)
		{
			if (diagonalOccupied[i+7-columns[i]])
				valid = false;
			diagonalOccupied[i+7-columns[i]] = true;
		}
		count += valid;
	}while (next_permutation(columns.begin(),columns.end()));
	cout << count;
}
