#pragma once
class Boards
{
private:
	int N = 10;
	char **board;
	int MaxShips = 10;
public:
	Boards();
	void Show_Board();
	int GetN();
	char **GetBoard();
	void Clear_Board();
};
//int Boards::GetN() const{
//	return N;
//}
//char Boards::GetBoard() {
//	return board[N][N];
//}

