#pragma once
#include "Boards.h"
#include "Ships.h"
class ShipsAi
{
private:
	Boards tab;
public:
	void SetShipsAi(Ships statki[]);
	void SetCoordinatesAi(int lenght, int qt, Ships statki[]);
	char** GetAiBoard();

};

