#include "Ships.h"
/// <summary>
/// Initializes a new instance of the <see cref="Ships"/> class.
/// </summary>
Ships::Ships() {
	for (int i = 0; i < 6; i++) statki[i] = nullptr;
}
/// <summary>
/// Determines whether this instance is destroyed.
/// </summary>
/// <returns>
///   <c>true</c> if this instance is destroyed; otherwise, <c>false</c>.
/// </returns>
bool Ships::IsDestroyed() {
	if (statki[0]==nullptr) return false;

	for (int i = 0; statki[i]!=nullptr; i++){
		if (*statki[i] != 'T') return false;
	}
	statki[0] = nullptr;
	isDestroyed = true;
	return true;
}
