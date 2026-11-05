#include "test.h"
extern bool isNaN(float _kfX);
extern bool isNegative(float _kfX);


bool PerformTestMagnitude(const float _kfX, const float _expectedState) {
	if (isNaN(_kfX) || isNaN(_expectedState)) {
		return isNaN(_kfX) && isNaN(_expectedState);
	}
	//-0.0f == 0.0f is true
	//checks the results vs expected state and checks the sign bit of the zero.
	return (_kfX == _expectedState) && (isNegative(_kfX) == isNegative(_expectedState));
}

bool PerformTestSignum(const float _kfX, const float _expectedState) {
	if (isNaN(_kfX) || isNaN(_expectedState)) {
		return isNaN(_kfX) && isNaN(_expectedState);
	}
	return _kfX == _expectedState;
}

bool PerformTestFloor(const float _kfX, const float _expectedState) {
	if (isNaN(_kfX) || isNaN(_expectedState)) {
		return isNaN(_kfX) && isNaN(_expectedState);
	}
	return _kfX == _expectedState;
}

bool PerformTestCeiling(const float _kfX, const float _expectedState)
{
	return false;
}

bool PerformTestFactorial(const unsigned int _kdn, const float _expectedState)
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
void RunAlTests() {
	unsigned int _uiTestsRun = 0;
	unsigned int _uiPassedTests = 0;
	unsigned int _uiFailTests = 0;
	float nan = __builtin_nanf("");
	const float _kaT[10] = {0.0f, -0.0f, 1.0f, -1.0f, 0.5f, -0.5f, 3.4028235e38f, -3.4028235e38f, 1.17549435e-38f,nan};
	//Magnitude expected values
	const float _aMES[10] = {0.0f,  0.0f,  1.0f,  1.0f, 0.5f,  0.5f, 3.4028235e38f,  3.4028235e38f, 1.17549435e-38f,nan};
	//Sinnum expected values
	const float _aSES[10] = {0.0f, 0.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f,1.0f,nan};
	
	//Magnitude Testing 
	for (int i = 0; i < 10; i++) {
		float _fResult = Magnitude(_kaT[i]);
		if (PerformTestMagnitude(_fResult, _aMES[i])) {
			_uiPassedTests++;
			//std::cout << "######### Magnitude Test Successful #########\n";
			//std::cout << "Given " << _kaT[i] << " Returned " << _fResult << "\n";
		}
		else {
			_uiFailTests++;
			std::cout << "######### Magnitude Test Failed #########\n";
			std::cout << "Value: " << _kaT[i] << " Outcome " << _fResult << "  Expected : " << _aMES[i] << "\n";
		}
	}
	//Signum Testing
	for (int i = 0; i < 10; i++) {
		float _fResult = Signum(_kaT[i]);
		if (PerformTestSignum(_fResult, _aSES[i])) {
			_uiPassedTests++;
			//std::cout << "######### Signum Test Successful #########\n";
			//std::cout << "Given " << _kaT[i] << " Returned " << _fResult << "\n";
		}
		else {
			_uiFailTests++;
			std::cout << "######### Signum Test Failed #########\n";
			std::cout << "Value: " << _kaT[i] <<" Outcome " << _fResult << "  Expected : " << _aSES[i] << "\n";
		}
	}
	std::cout << "Passed: " << _uiPassedTests << " | Failed: " << _uiFailTests << "\n";
}
