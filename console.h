#pragma once
/**
 * \file   console.h
 * \brief  Header file for console
 * \author pawci
 * \date   June 2023
 */
#include<iostream>
#include <Windows.h>
class console{
public:
	void ClearConsoleFromSecondLine();
	void ClearConsoleFromThirdLine();
	void SetCursorPosition(int x, int y);
};

