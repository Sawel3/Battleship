#include <iostream>
#include "Boards.h"
using namespace std;
int Boards::GetN() {
	return N;
}
//Boards tab;
//int N = tab.GetN();
Boards::Boards() {
	board = new char* [N];
	for (int i = 0; i < N; i++)
	{
		board[i] = new char[N];
	}
}
char **Boards::GetBoard() {
	char **board = new char* [N];
	for (int i = 0; i < N; i++)
	{
		board[i] = new char[N];
	}
	return board;
}
void Boards::Show_Board() {
	char a = 'A';
	int b = 0;
	//char** board = GetBoard();
	for (int i = 0; i < N; i++)
	{
		if (i == 0) {
			cout << "     | ";
			for (int j = 0; j < N; j++)
			{
				cout << j << " | ";
			}
			cout << endl << "_______________________________________________\n";
		}
		for (int j = 0; j < N; j++)
		{
			if (j == 0)
			{
				cout << " " << a << " " << b << " | ";
				a += 1;
				b++;
			}

			cout << board[i][j]/*<<"[" << i <<"," << j << "]" */ << " | ";
		}
		cout << endl;
	}
	cout << "_______________________________________________\n";
}
void Boards::Clear_Board() {
	//char** board = tab.GetBoard();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = 0 + '  ';
		}
	}
};
