#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "ShipsAi.h"
#include "Boards.h"
#include "Attack.h"
#include "ShipsPlayer.h"

using namespace std;
class Ships
{
private:
	int Patrol_boat=4; //2
	int Submarine=1; //3
	int Cruiser=2; //3
	int Battleship=2; //4
	int Carrier=1; //5
	int MaxShips = 10;
public:


};
class Board
{
private:
	const static int N = 10;
	char board[N][N];
	int Patrol_boat = 4; //2
	int Submarine = 1; //3
	int Cruiser = 2; //3
	int Battleship = 2; //4
	int Carrier = 1; //5
	int MaxShips = 10;
public:
	/*Board() {

	}*/
	int Check_Ship(int length) {
		int qt=0;
		switch (length)
		{
		case 2:
			qt = 4;
			break;
		case 3:
			qt = 3;
			break;
		case 4:
			qt = 2;
			break;
		case 5:
			qt = 1;
			break;
		default:
			break;
		}
		return qt;
	}
};

int main() {
	srand(time(0));
	Boards tablica;
	ShipsAi ai;
	ShipsPlayer gracz;
	Attack atak;
	tablica.Clear_Board();
	ai.SetShipsAi();
	cout << "dziala\n";
	char** arr = ai.GetAiBoard();
	tablica.Show_Board(arr);
	atak.Atak(arr);
	tablica.Show_Board(arr);

	return 0;
}