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
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] =' ';
		}
	}
	
}
char **Boards::GetBoard() {
	return board;
}
void Boards::Show_Board(char** board) {
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
void Boards::ShowTwoBoard(char** AiBoard, char** PmcBoard) {
	char a = 'A';
	int b = 0;
	char c = 'A';
	int d = 0;
	//char** board = GetBoard();
	for (int i = 0; i < N; i++)
	{
		if (i == 0) {
			cout << "\t\tPC's board\t\t\t\t\t\tPlayer's Board\n";
			cout << "     | ";
			for (int j = 0; j < N; j++)
			{
				cout << j << " | ";
			}
			cout << "\t\t     | ";
			for (int j = 0; j < N; j++)
			{
				cout << j << " | ";
			}
			cout << endl << "______________________________________________\t\t______________________________________________\n";	
		}
		for (int j = 0; j < N; j++)
		{
			if (j == 0)
			{
				cout << " " << a << " " << b << " | ";
				a += 1;
				b++;
			}

			cout << AiBoard[i][j]/*<<"[" << i <<"," << j << "]" */ << " | ";
		}

		for (int j = 0; j < N; j++) {
			
			if (j == 0) {
				cout << "\t\t " << c << " " << d << " | ";
				c += 1;
				d++;
			}	
			cout<< PmcBoard[i][j]/*<<"[" << i <<"," << j << "]" */ << " | ";
		}
		cout << endl;
	}
	cout << "______________________________________________\t\t______________________________________________\n";
}
void Boards::Clear_Board() {
	//char** board = tab.GetBoard();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] =' ';
		}
	}
};
