#include "Attack.h"
void Attack::Atak(char** AiRealBoard, Ships statki[], char** AiVisibleBoard, char** PlayerBoard) {
	bool trafiony=true, over=false;
	int strzaly=true,x,y;
	string point;
	while (trafiony==true && over==false)
	{
		cin >> point;
		if (point.length() != 2) {
			cout << "Cos zle wpisales mordo!!!\n";
			continue;
		}
		if (point[0] < 65 || point[0]>74)
		{
			cout << "Cos zle wpisales mordo!!!\n";
			continue;
		}
		
		x = point[1] - 49;
		if (point[2] == '0')
		{
			y = 9;
		}
		else
		{
			y = abs(65 - point[0]);
		}
		if (x<0||x>10||y<0||y>10)
		{
			cout << "Zle wybrales\n";
			cout << "Przyklad "<<char(74-rand()%10)<<10-rand()%9<<endl;
			continue;
		}
		else
		{
			if (AiRealBoard[y][x] == 'x')
			{
				cout << "trafiony\n";
				AiRealBoard[y][x] = 'T';
				AiVisibleBoard[y][x] = 'X';
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
	
