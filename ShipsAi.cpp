#include<iostream>
#include "ShipsAi.h"
using namespace std;
char** board;
int licz=0;

void ShipsAi::SetCoordinatesAi(int lenght, int qt, Ships statki[]) {
	int nb = 0, xp, yp, xk, yk, granica = 0, granica2=0, granica3 =0, granica4=0, granica5=0;
	char** board = tab.GetBoard();
	int N = tab.GetN();
	while (nb < qt) {
		bool blad=false;
		yp = rand() % N;
		/*cout << "yp=" << yp << endl;*/
		xp = rand() % N;
		/*cout << "xp=" << xp << endl;*/
		yk = rand() % N;
		/*cout << "yk=" << yk << endl;*/
		xk = rand() % N;
		/*cout << "xk=" << xk << endl;*/
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
		/*cout << "rozx=" << rozx << endl;*/
		int rozy = (yk - yp) + 1;
		/*cout << "rozy=" << rozy << endl;*/
		if (rozx != lenght && rozy != lenght)
		{
			/*board[xp][yp] = 0 + '  ';
			board[xk][yk] = 0 + '  ';*/
			/*cout << "chuj\n";*/
			continue;
		}
		else if (yp == yk)
		{
			/*cout << rozx << endl << xp << endl << xk << endl;*/
			for (int i = xp; i <= xk; i++)
			{
				/*cout << i << "forx\n";*/
				if (board[i][yp] == 'x') {
					/*cout << "zajete\n";*/
					blad = true;
					break;
				}
			}
			for (int i = xp; i <= xk; i++)
			{
				/*cout << i << "forOx\n";*/
				if (i!=0 && i!= (N - 1) && yp!=0 && yp!= (N - 1))
				{
					if (board[i - 1][yp] == 'x' || board[i + 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp - 1] == 'x' || board[i + 1][yp - 1] == 'x' || board[i - 1][yp + 1] == 'x' || board[i + 1][yp + 1] == 'x') {

						/*cout << "graniczy\n";*/
						blad = true;
						granica += 1;
						break;
					}
				}
				else if (i==0 && yp ==0)
				{
					if (board[i+1][yp] == 'x' || board [i][yp+1]=='x' || board[i+1][yp + 1] == 'x')
					{
						/*cout << "graniczy2\n";*/
						granica2 += 1;
						blad = true;
						break;
					}
				}
				else if (i== (N - 1) && yp ==0)
				{
					if (board[i-1][yp]=='x'||board[i][yp+1]=='x' || board[i - 1][yp + 1] == 'x')
					{
						/*cout << "graniczy3\n";*/
						granica3 += 1;
						blad = true;
						break;
					}
				}
				else if (i == (N - 1) && yp == (N - 1))
				{
					if (board[i - 1][yp] == 'x' || board[i][yp - 1]=='x' || board[i - 1][yp - 1] == 'x')
					{
						/*cout << "graniczy4\n";*/
						granica4 += 1;
						blad = true;
						break;
					}
				}
				else if (i == 0 && yp == (N - 1))
				{
					if (board[i + 1][yp] == 'x' || board[i][yp - 1]=='x' || board[i + 1][yp - 1] == 'x')
					{
						/*cout << "graniczy5\n";*/
						granica5 += 1;
						blad = true;
						break;
					}
				}
				else if(i == 0)
				{
					if (board[i + 1][yp] == 'x' || board[i + 1][yp + 1] == 'x' || board[i][yp + 1] == 'x' || board[i +1 ][yp - 1] == 'x' || board[i][yp - 1] == 'x')
					{
						/*cout << "graniczy5\n";*/
						granica5 += 1;
						blad = true;
						break;
					}
				}
				else if (i == N-1)
				{
					if (board[i - 1][yp] == 'x' || board[i - 1][yp + 1] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp - 1] == 'x' || board[i][yp - 1] == 'x')
					{
						/*cout << "graniczy5\n";*/
						granica5 += 1;
						blad = true;
						break;
					}
				}
				else if (yp == 0)
				{
					if (board[i - 1][yp] == 'x' || board[i + 1][yp] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp + 1] == 'x' || board[i + 1][yp + 1] == 'x') {

						/*cout << "graniczy\n";*/
						blad = true;
						granica += 1;
						break;
					}
				}
				else if (yp == N-1)
				{
					if (board[i - 1][yp] == 'x' || board[i + 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i - 1][yp - 1] == 'x' || board[i + 1][yp - 1] == 'x') {

						/*cout << "graniczy\n";*/
						blad = true;
						granica += 1;
						break;
					}
				}	
			}
			if (blad == false) {
				int j = 0;
				for (int i = xp; i <= xk; i++)
				{
					/*cout << i << "for\n";*/
					if (board[i][yp] != 'x')
					{
						/*cout <<i<< "if\n";*/
						board[i][yp] = 'x';
						statki[licz].statki[j] = &board[i][yp];
						j++;
						/*tab.Show_Board();*/
					}
				}
				/*tab.Show_Board();*/
				nb++;
				licz++;
				/*statki++;*/
			}
		}
		else if (xp == xk)
		{
			/*cout << rozy << endl << xp << endl << xk << endl;;*/
			for (int i = yp; i <= yk; i++)
			{
				/*cout << i << "forx\n";*/
				if (board[xp][i] == 'x')
				{
					/*cout << "zajete\n";*/
					blad = true;
					break;
				}
			}
			for (int i = yp; i <= yk; i++)
			{
				/*cout << i << "forOx\n";*/
				//if przy krawedzi x=0 lub y=0 lub x=max lub y=max
				//if czy w rogu
				if (i != 0 && i != (N - 1) && xp != 0 && xp != (N - 1))
				{
					if (board[xp - 1][i] == 'x' || board[xp + 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i - 1] == 'x' || board[xp + 1][i - 1] == 'x' || board[xp - 1][i + 1] == 'x' || board[xp + 1][i + 1] == 'x') {
						/*cout << "graniczy\n";*/
						granica += 1;
						blad = true;
						break;
					}
				}
				else if (i == 0 && xp == 0)
				{
					if (board[xp + 1][i] == 'x' || board[xp][i + 1]=='x' || board[xp + 1][i + 1] == 'x')
					{
						/*cout << "graniczy2\n";*/
						granica2 += 1;
						blad = true;
						break;
					}
				}
				else if (i == 0 && xp == (N - 1))
				{
					if (board[xp - 1][i] == 'x' || board[xp][i + 1]=='x' || board[xp - 1][i + 1] == 'x')
					{
						/*cout << "graniczy3\n";*/
						granica3 += 1;
						blad = true;
						break;
					}
				}
				else if (i == (N - 1) && xp == (N - 1))
				{
					if (board[xp - 1][i] == 'x' || board[xp][i - 1]=='x' || board[xp - 1][i - 1] == 'x')
					{
						/*cout << "graniczy4\n";*/
						granica4 += 1;
						blad = true;
						break;
					}
				}
				else if (i == (N-1) && xp == 0)
				{
					if (board[xp + 1][i] == 'x' || board[xp][i - 1]=='x' || board[xp + 1][i - 1] == 'x')
					{
						/*cout << "graniczy5\n";*/
						granica5 += 1;
						blad = true;
						break;
					}
				}
				else if (i == 0)
				{
					if (board[xp - 1][i] == 'x' || board[xp + 1][i] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i + 1] == 'x' || board[xp + 1][i + 1] == 'x') {
						/*cout << "graniczy\n";*/
						granica += 1;
						blad = true;
						break;
					}
				}
				else if (i == N - 1) {
					if (board[xp - 1][i] == 'x' || board[xp + 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp - 1][i - 1] == 'x' || board[xp + 1][i - 1] == 'x') {
						/*cout << "graniczy\n";*/
						granica += 1;
						blad = true;
						break;
					}
				}
				else if (xp == 0) {
					if (board[xp + 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp][i + 1] == 'x' || board[xp + 1][i - 1] == 'x' || board[xp + 1][i + 1] == 'x') {
						/*cout << "graniczy\n";*/
						granica += 1;
						blad = true;
						break;
					}
				}
				else if (xp == N - 1) {
					if (board[xp - 1][i] == 'x'|| board[xp][i - 1] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i - 1] == 'x' || board[xp - 1][i + 1] == 'x') {
						/*cout << "graniczy\n";*/
						granica += 1;
						blad = true;
						break;
					}
				}
				
			}
			if (blad == false) {
				int j = 0;
				for (int i = yp; i <= yk; i++)
				{
					/*cout << i << "for\n";*/
					if (board[xp][i] != 'x')
					{
						/*cout << "if\n";*/
						board[xp][i] = 'x';
						statki[licz].statki[j]=&board[xp][i];
						j++;
						/*tab.Show_Board();*/
					}
				}
				/*tab.Show_Board();*/
				nb++;
				licz++;
				/*cout << licz << endl;*/
				/*statki++;*/
			}
		}
		else {
			/*board[xp][yp] = 0 + '  ';
			board[xk][yk] = 0 + '  ';*/
			/*cout << "chujowo wybrales\n";*/
		}
		/*cout << "liczba=" << nb << endl;*/
	}
	/*cout << granica << endl << granica2 << endl << granica3 << endl << granica4 << endl << granica5 << endl;*/
}
void ShipsAi::SetShipsAi(Ships statki[]) {
	
	//carrier
	SetCoordinatesAi(5, 1, statki);
	
	/*tab.Show_Board();*/
	//battleship
	SetCoordinatesAi(4, 2, statki);
	/*tab.Show_Board();*/
	//cruiser
	SetCoordinatesAi(3, 2, statki);
	/*tab.Show_Board();*/
	//submarine
	SetCoordinatesAi(3, 1, statki);
	//patrol boat
	SetCoordinatesAi(2, 4, statki);
	/*tab.Show_Board();*/
}
char** ShipsAi::GetAiBoard() {
	char** arr = tab.GetBoard();
	return arr;
}