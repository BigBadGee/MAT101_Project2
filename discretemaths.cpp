#include "discretemaths.h"

// needs to return a real number  
float Magnitude(const float _kfX) {
	// is _kfX postive or negitive, if negitive, convert to possitive by mutliplying by -1.   
	return (_kfX < 0.0f) ? _kfX * -1.0f : _kfX;
}

float Signum(const float _kfX);

float Floor(const float _kfX);

float Ceiling(const float _kfX);

unsigned long long Factorial(const unsigned int _kdn);

unsigned long long Combination(const unsigned int _kuin, const unsigned int _kuir);

unsigned long long Permutation(const unsigned int _kuin, const unsigned int _kuir);

int Cardinality(Set& _rSet);

unsigned long long Power(Set& _rSet);

unsigned long long CartesianProduct(Set& _rA, Set& _rB);

bool Equals(Set& _rA, Set& _rB);

bool Subset(Set& _rA, Set& _rB);

bool Superset(Set& _rA, Set& _rB);

bool Disjoint(Set& _rA, Set& _rB);

Set& Union(Set& _rA, Set& _rB, Set& _rResultant);

Set& Intersection(Set& _rA, Set& _rB, Set& _rResultant);

Set& SetDifference(Set& _rA, Set& _rB, Set& _rResultant);

Set& SymmetricDifference(Set& _rA, Set& _rB, Set& _rResultant);

Set& Complement(Set& _rA, Set& _rResultant);
