#include "ShipsPlayer.h"
void ShipsPlayer::SetCoordinates(int lenght, int qt, Ships statki[]) {
	int nb = 0, xp, yp, xk, yk, granica = 0, granica2 = 0, granica3 = 0, granica4 = 0, granica5 = 0;
	board = tab.GetBoard();
	while (nb < qt) {
		bool blad = false;
		cout << "poczatkowe[x,y]\n";
		cin >> yp >> xp;
		board[xp][yp] = 'C';
		tab.Show_Board(board);
		cout << "koncowe[x,y]\n";
		cin >> yk >> xk;
		board[xk][yk] = 'C';
		tab.Show_Board(board);
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
		if (rozx != lenght && rozy != lenght)
		{
			/*board[xp][yp] = 0 + '  ';
			board[xk][yk] = 0 + '  ';*/
			cout << "Zle wymiary statku\n Podaj pownownie\n";
			continue;
		}
		else if (yp == yk)
		{
			cout << rozx << endl << xp << endl << xk << endl;
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
				if (i != 0 && i != (N - 1) && yp != 0 && yp != (N - 1))
				{
					if (board[i - 1][yp] == 'x' || board[i + 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp - 1] == 'x' || board[i + 1][yp - 1] == 'x' || board[i - 1][yp + 1] == 'x' || board[i + 1][yp + 1] == 'x') {

						/*cout << "graniczy\n";*/
						blad = true;
						granica += 1;
						break;
					}
				}
				else if (i == 0 && yp == 0)
				{
					if (board[i + 1][yp] == 'x' || board[i][yp + 1] == 'x' || board[i + 1][yp + 1] == 'x')
					{
						/*cout << "graniczy2\n";*/
						granica2 += 1;
						blad = true;
						break;
					}
				}
				else if (i == (N - 1) && yp == 0)
				{
					if (board[i - 1][yp] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp + 1] == 'x')
					{
						/*cout << "graniczy3\n";*/
						granica3 += 1;
						blad = true;
						break;
					}
				}
				else if (i == (N - 1) && yp == (N - 1))
				{
					if (board[i - 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i - 1][yp - 1] == 'x')
					{
						/*cout << "graniczy4\n";*/
						granica4 += 1;
						blad = true;
						break;
					}
				}
				else if (i == 0 && yp == (N - 1))
				{
					if (board[i + 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i + 1][yp - 1] == 'x')
					{
						/*cout << "graniczy5\n";*/
						granica5 += 1;
						blad = true;
						break;
					}
				}
				else if (i == 0)
				{
					if (board[i + 1][yp] == 'x' || board[i + 1][yp + 1] == 'x' || board[i][yp + 1] == 'x' || board[i + 1][yp - 1] == 'x' || board[i][yp - 1] == 'x')
					{
						/*cout << "graniczy5\n";*/
						granica5 += 1;
						blad = true;
						break;
					}
				}
				else if (i == N - 1)
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
				else if (yp == N - 1)
				{
					if (board[i - 1][yp] == 'x' || board[i + 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i - 1][yp - 1] == 'x' || board[i + 1][yp - 1] == 'x') {

						/*cout << "graniczy\n";*/
						blad = true;
						granica += 1;
						break;
					}
				}
			}
			if(blad==false){
				int j = 0;
				for (int i = xp; i <= xk; i++)
				{
					if (board[i][yp] != 'x')
					{
						board[i][yp] = 'x';
						statki[licz].statki[j] = &board[i][yp];
						j++;
					}
				}
				tab.Show_Board(board);
				nb++;
				licz++;
			}
		}
		else if (xp == xk)
		{
			cout << rozy << endl << xp << endl << xk << endl;;
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
					if (board[xp + 1][i] == 'x' || board[xp][i + 1] == 'x' || board[xp + 1][i + 1] == 'x')
					{
						/*cout << "graniczy2\n";*/
						granica2 += 1;
						blad = true;
						break;
					}
				}
				else if (i == 0 && xp == (N - 1))
				{
					if (board[xp - 1][i] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i + 1] == 'x')
					{
						/*cout << "graniczy3\n";*/
						granica3 += 1;
						blad = true;
						break;
					}
				}
				else if (i == (N - 1) && xp == (N - 1))
				{
					if (board[xp - 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp - 1][i - 1] == 'x')
					{
						/*cout << "graniczy4\n";*/
						granica4 += 1;
						blad = true;
						break;
					}
				}
				else if (i == (N - 1) && xp == 0)
				{
					if (board[xp + 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp + 1][i - 1] == 'x')
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
					if (board[xp - 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i - 1] == 'x' || board[xp - 1][i + 1] == 'x') {
						/*cout << "graniczy\n";*/
						granica += 1;
						blad = true;
						break;
					}
				}

			}
			if(blad==false){
				int j = 0;
				for (int i = yp; i <= yk; i++)
				{
					if (board[xp][i] != 'x')
					{
						board[xp][i] = 'x';
						statki[licz].statki[j] = &board[xp][i];
						j++;
					}
				}
				tab.Show_Board(board);
				nb++;
				licz++;
			}
		}
		else {
			/*board[xp][yp] = 0 + '  ';
			board[xk][yk] = 0 + '  ';*/
			cout << "chujowo wybrales\n";
		}
		cout << nb << endl;
		tab.Show_Board(board);
	}
}
void ShipsPlayer::SetShips(Ships statki[]) {
	//carrier
	cout << "Wprowadz koordynaty dla carriera\n";
	SetCoordinates(5, 1, statki);
	//battleship
	cout << "Wprowadz koordynaty dla battleshipa\n";
	SetCoordinates(4, 2, statki);
	//cruiser
	cout << "Wprowadz koordynaty dla cruisera\n";
	SetCoordinates(3, 2, statki);
	//submarine
	cout << "Wprowadz koordynaty dla submarine\n";
	SetCoordinates(3, 1, statki);
	//patrol boat
	cout << "Wprowadz koordynaty dla patrola\n";
	SetCoordinates(2, 4, statki);
}
char** ShipsPlayer::GetAiBoard() {
	char** arr = tab.GetBoard();
	return arr;
}