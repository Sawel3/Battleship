#pragma once
#include<iostream>
#include "Boards.h"
#include "Ships.h"
using namespace std;
class ShipsPlayer{
private:
	Boards tab;
	int N = tab.GetN();
	char** board;
	int licz = 0;
public:
	void SetShips(Ships statki[]);
	void SetCoordinates(int lenght, int qt, Ships statki[]);
	char** GetBoard();
};

