#pragma once
#include <iostream>
#include "Boards.h"
#include "Ships.h"
#include <stdlib.h>
using namespace std;
class Attack
{
private:
	Boards tab;
	int N = tab.GetN();
public:
	void Atak(char **board, Ships statki[], char** ndboard, char** rdboard);
	void AiAtak(char** board, Ships statki[], char** ndboard);
};

