#include "Boards.h"
int Boards::GetN() {
	return N;
}
Boards::Boards() {
	board = new char* [N];
	for (int i = 0; i < N; i++) board[i] = new char[N];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
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
	for (int i = 0; i < N; i++){
		if (i == 0) {
			cout << "   | ";
			for (int j = 0; j < N; j++) cout << j+1 << " | ";
			cout << endl << "_______________________________________________\n";
		}
		for (int j = 0; j < N; j++){
			if (j == 0){
				cout << " " << a << " | ";
				a += 1;
			}cout << board[i][j]/*<<"[" << i <<"," << j << "]" */ << " | ";
		}cout << endl;
	}cout << "_______________________________________________\n";
}
void Boards::ShowTwoBoard(char** AiBoard, char** PmcBoard) {
	char a = 'A';
	char c = 'A';
	for (int i = 0; i < N; i++){
		if (i == 0) {
			cout << "\t\tPC's board\t\t\t\t\t\tPlayer's Board\n";
			cout << "   | ";
			for (int j = 0; j < N; j++) cout << j+1 << " | ";
			cout << "\t\t   | ";
			for (int j = 0; j < N; j++) cout << j+1 << " | ";
			cout << endl << "______________________________________________\t\t______________________________________________\n";	
		}
		for (int j = 0; j < N; j++){
			if (j == 0){
				cout << " " << a << " | ";
				a += 1;
			}cout << AiBoard[i][j]/*<<"[" << i <<"," << j << "]" */ << " | ";
		}
		for (int j = 0; j < N; j++) {
			if (j == 0) {
				cout << "\t\t " << c << " | ";
				c += 1;
			}cout<< PmcBoard[i][j]/*<<"[" << i <<"," << j << "]" */ << " | ";
		}cout << endl;
	}cout << "______________________________________________\t\t______________________________________________\n";
}
void Boards::Clear_Board() {
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) board[i][j] =' ';
	}
};
