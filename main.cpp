#include "test.h"

#include <iostream>
int main() {
	std::cout << PerformTestMagnitude(Magnitude(5.00f), 5.00f);
	std::cout << PerformTestMagnitude(Magnitude(-5.00f), 5.00f);
	std::cout << PerformTestMagnitude(Magnitude(0.00f), 0.00f);
	return 0;
}