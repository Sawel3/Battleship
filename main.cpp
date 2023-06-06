/**
 * \mainpage
 * \par Battleship
 * Battleships board game
 * \author Pawel Sawczuk
 * \date   June 2023
 * \version 1.0
 * \par Kontakt:
 * \a pawel.sawczuk2.stud@pw.edu.pl
*/
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
/// <summary>
/// The array of class Ships for Ai Ships
/// </summary>
Ships AiShips[10];
/// <summary>
/// The array of class Ships for Player's Ships
/// </summary>
Ships PmcShips[10];
/// <summary>
/// String for choosing an option in the main menu
/// </summary>
string option;
/// <summary>
/// Mains this instance.
/// </summary>
/// <returns></returns>
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
	console consol;
	//setting arrays
	char** AiBoard;
	char** PmcBoard;
	char** AiArr;
	char** PmcArr;
	//main menu
	while (true) {
		cout << "Welcome to my battleships board game\n1.Play\n2.Credits\n3.Exit the game\n(enter the appropriate number)\n";
		cin >> option;
		switch (option[0]) {
		case '1': //game
			system("CLS");
			tablica.Clear_Board();
			//setting visable pc's board
			AiBoards.Clear_Board();
			AiBoard = AiBoards.GetBoard();
			//setting player's board
			PmcBoards.Clear_Board();
			PmcBoard = PmcBoards.GetBoard();
			//placing ships on pc's board
			ai.SetShipsAi(AiShips);
			AiArr = ai.GetAiBoard();
			//placing ships on player's board
			/*player.SetShipsAi(PmcShips);
			PmcArr = player.GetAiBoard();*/
			gracz.SetShips(PmcShips);
			PmcArr = gracz.GetBoard();
			//game loop
			while (true){
				system("CLS");
				consol.SetCursorPosition(0, 1);
				cout << "Player's turn\n";
				tablica.ShowTwoBoard(AiBoard, PmcArr);
				atak.Atak(AiArr, AiShips, AiBoard, PmcArr);//attack function for player
				system("CLS");
				cout << "PC's turn\n";
				atak.AiAtak(PmcArr, PmcShips, AiBoard);//atack function for pc
			}
			break;
		case '2'://credits
			system("CLS");
			cout << "Credits:\nMade by Pawel \"Sawel\" Sawczuk\nmostly:)\n\n";
			system("pause");
			system("CLS");
			break;
		case '3'://exit
			system("CLS");
			cout << "Thank you for playing my game :)\n";
			exit(0);
			break;
		default://error
			system("CLS");
			cout << "You typed wrong character\n";
			break;
		}
	}
	return 0;
}