#include "discretemaths.h"

// needs to return a real number  
float Magnitude(const float _kfX) {
	// is _kfX postive or negitive, if negitive, convert to possitive by mutliplying by -1.   
	return (_kfX < 0.0f) ? _kfX * -1.0f : _kfX;
}

// needs to return the 1 if if greater than 0, -1 if less than zero, 0 if 0
float Signum(const float _kfX)
{
    if (_kfX > 0.0f) return  1.0f;
    if (_kfX < 0.0f) return -1.0f;
    return 0.0f;
}

// needs to round down toward 0 and return the float. 
float Floor(const float _kfX) {
    //converting to int will round correctly for postive non-integers. but for negitive non-integers it ceiling them. 
    float truncated = (int)_kfX;      
    //if truncated is greater than _kfX it means its been ceiling and thus a negitive non-integer.
    if (truncated > _kfX) { 
        // minusing 1 will correct the ceiling from converting to int.
        truncated =  truncated  - 1.0f;
    };
    return truncated;
};

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
