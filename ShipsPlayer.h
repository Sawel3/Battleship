#pragma once
#include<iostream>
#include "Boards.h"
#include "Ships.h"
#include "console.h"
#include <Windows.h>
using namespace std;
class ShipsPlayer{
private:
	Boards tab;
	console consol;
	int N = tab.GetN();
	char** board;
	int licz = 0;
public:
	void SetShips(Ships statki[]);
	void SetCoordinates(int lenght, int qt, Ships statki[]);
	char** GetBoard();
};

