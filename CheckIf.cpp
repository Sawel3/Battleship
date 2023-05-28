#include "CheckIf.h"
bool CheckIf::CheckIfTouch(char** board, int N, int xp, int xk, int yp, bool& blad, int& granica, int& granica2, int& granica3, int& granica4, int& granica5)
{
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
	return blad;
}