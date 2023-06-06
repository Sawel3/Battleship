#include "ShipsPlayer.h"
/// <summary>
/// Sets the coordinates.
/// </summary>
/// <param name="lenght">The lenght of the ship.</param>
/// <param name="qt">The quantity of ships.</param>
/// <param name="statki">The statki.</param>
void ShipsPlayer::SetCoordinates(int lenght, int qt, Ships statki[]) {
	int nb = 0, xp, yp, xk, yk;
	string beg, end;
	bool blad=false,size=false;
	board = tab.GetBoard();
	while (nb < qt) {
		consol.ClearConsoleFromSecondLine();
		if (blad==true) cout << "graniczy lub pole zajete wprowadz ponownie\n";
		else if (size==true) cout << "zle wymiary statku\n";
		size = false;
		blad = false;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (board[i][j] == 'C') board[i][j] = ' ';
			}
		}
		tab.Show_Board(board);
		cout << "poczatkowe\nprzyklad:  "<< char(74 - rand() % 10) << 10 - rand() % 9<<endl;
		cin >> beg;
		if (beg.length() > 3 || beg.length() < 0) {
			size = true;
			continue;
		}
		else if (beg.length() != 3 && beg.length() != 2){
			size = true;
			continue;
		}
		if (beg[0] < 65 || beg[0]>74){
			size = true;
			continue;
		}
		if (beg[2]=='0'&&beg[1]=='1') yp = 9;
		else yp=beg[1] - 49;
		xp = abs(65 - beg[0]);
		if (board[xp][yp] == 'x') {
			blad = true;
			continue;
		}
		else if (xp != 0 && xp != (N - 1) && yp != 0 && yp != (N - 1)){
			if (board[xp - 1][yp] == 'x' || board[xp + 1][yp] == 'x' || board[xp][yp - 1] == 'x' || board[xp][yp + 1] == 'x' || board[xp - 1][yp - 1] == 'x' || board[xp + 1][yp - 1] == 'x' || board[xp - 1][yp + 1] == 'x' || board[xp + 1][yp + 1] == 'x') {
				blad = true;
				continue;
			}
		}
		else if (xp == (N - 1) && yp == 0){
			if (board[xp - 1][yp] == 'x' || board[xp][yp + 1] == 'x' || board[xp - 1][yp + 1] == 'x'){
				blad = true;
				continue;
			}
		}
		else if (xp == (N - 1) && yp == (N - 1)){
			if (board[xp - 1][yp] == 'x' || board[xp][yp - 1] == 'x' || board[xp - 1][yp - 1] == 'x'){
				blad = true;
				continue;
			}
		}
		else if (xp == 0 && yp == (N - 1)){
			if (board[xp + 1][yp] == 'x' || board[xp][yp - 1] == 'x' || board[xp + 1][yp - 1] == 'x'){
				blad = true;
				continue;
			}
		}
		else if (xp == 0){
			if (board[xp + 1][yp] == 'x' || board[xp + 1][yp + 1] == 'x' || board[xp][yp + 1] == 'x' || board[xp + 1][yp - 1] == 'x' || board[xp][yp - 1] == 'x'){
				blad = true;
				continue;
			}
		}
		else if (xp == N - 1){
			if (board[xp - 1][yp] == 'x' || board[xp - 1][yp + 1] == 'x' || board[xp][yp + 1] == 'x' || board[xp - 1][yp - 1] == 'x' || board[xp][yp - 1] == 'x'){
				blad = true;
				continue;
			}
		}
		else if (yp == 0){
			if (board[xp - 1][yp] == 'x' || board[xp + 1][yp] == 'x' || board[xp][yp + 1] == 'x' || board[xp - 1][yp + 1] == 'x' || board[xp + 1][yp + 1] == 'x') {
				blad = true;
				continue;
			}
		}
		else if (yp == N - 1){
			if (board[xp - 1][yp] == 'x' || board[xp + 1][yp] == 'x' || board[xp][yp - 1] == 'x' || board[xp - 1][yp - 1] == 'x' || board[xp + 1][yp - 1] == 'x') {
				blad = true;
				continue;
			}
		}
		consol.ClearConsoleFromSecondLine();
		board[xp][yp] = 'C';
		tab.Show_Board(board);
		cout << "koncowe\nprzyklad: " << char(74 - rand() % 10) << 10 - rand() % 9 << endl;
		cin >> end;
		cout << end.length() << endl;
		if (end.length() > 3 || end.length() < 0) {
			size = true;
			continue;
		}
		else if(end.length() != 3 && end.length() != 2){
			size = true;
			continue;
		}
		if (end[0] < 65 || end[0]>74){
			size = true;
			continue;
		}
		if (end[2]=='0')yk = 9;
		else yk = end[1] - 49;
		xk = abs(65 - end[0]);
		if (board[xk][yk] == 'x') {
			blad = true;
			continue;
		}
		board[xk][yk] = 'C';
		tab.Show_Board(board);
		cout << "______\n";
		if (xp < 0 || xp>10 || xk < 0 || xk>10 || yp < 0 || yp>10 || yk < 0 || yk>10) {
			cout << "Przyklad " << char(74 - rand() % 10) << 10 - rand() % 9 << endl;
			size = true;
			continue;
		}
		else{
			if (xk < xp){
				int temp = xk;
				xk = xp;
				xp = temp;
			}
			if (yk < yp){
				int temp = yk;
				yk = yp;
				yp = temp;
			}
			int rozx = (xk - xp) + 1;
			int rozy = (yk - yp) + 1;
			if (rozx != lenght && rozy != lenght){
				size = true;
				continue;
			}
			else if (yp == yk){
				for (int i = xp; i <= xk; i++){
					if (board[i][yp] == 'x') {
						board[xp][yp] = 'x';
						board[xk][yk] = 'x';
						blad = true;
						break;
					}
				}
				for (int i = xp; i <= xk; i++){
					if (i != 0 && i != (N - 1) && yp != 0 && yp != (N - 1)){
						if (board[i - 1][yp] == 'x' || board[i + 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp - 1] == 'x' || board[i + 1][yp - 1] == 'x' || board[i - 1][yp + 1] == 'x' || board[i + 1][yp + 1] == 'x') {
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (i == 0 && yp == 0){
						if (board[i + 1][yp] == 'x' || board[i][yp + 1] == 'x' || board[i + 1][yp + 1] == 'x'){
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (i == (N - 1) && yp == 0){
						if (board[i - 1][yp] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp + 1] == 'x'){
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (i == (N - 1) && yp == (N - 1)){
						if (board[i - 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i - 1][yp - 1] == 'x'){
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (i == 0 && yp == (N - 1)){
						if (board[i + 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i + 1][yp - 1] == 'x'){
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (i == 0){
						if (board[i + 1][yp] == 'x' || board[i + 1][yp + 1] == 'x' || board[i][yp + 1] == 'x' || board[i + 1][yp - 1] == 'x' || board[i][yp - 1] == 'x'){
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (i == N - 1){
						if (board[i - 1][yp] == 'x' || board[i - 1][yp + 1] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp - 1] == 'x' || board[i][yp - 1] == 'x'){
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (yp == 0){
						if (board[i - 1][yp] == 'x' || board[i + 1][yp] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp + 1] == 'x' || board[i + 1][yp + 1] == 'x') {
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (yp == N - 1){
						if (board[i - 1][yp] == 'x' || board[i + 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i - 1][yp - 1] == 'x' || board[i + 1][yp - 1] == 'x') {
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
				}
				if (blad == false) {
					int j = 0;
					for (int i = xp; i <= xk; i++){
						if (board[i][yp] != 'x'){
							board[i][yp] = 'x';
							statki[licz].statki[j] = &board[i][yp];
							j++;
						}
					}
					nb++;
					licz++;
				}
			}
			else if (xp == xk){
				for (int i = yp; i <= yk; i++){
					if (board[xp][i] == 'x'){
						board[xp][yp] = 'x';
						board[xk][yk] = 'x';
						blad = true;
						break;
					}
				}
				for (int i = yp; i <= yk; i++){
					if (i != 0 && i != (N - 1) && xp != 0 && xp != (N - 1)){
						if (board[xp - 1][i] == 'x' || board[xp + 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i - 1] == 'x' || board[xp + 1][i - 1] == 'x' || board[xp - 1][i + 1] == 'x' || board[xp + 1][i + 1] == 'x') {
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (i == 0 && xp == 0){
						if (board[xp + 1][i] == 'x' || board[xp][i + 1] == 'x' || board[xp + 1][i + 1] == 'x'){
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (i == 0 && xp == (N - 1)){
						if (board[xp - 1][i] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i + 1] == 'x'){
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (i == (N - 1) && xp == (N - 1)){
						if (board[xp - 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp - 1][i - 1] == 'x'){
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (i == (N - 1) && xp == 0){
						if (board[xp + 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp + 1][i - 1] == 'x'){
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (i == 0){
						if (board[xp - 1][i] == 'x' || board[xp + 1][i] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i + 1] == 'x' || board[xp + 1][i + 1] == 'x') {
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (i == N - 1) {
						if (board[xp - 1][i] == 'x' || board[xp + 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp - 1][i - 1] == 'x' || board[xp + 1][i - 1] == 'x') {
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (xp == 0) {
						if (board[xp + 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp][i + 1] == 'x' || board[xp + 1][i - 1] == 'x' || board[xp + 1][i + 1] == 'x') {
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}
					else if (xp == N - 1) {
						if (board[xp - 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i - 1] == 'x' || board[xp - 1][i + 1] == 'x') {
							board[xp][yp] = 'x';
							board[xk][yk] = 'x';
							blad = true;
							break;
						}
					}

				}
				if (blad == false) {
					int j = 0;
					for (int i = yp; i <= yk; i++){
						if (board[xp][i] != 'x'){
							board[xp][i] = 'x';
							statki[licz].statki[j] = &board[xp][i];
							j++;
						}
					}
					nb++;
					licz++;
				}
			}
			else {
				board[xp][yp] = '  ';
				board[xk][yk] = '  ';
				cout << "chujowo wybrales\n";
			}
		}
	}
}
/// <summary>
/// Sets the ships.
/// </summary>
/// <param name="statki">The statki.</param>
void ShipsPlayer::SetShips(Ships statki[]) {
	//carrier
	cout << "Wprowadz koordynaty dla carriera(5)\n";
	SetCoordinates(5, 1, statki);
	system("CLS");
	//battleship
	cout << "Wprowadz koordynaty dla battleshipa(4)\n";
	SetCoordinates(4, 2, statki);
	system("CLS");
	//cruiser
	cout << "Wprowadz koordynaty dla cruisera(3)\n";
	SetCoordinates(3, 2, statki);
	system("CLS");
	//submarine
	cout << "Wprowadz koordynaty dla submarine(3)\n";
	SetCoordinates(3, 1, statki);
	system("CLS");
	//patrol boat
	cout << "Wprowadz koordynaty dla patrola(2)\n";
	SetCoordinates(2, 4, statki);
	system("CLS");
}
/// <summary>
/// Gets the board.
/// </summary>
/// <returns></returns>
char** ShipsPlayer::GetBoard() {
	char** arr = tab.GetBoard();
	return arr;
}