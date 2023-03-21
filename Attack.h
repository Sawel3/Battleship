#pragma once
#include "Boards.h"
#include "Ships.h"
class Attack
{
private:
	Boards tab;
public:
	void Atak(char **board, Ships statki[], char** ndboard, char** rdboard);
	void AiAtak(char** board, Ships statki[], char** ndboard);
};

