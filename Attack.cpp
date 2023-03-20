#include <iostream>
#include "Attack.h"
using namespace std;

void Attack::Atak(char** board, Ships statki[]) {
	bool trafiony=true, over=false;
	int strzaly=true,x,y;
	while (trafiony==true && over==false)
	{
		cin >> x >> y;
		if (board[y][x] == 'x')
		{
			cout << "trafiony\n";
			board[y][x] = 'T';
			trafiony = true;
			for (int  i = 0; i < 10; i++)
			{
				if (statki[i].IsDestroyed() == true) {
					cout << "zniszczony\n";
					int win = 0;
					for (int i = 0; i < 10; i++)
					{
						if (statki[i].isDestroyed) {
							win++;
						}
					}
					if (win == 10)
					{
						over = true;
						cout << "Wygrales farajerze essa na noba\n";
						exit(0);
						
					}
				};
			}
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
	
