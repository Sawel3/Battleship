#pragma once
#include<iostream>
#include "Boards.h"
#include "Ships.h"
using namespace std;
class ShipsAi{
private:
	Boards tab;
	int N = tab.GetN();
	char** board;
	int licz = 0;
public:
	void SetShipsAi(Ships statki[]);
	void SetCoordinatesAi(int lenght, int qt, Ships statki[]);
	char** GetAiBoard();
};
