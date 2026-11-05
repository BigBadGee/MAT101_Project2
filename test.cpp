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

bool PerformTestCeiling(const float _kfX, const float _expectedState){
	if (isNaN(_kfX) || isNaN(_expectedState)) {
		return isNaN(_kfX) && isNaN(_expectedState);
	}
	return _kfX == _expectedState;
}

bool PerformTestFactorial(const unsigned int _kdn, const float _expectedState){
if (isNaN(_kdn) || isNaN(_expectedState)) {
	return isNaN(_kdn) && isNaN(_expectedState);
}
return _kdn == _expectedState;
}

bool PerformTestCombination(const unsigned long long _kullc,  const unsigned long long _expectedState){
	return _kullc == _expectedState;
}

bool PerformTestPermutation(const unsigned long long _kullc, const float _expectedState)
{
	return _kullc == _expectedState;
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
	//Float inputs
	const float _kaT[10] = {0.0f, -0.0f, 1.0f, -1.0f, 0.5f, -0.5f, 3.4028235e38f, -3.4028235e38f, 1.17549435e-38f,nan};
	//Magnitude expected values
	const float _aMES[10] = {0.0f,  0.0f,  1.0f,  1.0f, 0.5f,  0.5f, 3.4028235e38f,  3.4028235e38f, 1.17549435e-38f,nan};
	//Sinnum expected values
	const float _aSES[10] = {0.0f, 0.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f, -1.0f,1.0f,nan};
	//Floor expected values
	const float _aFES[10] = {0.0f, -0.0f, 1.0f, -1.0f, 0.0f, -1.0f, 3.4028235e38f, -3.4028235e38f, 0.0f, nan};
	//Ceiling expected values
	const float _aCES[10] = {0.0f, -0.0f, 1.0f, -1.0f, 1.0f, -0.0f,3.4028235e38f, -3.4028235e38f, 1.0f, nan};
	//Unsigned int inputs
	const unsigned int _kaF[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//Facotrial 
	const unsigned int _kaFES[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
	//combinations 
	const unsigned int _kaaiC[6][2] = { {5, 0},{5, 1},{5, 5},{10, 2},{10, 5},{5, 6}};
	const unsigned long long _kullCES[6] = { 1 ,5 ,1 ,45 ,252, 0};
	//Permutations
	const unsigned long long _kullPES[6] = { 1 ,5, 120 ,90 ,30240, 0 };

	
	//Magnitude Testing 
	for (int i = 0; i < 10; i++) {
		float _fResult = Magnitude(_kaT[i]);
		if (PerformTestMagnitude(_fResult, _aMES[i])) {
			_uiPassedTests++;
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
		}
		else {
			_uiFailTests++;
			std::cout << "######### Signum Test Failed #########\n";
			std::cout << "Value: " << _kaT[i] <<" Outcome " << _fResult << "  Expected : " << _aSES[i] << "\n";
		}
	}
	//floor Testing
	for (int i = 0; i < 10; i++) {
		float _fResult = Floor(_kaT[i]);
		if (PerformTestFloor(_fResult, _aFES[i])) {
			_uiPassedTests++;
		}
		else {
			_uiFailTests++;
			std::cout << "######### Floor Test Failed #########\n";
			std::cout << "Value: " << _kaT[i] << " Outcome " << _fResult << "  Expected : " << _aFES[i] << "\n";
		}
	}
	//ceiling testing
	for (int i = 0; i < 10; i++) {
		float _fResult = Ceiling(_kaT[i]);
		if (PerformTestCeiling(_fResult, _aCES[i])) {
			_uiPassedTests++;
		}
		else {
			_uiFailTests++;
			std::cout << "######### Ceiling Test Failed #########\n";
			std::cout << "Value: " << _kaT[i] << " Outcome " << _fResult << "  Expected : " << _aCES[i] << "\n";
		}
	}
	//Combination testing 

	for (int i = 0; i < 6; i++) {
		int _fResult = Combination(_kaaiC[i][0], _kaaiC[i][1]);
		if (PerformTestCombination(_fResult, _kullCES[i])) {
			_uiPassedTests++;

		}
		else {
			_uiFailTests++;
			std::cout << "######### Combination Test Failed #########\n";
			std::cout << "Value: " << _kaaiC[i][0] << "," << _kaaiC[i][1] << " Outcome " << _fResult << "  Expected : " << _kullCES[i] << "\n";
		}
	};

	//Permutation testing

	for (int i = 0; i < 6; i++) {
		int _fResult = Permutation(_kaaiC[i][0], _kaaiC[i][1]);
		if (PerformTestPermutation(_fResult, _kullPES[i])) {
			_uiPassedTests++;

		}
		else {
			_uiFailTests++;
			std::cout << "######### Combination Test Failed #########\n";
			std::cout << "Value: " << _kaaiC[i][0] << "," << _kaaiC[i][1] << " Outcome " << _fResult << "  Expected : " << _kullPES[i] << "\n";
		}
	};

	std::cout << "Passed: " << _uiPassedTests << " | Failed: " << _uiFailTests << "\n";
}
