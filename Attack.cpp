#include <iostream>
#include "Attack.h"
using namespace std;

Attack::Attack(int x, int y, char** board) {
	bool trafiony=true;
	int strzaly=true;
	while (trafiony==true)
	{
		if (board[x][y] == 'x')
		{
			cout << "trafiony\n";
			board[x][y] = 'X';
			trafiony = true;
		}
		else
		{
			trafiony = false;
			cout << "pudlo\n";
			break;
		}
	}
}
	
