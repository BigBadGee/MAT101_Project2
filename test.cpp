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

bool PerformTestCardinality(Set& _rSet, const int _expectedState) {
	return Cardinality(_rSet) == _expectedState;
}

bool PerformTestPower(Set& _rSet, const int _expectedState) {
	return Power(_rSet) == _expectedState;
}

bool PerformTestCartesianProduct(Set& _rA, Set& _rB, const unsigned long long _expectedState) {
	return CartesianProduct(_rA, _rB) == _expectedState;
}

bool PerformTestEquals(Set& _rA, Set& _rB, const bool _expectedState) {
	return Equals(_rA, _rB) == _expectedState;
}

bool PerformTestSubset(Set& _rA, Set& _rB, bool _expectedState) {
	return Subset(_rA, _rB) == _expectedState;
}

bool PerformTestSuperset(Set& _rA, Set& _rB, bool _expectedState) {
	return Superset(_rA, _rB) == _expectedState;
}
bool PerformTestDisjoint(Set& _rA, Set& _rB, bool _expectedState) {
	return Disjoint(_rA, _rB) == _expectedState;
}

bool PerformTestUnion(Set& _rResultant, Set& _expectedState) {
	return Equals(_rResultant, _expectedState);
}

bool PerformTestIntersection(Set& _rResultant, Set& _expectedState) {
	return Equals(_rResultant, _expectedState);
}

bool PerformTestSetDifference(Set& _rResultant, Set& _expectedState) {
	return Equals(_rResultant, _expectedState);
}

bool PerformTestSymmetricDifference(Set& _rResultant, Set& _expectedState) {
	return Equals(_rResultant, _expectedState);
}

bool PerformTestComplement(Set& _rA, Set& _rResultant, int _expectedState) {
	if (Cardinality(_rResultant) != _expectedState) return false;
	for (int i = 1; i <= SET_SIZE_MAX; i++) {
		if (_rA.ContainsElement(i) && _rResultant.ContainsElement(i)) return false;
	}
	for (int i = 1; i <= SET_SIZE_MAX; i++) {
		if (!_rA.ContainsElement(i) && !_rResultant.ContainsElement(i)) return false;
	}
	return true;
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
	Set _sT0;
	_sT0.SetClear();

	Set _sT1;
	_sT1.SetClear();
	_sT1.AddElement(1);
	_sT1.AddElement(34);
	_sT1.AddElement(55);
	_sT1.AddElement(6);
	_sT1.AddElement(15);


	Set _sT2;
	_sT2.SetClear();
	_sT2.AddElement(1);
	_sT2.AddElement(34);
	_sT2.AddElement(55);
	_sT2.AddElement(6);
	_sT2.AddElement(15);
	_sT2.AddElement(9);

	Set _sT3;
	_sT3.SetClear();
	_sT3.AddElement(55);
	_sT3.AddElement(1);
	_sT3.AddElement(15);
	_sT3.AddElement(34);
	_sT3.AddElement(6);
	_sT3.AddElement(1);

	Set _sT4;
	_sT4.SetClear();
	_sT4.AddElement(2);
	_sT4.AddElement(4);
	_sT4.AddElement(8);
	_sT4.AddElement(9);
	_sT4.AddElement(100);
	//Base Resultant
	Set _rResultant;
	_rResultant.SetClear();
	//
	Set _sU1;
	_sU1.SetClear();
	_sU1.AddElement(1);
	_sU1.AddElement(34);
	_sU1.AddElement(55);
	_sU1.AddElement(6);
	_sU1.AddElement(15);


	Set _sU2;
	_sU2.SetClear();
	_sU2.AddElement(1);
	_sU2.AddElement(34);
	_sU2.AddElement(55);
	_sU2.AddElement(6);
	_sU2.AddElement(15);
	_sU2.AddElement(9);
	_sU2.AddElement(4);

	//Expected state for  Union 
	Set _sUES1;
	_sUES1.SetClear();
	_sUES1.AddElement(1);
	_sUES1.AddElement(4);
	_sUES1.AddElement(6);
	_sUES1.AddElement(9);
	_sUES1.AddElement(15);
	_sUES1.AddElement(34);
	_sUES1.AddElement(55);

	Set _sIES;
	_sIES.SetClear();
	_sIES.AddElement(1);
	_sIES.AddElement(15);
	_sIES.AddElement(34);
	_sIES.AddElement(55);
	_sIES.AddElement(6);
	//expected state for Different 
	Set _sDES1;
	_sDES1.SetClear();
	Set _sDES2;
	_sDES2.SetClear();
	_sDES2.AddElement(4);
	_sDES2.AddElement(9);

	Set _sSDES1;
	_sSDES1.AddElement(4);
	_sSDES1.AddElement(9);
	Set _sSDES2;

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

	


	//Cardinailty testing
	if (PerformTestCardinality(_sT1, 5)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Cardinailty Test Failed #########\n";
		std::cout << "Expected: 5";
	}
	//Power testing
	if (PerformTestPower(_sT1, 32)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Power Test Failed #########\n";
		std::cout << "Expected: 32 Outcome: " << Power(_sT1) << "\n";
	}
	
	if (PerformTestPower(_sT2, 64)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Power Test Failed #########\n";
		std::cout << "Expected: 64 Outcome: " << Power(_sT2)<< "\n" ;
	}
	//Cartesian Product testing;
	if (PerformTestCartesianProduct(_sT1, _sT2,30)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Cartesian Product Test Failed #########\n";
		std::cout << "Expected: 30 Outcome: " << CartesianProduct(_sT1, _sT2) << "\n";
	}
	//Equals testing;
	if (PerformTestEquals(_sT1, _sT1, 1)) _uiPassedTests++;
	
	else {
		_uiFailTests++;
		std::cout << "######### Equals Test 1 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Equals(_sT1, _sT2) << "\n";
	}
	
	if (PerformTestEquals(_sT2, _sT1, 0)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Equals Test 2 Failed #########\n";
		std::cout << "Expected: 0 Outcome: " << Equals(_sT2, _sT1) << "\n";
	}
	if (PerformTestEquals(_sT1, _sT3, 1)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Equals Test 3 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Equals(_sT1, _sT3) << "\n";
	}
	//Subset testing
	if (PerformTestSubset(_sT1, _sT2, 1)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Subset Test 1 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Subset(_sT1, _sT2) << "\n";
	}
	if (PerformTestSubset(_sT2, _sT1, 0)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Subset Test 2 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Subset(_sT2, _sT1) << "\n";
	}
	if (PerformTestSubset(_sT1, _sT1, 1)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Subset Test 3 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Subset(_sT1, _sT1) << "\n";
	}
	if (PerformTestSubset(_sT0, _sT1, 1)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Subset Test 4 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Subset(_sT0, _sT1) << "\n";
	}
	if (PerformTestSubset(_sT1, _sT1, 1)) {
		_uiPassedTests++;
	}
	else {
		_uiFailTests++;
		std::cout << "######### Subset Test 4 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Subset(_sT1, _sT1) << "\n";
	}

	if (PerformTestSubset(_sT1, _sT1, 1)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Subset Test 4 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Subset(_sT1, _sT1) << "\n";
	}
	if (PerformTestSubset(_sT1, _sT1, 1)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Subset Test 4 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Subset(_sT1, _sT1) << "\n";
	}
	if (PerformTestSubset(_sT0, _sT1, 1)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Subset Test 4 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Subset(_sT0, _sT1) << "\n";
	}
	//Superset testing
	if (PerformTestSuperset(_sT2, _sT1, 1)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Superset Test 1 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Superset(_sT2, _sT1) << "\n";
	}

	if (PerformTestSuperset(_sT1, _sT2, 0)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Superset Test 2 Failed #########\n";
		std::cout << "Expected: 0 Outcome: " << Superset(_sT1, _sT2) << "\n";
	}

	if (PerformTestSuperset(_sT1, _sT1, 1)) _uiPassedTests++;
	
	else {
		_uiFailTests++;
		std::cout << "######### Superset Test 3 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Superset(_sT1, _sT1) << "\n";
	}

	if (PerformTestSuperset(_sT1, _sT0, 1)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Superset Test 4 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Superset(_sT1, _sT0) << "\n";
	}
	//Disjoint testing
	if (PerformTestDisjoint(_sT1, _sT2, 0)) {
		_uiPassedTests++;
	}
	else {
		_uiFailTests++;
		std::cout << "######### Disjoint Test 1 Failed #########\n";
		std::cout << "Expected: 0 Outcome: " << Disjoint(_sT1, _sT2) << "\n";
	}
	if (PerformTestDisjoint(_sT1, _sT4, 1)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Disjoint Test 2 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Disjoint(_sT1, _sT4) << "\n";
	}
	if (PerformTestDisjoint(_sT1, _sT0, 1)) {
		_uiPassedTests++;
	}
	else {
		_uiFailTests++;
		std::cout << "######### Disjoint Test 3 Failed #########\n";
		std::cout << "Expected: 1 Outcome: " << Disjoint(_sT1, _sT0) << "\n";
	}
	//Union testing
	_rResultant.SetClear();
	if (PerformTestUnion(Union(_sU1, _sU2, _rResultant), _sUES1)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "Outcome:  { ";
		for (int i = 1; i <= SET_SIZE_MAX; i++) {
			if (_rResultant.ContainsElement(i)) std::cout << i << " ";
		}
		std::cout << "}\n";

		std::cout << "Expected: { ";
		for (int i = 1; i <= SET_SIZE_MAX; i++) {
			if (_sUES1.ContainsElement(i)) std::cout << i << " ";
		}
		std::cout << "}\n";
	}
	//Intersection testing
	_rResultant.SetClear();
	if (PerformTestIntersection(Intersection(_sU1, _sU2, _rResultant), _sIES)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Intersection Test Failed #########\n";

		std::cout << "Outcome:  { ";
		for (int i = 1; i <= SET_SIZE_MAX; i++) {
			if (_rResultant.ContainsElement(i)) std::cout << i << " ";
		}
		std::cout << "}\n";

		std::cout << "Expected: { ";
		for (int i = 1; i <= SET_SIZE_MAX; i++) {
			if (_sIES.ContainsElement(i)) std::cout << i << " ";
		}
		std::cout << "}\n";
	}
	//SetDifference testing
	_rResultant.SetClear();
	if (PerformTestSetDifference(SetDifference(_sU1, _sU2, _rResultant), _sDES1)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Set Difference Test 1 (_sU1 - _sU2) Failed #########\n";
		std::cout << "Outcome:  { ";
		for (int i = 1; i <= SET_SIZE_MAX; i++) {
			if (_rResultant.ContainsElement(i)) std::cout << i << " ";
		}
		std::cout << "}\nExpected: { }\n";
	}
	_rResultant.SetClear();
	if (PerformTestSetDifference(SetDifference(_sU2, _sU1, _rResultant), _sDES2)) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Set Difference Test 2 (_sU2 - _sU1) Failed #########\n";
		std::cout << "Outcome:  { ";
		for (int i = 1; i <= SET_SIZE_MAX; i++) {
			if (_rResultant.ContainsElement(i)) std::cout << i << " ";
		}
		std::cout << "}\nExpected: { }\n";
	}
	//SymmetricDifference testing
	_rResultant.SetClear();
	if (PerformTestSymmetricDifference(SymmetricDifference(_sU1, _sU2, _rResultant), _sSDES1)) _uiPassedTests;
	else {
		_uiFailTests++;
		std::cout << "######### Symmetric Difference Test Failed #########\n";

		std::cout << "Outcome:  { ";
		for (int i = 1; i <= SET_SIZE_MAX; i++) {
			if (_rResultant.ContainsElement(i)) std::cout << i << " ";
		}
		std::cout << "}\n";

		std::cout << "Expected: { ";
		for (int i = 1; i <= SET_SIZE_MAX; i++) {
			if (_sSDES1.ContainsElement(i)) std::cout << i << " ";
		}
		std::cout << "}\n";
	}
	//Complement testing 
	if (PerformTestComplement(_sU1,Complement(_sU1, _rResultant), (SET_SIZE_MAX - Cardinality(_sU1)))) _uiPassedTests++;
	else {
		_uiFailTests++;
		std::cout << "######### Complement Test Failed #########\n";
		std::cout << "Expected Size: " << SET_SIZE_MAX - Cardinality(_sU1) << " | Actual Size: " << Cardinality(_rResultant) << "\n";
	}

	std::cout << "Passed: " << _uiPassedTests << " | Failed: " << _uiFailTests << "\n";
}
