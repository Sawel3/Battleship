#include "console.h"
/// <summary>
/// Clears the console from second line.
/// </summary>
void console::ClearConsoleFromSecondLine()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD startPosition = { 0, 1 }; // Second line, assuming 0-based indexing

	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(hConsole, &bufferInfo);

	DWORD numCharsWritten;
	DWORD screenSize = bufferInfo.dwSize.X * (bufferInfo.dwSize.Y - 1); // Exclude the first line
	FillConsoleOutputCharacter(hConsole, ' ', screenSize, startPosition, &numCharsWritten);
	FillConsoleOutputAttribute(hConsole, bufferInfo.wAttributes, screenSize, startPosition, &numCharsWritten);
	SetConsoleCursorPosition(hConsole, startPosition);
}
/// <summary>
/// Clears the console from third line.
/// </summary>
void console::ClearConsoleFromThirdLine()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD startPosition = { 0, 2 }; // Third line, assuming 0-based indexing

	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(hConsole, &bufferInfo);

	DWORD numCharsWritten;
	DWORD screenSize = bufferInfo.dwSize.X * (bufferInfo.dwSize.Y - 2); // Exclude the first two lines
	FillConsoleOutputCharacter(hConsole, ' ', screenSize, startPosition, &numCharsWritten);
	FillConsoleOutputAttribute(hConsole, bufferInfo.wAttributes, screenSize, startPosition, &numCharsWritten);
	SetConsoleCursorPosition(hConsole, startPosition);
}
/// <summary>
/// Sets the cursor position.
/// </summary>
/// <param name="x">The x position.</param>
/// <param name="y">The y position.</param>
void console::SetCursorPosition(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hConsole, position);
}