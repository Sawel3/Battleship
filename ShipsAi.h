#pragma once
#include "Boards.h"
class ShipsAi
{
private:
	Boards tab;
public:
	void SetShipsAi();
	void SetCoordinatesAi(int lenght, int qt);
	char** GetAiBoard();

};

