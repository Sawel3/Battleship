#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "ShipsAi.h"
#include "Boards.h"
#include "Attack.h"
#include "ShipsPlayer.h"
#include "Ships.h"
#include <Windows.h>
#include "console.h"

using namespace std;
Ships AiShips[10]; //array of class Ships for Ai Ships
Ships PmcShips[10]; //array of class Ships for Player's Ships

int main() {
	string option;
	srand(time(0));
	//setting objects
	Boards tablica;
	Boards AiBoards;
	Boards PmcBoards;
	ShipsAi ai;
	ShipsAi player;
	ShipsPlayer gracz;
	Attack atak; 
	console consol;
	char** AiBoard;
	char** PmcBoard;
	char** AiArr;
	char** PmcArr;
	//main menu
	while (true) {
		cout << "Welcome to my battleships board game\n1.Play\n2.Credits\n3.Exit the game\n(enter the appropriate number)\n";
		cin >> option;
		switch (option[0]) {
		case '1':
			system("CLS");
			tablica.Clear_Board();

			AiBoards.Clear_Board();
			AiBoard = AiBoards.GetBoard();

			PmcBoards.Clear_Board();
			PmcBoard = PmcBoards.GetBoard();

			ai.SetShipsAi(AiShips);
			AiArr = ai.GetAiBoard();

			player.SetShipsAi(PmcShips);
			PmcArr = player.GetAiBoard();

			/*gracz.SetShips(PmcShips);
			PmcArr = gracz.GetBoard();*/
			//game loop
			while (true){
				system("CLS");
				consol.SetCursorPosition(0, 1);
				cout << "Player's turn\n";
				tablica.ShowTwoBoard(AiBoard, PmcArr);
				atak.Atak(AiArr, AiShips, AiBoard, PmcArr);
				system("CLS");
				cout << "PC's turn\n";
				atak.AiAtak(PmcArr, PmcShips, AiBoard);
			}
			break;
		case '2':
			system("CLS");
			cout << "Credits:\nMade by Pawel \"Sawel\" Sawczuk\nmostly:)\n\n";
			system("pause");
			system("CLS");
			break;
		case '3':
			system("CLS");
			cout << "Thank you for playing my game :)\n";
			exit(0);
			break;
		default:
			system("CLS");
			cout << "You typed wrong character\n";
			break;
		}
	}
	return 0;
}