#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "ShipsAi.h"
#include "Boards.h"
#include "Attack.h"
#include "ShipsPlayer.h"
#include "Ships.h"

using namespace std;
Ships AiShips[10]; //array of class Ships for Ai Ships
Ships PmcShips[10]; //array of class Ships for Player's Ships

int main() {
	srand(time(0));
	//setting objects
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

	/*gracz.SetShips(PmcShips);*/
	player.SetShipsAi(PmcShips);
	/*char** PmcArr = gracz.GetBoard();*/
	char** PmcArr = player.GetAiBoard();
	tablica.ShowTwoBoard(AiBoard, PmcArr);
	//game loop
	cout << "dziala\n";
	while (true)
	{
		tablica.ShowTwoBoard(AiBoard,PmcArr);
		tablica.Show_Board(AiArr);
		cout << "Player's turn\n";
		atak.Atak(AiArr, AiShips, AiBoard, PmcArr);
		cout << "PC's turn\n";
		atak.AiAtak(PmcArr,PmcShips,AiBoard);
	}
	return 0;
}
