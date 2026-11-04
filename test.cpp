#include "test.h"
void RunAlTests() {
	unsigned int _uiTestsRun = 0;
	unsigned int _uiPassedTests = 0;
};
bool PerformTestMagnitude(const float _kfX, const float _expectedState)
{
	if (!(_kfX == _expectedState)) {
		return false;
	}
	else {
		return true;
	}
	 
}

bool PerformTestSignum(const float _kfX)
{
	return false;
}

bool PerformTestFloor(const float _kfX)
{
	return false;
}

bool PerformTestCeiling(const float _kfX)
{
	return false;
}

bool PerformTestFactorial(const unsigned int _kdn)
{
	return false;
}

bool PerformTestCombination(const unsigned int _kuin, const unsigned int _kuir)
{
	return false;
}

bool PerformTestPermutation(const unsigned int _kuin, const unsigned int _kuir)
{
	return false;
}

bool PerformTestCardinality(Set& _rSet)
{
	return false;
}

bool PerformTestPower(Set& _rSet)
{
	return false;
}

bool PerformTestCartesianProduct(Set& _rA, Set& _rB)
{
	return false;
}

bool PerformTestEquals(Set& _rA, Set& _rB)
{
	return false;
}

bool PerformTestSubset(Set& _rA, Set& _rB)
{
	return false;
}

bool PerformTestSuperset(Set& _rA, Set& _rB)
{
	return false;
}

bool PerformTestDisjoint(Set& _rA, Set& _rB, Set& _rResultant)
{
	return false;
}

bool PerformTestUnion(Set& _rA, Set& _rB, Set& _rResultant)
{
	return false;
}

bool PerformTestIntersection(Set& _rA, Set& _rB, Set& _rResultant)
{
	return false;
}

bool PerformTestSetDifference(Set& _rA, Set& _rB, Set& _rResultant)
{
	return false;
}

bool PerformTestSymmetricDifference(Set& _rA, Set& _rB, Set& _rResultant)
{
	return false;
}

bool PerformTestComplement(Set& _rA, Set& _rResultant)
{
	return false;
}
