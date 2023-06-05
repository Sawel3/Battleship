#pragma once
/**
 * \file   Ships.h
 * \brief  Header file for Ships
 */
#include <iostream>
#include <stdlib.h>
using namespace std;
class Ships{
public:
	Ships();
	/// <summary>
	/// The statki array
	/// </summary>
	char* statki[6];
	bool IsDestroyed();
	/// <summary>
	/// The is destroyed boolean
	/// </summary>
	bool isDestroyed = false;
};



