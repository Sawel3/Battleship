#include "Ships.h"
Ships::Ships() {
	for (int i = 0; i < 6; i++)
	{
		statki[i] = nullptr;
	}
}
bool Ships::IsDestroyed() {
	if (statki[0]==nullptr)
	{
		return false;
	}
	for (int i = 0; statki[i]!=nullptr; i++)
	{
		if (*statki[i] != 'T') {
			return false;
		}
	}
	statki[0] = nullptr;
	isDestroyed = true;
	return true;
}
