#include <iostream>
#include "Attack.h"
using namespace std;

void Attack::Atak(char** AiRealBoard, Ships statki[], char** AiVisibleBoard, char** PlayerBoard) {
	bool trafiony=true, over=false;
	int strzaly=true,x,y;
	while (trafiony==true && over==false)
	{
		cin >> x >> y;
		if (AiRealBoard[y][x] == 'x')
		{
			cout << "trafiony\n";
			AiRealBoard[y][x] = 'T';
			AiVisibleBoard[y][x] = 'X';
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
			tab.ShowTwoBoard(AiVisibleBoard,PlayerBoard);
			tab.Show_Board(AiRealBoard);
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
void Attack::AiAtak(char** PlayerBoard, Ships statki[], char** AiVisibleBoard) {
	bool trafiony = true, over = false;
	int strzaly = true, x, y;
	while (trafiony == true && over == false)
	{
		x = rand() % N;
		y = rand() % N;
		if (PlayerBoard[y][x] == 'x')
		{
			cout << "trafiony\n";
			PlayerBoard[y][x] = 'T';
			trafiony = true;
			for (int i = 0; i < 10; i++)
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
			tab.ShowTwoBoard(AiVisibleBoard, PlayerBoard);
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
	
