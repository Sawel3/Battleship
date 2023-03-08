#include<iostream>
#include "ShipsAi.h"
using namespace std;
void ShipsAi::SetCoordinatesAi(int lenght, int qt) {
	int nb = 0, xp, yp, xk, yk;
	char** board = tab.GetBoard();
	int N = tab.GetN();
	while (nb < qt) {
		bool blad=false, granica = false;
		yp = rand() % N;
		cout << "yp=" << yp << endl;
		xp = rand() % N;
		cout << "xp=" << xp << endl;
		yk = rand() % N;
		cout << "yk=" << yk << endl;
		xk = rand() % N;
		cout << "xk=" << xk << endl;
		if (xk < xp)
		{
			int temp = xk;
			xk = xp;
			xp = temp;
		}
		if (yk < yp)
		{
			int temp = yk;
			yk = yp;
			yp = temp;
		}
		int rozx = (xk - xp) + 1;
		cout << "rozx=" << rozx << endl;
		int rozy = (yk - yp) + 1;
		cout << "rozy=" << rozy << endl;
		if (rozx != lenght && rozy != lenght)
		{
			/*board[xp][yp] = 0 + '  ';
			board[xk][yk] = 0 + '  ';*/
			cout << "chuj\n";
			continue;
		}
		else if (yp == yk)
		{
			cout << rozx << endl << xp << endl << xk << endl;
			for (int i = xp; i <= xk; i++)
			{
				cout << i << "forx\n";
				if (board[i][yp] == 'x') {
					cout << "zajete\n";
					blad = true;
					break;
				}
			}
			for (int i = xp; i <= xk; i++)
			{
				cout << i << "forOx\n";
				if (i!=0 && i!=N && yp!=0 && yp!=N)
				{
					if (board[i - 1][yp] == 'x' || board[i + 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp - 1] == 'x' || board[i + 1][yp - 1] == 'x' || board[i - 1][yp + 1] == 'x' || board[i + 1][yp + 1] == 'x') {

						cout << "graniczy\n";
						blad = true;
						break;
					}
				}
				else if ()
				{

				}
				else if (true)
				{

				}
				
			}
			if (blad == false) {
				for (int i = xp; i <= xk; i++)
				{
					cout << i << "for\n";
					if (board[i][yp] != 'x')
					{
						cout << "if\n";
						board[i][yp] = 'x';
					}
				}
				tab.Show_Board();
				nb++;
			}
		}
		else if (xp == xk)
		{
			cout << rozy << endl << xp << endl << xk << endl;;
			for (int i = yp; i <= yk; i++)
			{
				cout << i << "forx\n";
				if (board[xp][i] == 'x')
				{
					cout << "zajete\n";
					blad = true;
					break;
				}
			}
			for (int i = yp; i <= yk; i++)
			{
				cout << i << "forOx\n";
				//if przy krawedzi x=0 lub y=0 lub x=max lub y=max
				//if czy w rogu 
				if (board[xp - 1][i] == 'x' || board[xp + 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i - 1] == 'x' || board[xp + 1][i - 1] == 'x' || board[xp - 1][i + 1] == 'x' || board[xp + 1][i + 1] == 'x') {
					cout << "graniczy\n";
					blad = true;
					break;
				}
			}
			if (blad == false) {
				for (int i = yp; i <= yk; i++)
				{
					cout << i << "for\n";
					if (board[xp][i] != 'x')
					{
						cout << "if\n";
						board[xp][i] = 'x';
					}
				}
				tab.Show_Board();
				nb++;
			}
		}
		else {
			/*board[xp][yp] = 0 + '  ';
			board[xk][yk] = 0 + '  ';*/
			cout << "chujowo wybrales\n";
		}
		cout << "liczba=" << nb << endl;
	}
}
void ShipsAi::SetShipsAi() {
	//carrier
	SetCoordinatesAi(5, 1);
	tab.Show_Board();
	//battleship
	SetCoordinatesAi(4, 2);
	tab.Show_Board();
	//cruiser
	SetCoordinatesAi(3, 2);
	tab.Show_Board();
	//submarine
	SetCoordinatesAi(3, 1);
	//patrol boat
	SetCoordinatesAi(2, 4);
	tab.Show_Board();
}