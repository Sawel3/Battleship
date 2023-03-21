#pragma once
#include<iostream>
#include "Boards.h"
using namespace std;
class ShipsPlayer
{
private:
	Boards tab;
	int N = tab.GetN();
public:
	void SetShips();
	void SetCoordinates(int lenght, int qt);
};

