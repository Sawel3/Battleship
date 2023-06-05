#include "Attack.h"
/// <summary>
/// Ataks the specified ai real board.
/// </summary>
/// <param name="AiRealBoard">The ai real board.</param>
/// <param name="statki">The statki.</param>
/// <param name="AiVisibleBoard">The ai visible board.</param>
/// <param name="PlayerBoard">The player board.</param>
void Attack::Atak(char** AiRealBoard, Ships statki[], char** AiVisibleBoard, char** PlayerBoard) {
	bool trafiony=true, over=false;
	int strzaly=true,x,y;
	string point;
	while (trafiony==true && over==false){
		tab.Show_Board(AiRealBoard);
		cin >> point;
		if (point.length() > 3 || point.length() < 0) continue;
		else if (point.length() != 2 && point.length() != 3) continue;
		if (point[0] < 65 || point[0]>74) continue;
		x = abs(65-point[0]);
		if (point[2] == '0' && point[1] == '1') y = 9;
		else y = point[1]-49;
		if (x<0||x>10||y<0||y>10){
			cout << "Zle wybrales\n";
			cout << "Przyklad "<<char(74-rand()%10)<<10-rand()%9<<endl;
			continue;
		}
		else{
			if (AiRealBoard[x][y] == 'x'){
				consol.SetCursorPosition(0, 0);
				cout << "trafiony\n";
				AiRealBoard[x][y] = 'T';
				AiVisibleBoard[x][y] = 'X';
				trafiony = true;
				for (int i = 0; i < 10; i++){
					if (statki[i].IsDestroyed() == true) {
						consol.SetCursorPosition(0, 0);
						cout << "zniszczony\n";
						int win = 0;
						for (int j = 0; j < 10; j++){
							if (statki[j].isDestroyed) win++;
						}
						if (win == 10){
							over = true;
							system("CLS");
							cout << "Wygrales farajerze essa na noba\n";
							exit(0);
						}
					};
				}
				consol.ClearConsoleFromThirdLine();
				tab.ShowTwoBoard(AiVisibleBoard, PlayerBoard);
				continue;
			}
			else if (AiRealBoard[x][y] == 'T') {
				cout << "juz tu strzela³es mordo\n";
				continue;
			}
			else{
				trafiony = false;
				AiVisibleBoard[x][y] = 'O';
				cout << "pudlo\n";
				break;
			}
		}
	}
}
/// <summary>
/// Ai's the atak.
/// </summary>
/// <param name="PlayerBoard">The player board.</param>
/// <param name="statki">The statki.</param>
/// <param name="AiVisibleBoard">The ai visible board.</param>
void Attack::AiAtak(char** PlayerBoard, Ships statki[], char** AiVisibleBoard) {
	bool trafiony = true, over = false, LastHit = false, DoubleHit = false;
	int x=0, y=0, dodx, dody;
	while (trafiony == true && over == false){
		if (DoubleHit == true) {
			switch (dodx){
			case 0:
				switch (dody){
				case 1:
					y += 1;
					break;
				case -1:
					y -= 1;
					break;
				default:
					break;
				}
				break;
			case 1:
				x += 1;
				break;
			case -1:
				x -= 1;
				break;
			default:
				break;
			}
		}
		else if (LastHit == true){
			dodx = 0, dody = 0;
			if (x == 0) {
				if (y == 0){
					dodx = rand() % 1;
					if (dodx == 0){
						y += 1;
					}
				}
				else if (y == N-1){
					dodx = rand() % 1;
					if (dodx == 0) y -= 1;
				}
				else{
					do {
						dodx = rand() % 2;
						dody = rand() % 3 - 1;
					} while (abs(dodx) == abs(dody) || (dodx == 0 && dody == 0));
					x += dodx;
					y += dody;
				}
			}
			else if (x == N-1) {
				if (y == 0){
					dodx = rand() % 1;
					if (dodx == 0) y += 1;
				}
				else if (y == N-1){
					dodx = rand() % 1;
					if (dodx == 0) y -= 1;
				}
				else{
					do {
						dodx = rand() % 2-1;
						dody = rand() % 3 - 1;
					} while (abs(dodx) == abs(dody) || (dodx == 0 && dody == 0));
					x += dodx;
					y += dody;
				}
			}
			else if (y == 0) {
				if (x == 0){
					dody = rand() % 2 - 1;
					if (dody == 0) x += 1;
				}
				else if (x == N-1){
					dody = rand() % 2 - 1;
					if (dody == 0) x -= 1;
				}
				else{
					do {
						dodx = rand() % 3-1;
						dody = rand() % 2;
					} while (abs(dodx) == abs(dody) || (dodx == 0 && dody == 0));
					x += dodx;
					y += dody;
				}
			}
			else if (y == N-1) {
				if (x == 0){
					dody = rand() % 2 - 1;
					if (dody == 0) x += 1;
				}
				else if (x == N-1){
					dody = rand() % 2 - 1;
					if (dody == 0) x -= 1;
				}
				else{
					do {
						dodx = rand() % 3-1;
						dody = rand() % 2-1;
					} while (abs(dodx) == abs(dody) || (dodx == 0 && dody == 0));
					x += dodx;
					y += dody;
				}
			}
			else{
				do {
					dody = rand() % 3 - 1;
					dodx = rand() % 3 - 1;
				} while (abs(dodx) == abs(dody) || (dodx == 0 && dody == 0));
				x += dodx;
				y += dody;
			}
		}
		else{
			x = rand() % N;
			y = rand() % N;
		}
		if (PlayerBoard[x][y] == 'x'){
			consol.SetCursorPosition(0, 0);
			cout << "trafiony\n";
			PlayerBoard[x][y] = 'T';
			if (LastHit ==true) DoubleHit = true;
			trafiony = true;
			LastHit = true;
			for (int i = 0; i < 10; i++){
				if (statki[i].IsDestroyed() == true) {
					consol.SetCursorPosition(0, 0);
					cout << "zniszczony\n";
					LastHit = false;
					DoubleHit = false;
					int win = 0;
					for (int i = 0; i < 10; i++){
						if (statki[i].isDestroyed) win++;
					}
					if (win == 10){
						over = true;
						system("CLS");
						cout << "Wygrales farajerze essa na noba\n";
						exit(0);
					}
				};
			}
			consol.ClearConsoleFromThirdLine();
			tab.ShowTwoBoard(AiVisibleBoard, PlayerBoard);
			continue;
		}
		else if (PlayerBoard[x][y] == 'T'|| PlayerBoard[x][y] == 'O') {
			cout << "Juz tu strzelales mordo\n";
			LastHit = false;
			DoubleHit = false;
			continue;
		}
		else{
			
			trafiony = false;
			PlayerBoard[x][y] = 'O';
			cout << "pudlo\n";
			break;
		}
	}
}
	
