#include "ShipsAi.h"
#include "console.h"
void ShipsAi::SetCoordinatesAi(int lenght, int qt, Ships statki[]) {
	int nb = 0, xp, yp, xk, yk;
	board = tab.GetBoard();
	while (nb < qt) {
		bool blad=false;
		yp = rand() % N;
		xp = rand() % N;
		yk = rand() % N;
		xk = rand() % N;
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
		if (rozx != lenght && rozy != lenght) continue;
		else if (yp == yk){
			for (int i = xp; i <= xk; i++){
				if (board[i][yp] == 'x') {
					blad = true;
					break;
				}
			}
			for (int i = xp; i <= xk; i++){
				if (i != 0 && i != (N - 1) && yp != 0 && yp != (N - 1)){
					if (board[i - 1][yp] == 'x' || board[i + 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp - 1] == 'x' || board[i + 1][yp - 1] == 'x' || board[i - 1][yp + 1] == 'x' || board[i + 1][yp + 1] == 'x') {
						blad = true;
						break;
					}
				}
				else if (i == 0 && yp == 0){
					if (board[i + 1][yp] == 'x' || board[i][yp + 1] == 'x' || board[i + 1][yp + 1] == 'x'){
						blad = true;
						break;
					}
				}
				else if (i == (N - 1) && yp == 0){
					if (board[i - 1][yp] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp + 1] == 'x'){
						blad = true;
						break;
					}
				}
				else if (i == (N - 1) && yp == (N - 1)){
					if (board[i - 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i - 1][yp - 1] == 'x'){
						blad = true;
						break;
					}
				}
				else if (i == 0 && yp == (N - 1)){
					if (board[i + 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i + 1][yp - 1] == 'x'){
						blad = true;
						break;
					}
				}
				else if (i == 0){
					if (board[i + 1][yp] == 'x' || board[i + 1][yp + 1] == 'x' || board[i][yp + 1] == 'x' || board[i + 1][yp - 1] == 'x' || board[i][yp - 1] == 'x'){
						blad = true;
						break;
					}
				}
				else if (i == N - 1){
					if (board[i - 1][yp] == 'x' || board[i - 1][yp + 1] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp - 1] == 'x' || board[i][yp - 1] == 'x'){
						blad = true;
						break;
					}
				}
				else if (yp == 0){
					if (board[i - 1][yp] == 'x' || board[i + 1][yp] == 'x' || board[i][yp + 1] == 'x' || board[i - 1][yp + 1] == 'x' || board[i + 1][yp + 1] == 'x') {
						blad = true;
						break;
					}
				}
				else if (yp == N - 1){
					if (board[i - 1][yp] == 'x' || board[i + 1][yp] == 'x' || board[i][yp - 1] == 'x' || board[i - 1][yp - 1] == 'x' || board[i + 1][yp - 1] == 'x') {
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
					blad = true;
					break;
				}
			}
			for (int i = yp; i <= yk; i++){
				if (i != 0 && i != (N - 1) && xp != 0 && xp != (N - 1)){
					if (board[xp - 1][i] == 'x' || board[xp + 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i - 1] == 'x' || board[xp + 1][i - 1] == 'x' || board[xp - 1][i + 1] == 'x' || board[xp + 1][i + 1] == 'x') {
						blad = true;
						break;
					}
				}
				else if (i == 0 && xp == 0){
					if (board[xp + 1][i] == 'x' || board[xp][i + 1] == 'x' || board[xp + 1][i + 1] == 'x'){
						blad = true;
						break;
					}
				}
				else if (i == 0 && xp == (N - 1)){
					if (board[xp - 1][i] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i + 1] == 'x'){
						blad = true;
						break;
					}
				}
				else if (i == (N - 1) && xp == (N - 1)){
					if (board[xp - 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp - 1][i - 1] == 'x'){
						blad = true;
						break;
					}
				}
				else if (i == (N - 1) && xp == 0){
					if (board[xp + 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp + 1][i - 1] == 'x'){
						blad = true;
						break;
					}
				}
				else if (i == 0){
					if (board[xp - 1][i] == 'x' || board[xp + 1][i] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i + 1] == 'x' || board[xp + 1][i + 1] == 'x') {
						blad = true;
						break;
					}
				}
				else if (i == N - 1) {
					if (board[xp - 1][i] == 'x' || board[xp + 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp - 1][i - 1] == 'x' || board[xp + 1][i - 1] == 'x') {
						blad = true;
						break;
					}
				}
				else if (xp == 0) {
					if (board[xp + 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp][i + 1] == 'x' || board[xp + 1][i - 1] == 'x' || board[xp + 1][i + 1] == 'x') {
						blad = true;
						break;
					}
				}
				else if (xp == N - 1) {
					if (board[xp - 1][i] == 'x' || board[xp][i - 1] == 'x' || board[xp][i + 1] == 'x' || board[xp - 1][i - 1] == 'x' || board[xp - 1][i + 1] == 'x') {
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
						statki[licz].statki[j]=&board[xp][i];
						j++;
					}
				}
				nb++;
				licz++;
			}
		}
		else {
			/*cout << "chujowo wybrales\n";*/
		}
	}
}
void ShipsAi::SetShipsAi(Ships statki[]) {
	//carrier
	SetCoordinatesAi(5, 1, statki);
	//battleship
	SetCoordinatesAi(4, 2, statki);
	//cruiser
	SetCoordinatesAi(3, 2, statki);
	//submarine
	SetCoordinatesAi(3, 1, statki);
	//patrol boat
	SetCoordinatesAi(2, 4, statki);
}
char** ShipsAi::GetAiBoard() {
	char** arr = tab.GetBoard();
	return arr;
}