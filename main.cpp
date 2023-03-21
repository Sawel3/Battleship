#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "ShipsAi.h"
#include "Boards.h"
#include "Attack.h"
#include "ShipsPlayer.h"
#include "Ships.h"

using namespace std;
Ships AiShips[10];
Ships PmcShips[10];

int main() {
	srand(time(0));
	Boards tablica;
	Boards AiBoards;
	Boards PmcBoards;
	ShipsAi ai;
	ShipsAi player;
	ShipsPlayer gracz;
	Attack atak;  

	tablica.Clear_Board();
	AiBoards.Clear_Board();
	char** AiBoard = AiBoards.GetBoard();
	PmcBoards.Clear_Board();
	char** PmcBoard = PmcBoards.GetBoard();

	ai.SetShipsAi(AiShips);
	char** AiArr = ai.GetAiBoard();

	player.SetShipsAi(PmcShips);
	char** PmcArr = player.GetAiBoard();

	/*tablica.Show_Board(AiArr);*/
	tablica.ShowTwoBoard(AiBoard,PmcArr);
	while (true)
	{
		tablica.Show_Board(AiArr);
		cout << "Player's turn\n";
		atak.Atak(AiArr, AiShips, AiBoard, PmcArr);
		cout << "PC's turn\n";
		atak.AiAtak(PmcArr,PmcShips,AiBoard);
	}
	// if win
	
	return 0;
}
