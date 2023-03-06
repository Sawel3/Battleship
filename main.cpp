#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;
class Ships
{
private:
	int Patrol_boat=4; //2
	int Submarine=1; //3
	int Cruiser=2; //3
	int Battleship=2; //4
	int Carrier=1; //5
	int MaxShips = 10;
public:


};
class Board
{
private:
	const static int N = 10;
	char board[N][N];
	int Patrol_boat = 4; //2
	int Submarine = 1; //3
	int Cruiser = 2; //3
	int Battleship = 2; //4
	int Carrier = 1; //5
	int MaxShips = 10;
public:
	/*Board() {

	}*/
	void Show_Board() {
		char a = 'A';
		int b = 0;
		for (int i = 0; i < N; i++)
		{
			if (i == 0) {
				cout << "     | ";
				for (int j = 0; j < N; j++)
				{
					cout << j << " | ";
				}
				cout << endl<<"_______________________________________________\n";
			}
			for (int j = 0; j < N; j++)
			{
				if (j==0)
				{
					cout <<" " << a<<" " << b << " | ";
					a += 1;
					b++;
				}
				
				cout << board[i][j]/*<<"[" << i <<"," << j << "]" */<< " | ";
			}
			cout << endl;
		}
		cout << "_______________________________________________\n";
	}
	void SetShips() {
		//carrier
		cout << "Wprowadz koordynaty dla carriera\n";
		SetCoordinates(5,1);
		//battleship
		cout << "Wprowadz koordynaty dla battleshipa\n";
		SetCoordinates(4,2);
		//cruiser
		cout << "Wprowadz koordynaty dla cruisera\n";
		SetCoordinates(3,2);
		//submarine
		cout << "Wprowadz koordynaty dla submarine\n";
		SetCoordinates(3,1);
		//patrol boat
		cout << "Wprowadz koordynaty dla patrola\n";
		SetCoordinates(2,4);
	}
	void SetCoordinates(int lenght,int qt) {
		int nb = 0, xp, yp, xk, yk;
		while (nb < qt) {
			
			cout << "poczatkowe[x,y]\n";
			cin >> yp >> xp;
			board[xp][yp] = 'C';
			Show_Board();
			cout << "koncowe[x,y]\n";
			cin >> yk >> xk;
			board[xk][yk] = 'C';
			Show_Board();
			cout << "______\n";
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
			int rozy = (yk - yp) + 1;
			if (rozx!=lenght && rozy!=lenght)
			{
				board[xp][yp] = 0 + '  ';
				board[xk][yk] = 0 + '  ';
				cout << "Zle wymiary statku\n Podaj pownownie\n";
				continue;
			}
			if (yp == yk)
			{
				cout << rozx << endl << xp << endl<<xk<<endl;
				for (int i = xp; i <= xk; i++)
				{
					cout << i << "for\n";
					if (board[i][yp] != 'x')
					{
						cout << "if\n";
						board[i][yp] = 'x';
					}
				}
				nb++;

			}
			else if (xp == xk)
			{
				cout << rozy << endl << xp << endl << xk << endl;;
				for (int i = yp; i <= yk; i++)
				{
					cout << i << "for\n";
					if (board[xp][i] != 'x')
					{
						cout << "if\n";
						board[xp][i] = 'x';
					}
				}
				nb++;
			}
			else {
				board[xp][yp] = 0 + '  ';
				board[xk][yk] = 0 + '  ';
				cout << "chujowo wybrales\n";
			}
			cout << nb<<endl;
			Show_Board();
		}
	}
	int Check_Ship(int length) {
		int qt=0;
		switch (length)
		{
		case 2:
			qt = 4;
			break;
		case 3:
			qt = 3;
			break;
		case 4:
			qt = 2;
			break;
		case 5:
			qt = 1;
			break;
		default:
			break;
		}
		return qt;
	}
	void Clear_Board() {
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				board[i][j] = 0+'  ';
			}
		}
	};
	void SetShipsAi() {
		//carrier
		SetCoordinatesAi(5, 1);
		Show_Board();
		//battleship
		SetCoordinatesAi(4, 2);
		Show_Board();
		//cruiser
		SetCoordinatesAi(3, 2);
		Show_Board();
		//submarine
		SetCoordinatesAi(3, 1);
		//patrol boat
		SetCoordinatesAi(2, 4);
		Show_Board();
	}
	void SetCoordinatesAi(int lenght, int qt) {
		int nb = 0, xp, yp, xk, yk;
		while (nb < qt) {
			bool blad = false;
			yp = rand() % N;
			cout <<"yp=" << yp << endl;
			xp= rand() % N;
			cout <<"xp="<< xp << endl;
			yk=rand() % N;
			cout <<"yk="<< yk << endl;
			xk= rand() % N;
			cout <<"xk="<< xk << endl;
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
					if (board[i - 1][yp] == 'x' || board[i + 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp - 1] == 'x' || board[i + 1][yp - 1] == 'x' || board[i - 1][yp + 1] == 'x' || board[i + 1][yp + 1] == 'x') {

						cout << "graniczy\n";
						blad = true;
						break;
					}
				}
				if (blad == false){
					for (int i = xp; i <= xk; i++)
					{
						cout << i << "for\n";
						if (board[i][yp] != 'x')
						{
							cout << "if\n";
							board[i][yp] = 'x';
						}
					}
					Show_Board();
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
					Show_Board();
					nb++;
				}
			}
			else {
				/*board[xp][yp] = 0 + '  ';
				board[xk][yk] = 0 + '  ';*/
				cout << "chujowo wybrales\n";
			}
			cout <<"liczba="<< nb << endl;
		}
	}
};

int main() {
	srand(time(0));
	Board gracz1;
	gracz1.Clear_Board();
	gracz1.Show_Board();
	gracz1.SetShipsAi();
	
	return 0;
}