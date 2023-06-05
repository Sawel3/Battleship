#pragma once
/**
 * \file   Attack.h
 * \brief  Header file for Attack
*/
#include <iostream>
#include "Boards.h"
#include "Ships.h"
#include <stdlib.h>
#include "console.h"
using namespace std;
class Attack {
private:
	console consol;
	Boards tab;
	int N = tab.GetN();
public:
	void Atak(char** board, Ships statki[], char** ndboard, char** rdboard);
	void AiAtak(char** board, Ships statki[], char** ndboard);
};

