#pragma once
#include <iostream>
using namespace std;
class Boards
{
private:
	int N = 10;
	char **board;
	int MaxShips = 10;
public:
	Boards();
	void Show_Board(char** board);
	void ShowTwoBoard(char** AiBoard,char**PmcBoard);
	int GetN();
	char **GetBoard();
	void Clear_Board();
};


