#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "ShipsAi.h"
#include "Boards.h"
#include "Attack.h"
#include "ShipsPlayer.h"
#include "Ships.h"

using namespace std;
Ships statki[10];

int main() {
	srand(time(0));
	Boards tablica;
	ShipsAi ai;
	ShipsPlayer gracz;
	Attack atak;  
	tablica.Clear_Board();
	ai.SetShipsAi(statki);
	cout << "dziala\n";
	char** arr = ai.GetAiBoard();
	tablica.Show_Board(arr);
	atak.Atak(arr,statki);
	tablica.Show_Board(arr);
	// if win
	
	return 0;
}
