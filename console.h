#pragma once
/**
 * \file   console.h
 * \brief  Header file for console
 */
#include<iostream>
#include <Windows.h>
class console{
public:
	void ClearConsoleFromSecondLine();
	void ClearConsoleFromThirdLine();
	void SetCursorPosition(int x, int y);
};

