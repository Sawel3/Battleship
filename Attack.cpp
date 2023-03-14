#include <iostream>
#include "Attack.h"
using namespace std;

void Attack::Atak(char** board) {
	bool trafiony=true;
	int strzaly=true,x,y;
	while (trafiony==true)
	{
		cin >> x >> y;
		if (board[y][x] == 'x')
		{
			cout << "trafiony\n";
			board[y][x] = 'T';
			trafiony = true;
			tab.Show_Board(board);
			continue;
		}
		else
		{
			trafiony = false;
			cout << "pudlo\n";
			break;
		}
	}
}
	
