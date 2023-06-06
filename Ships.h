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
	char* statki[6];
	bool IsDestroyed();
	bool isDestroyed=false;
};



