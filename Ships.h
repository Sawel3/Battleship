#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
class Ships{
private:
public:
	Ships();
	char* statki[6];
	bool IsDestroyed();
	bool isDestroyed=false;
};



