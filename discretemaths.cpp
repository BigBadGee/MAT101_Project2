#include "discretemaths.h"

float Magnitude(const float _kfX) {
	return (_kfX < 0.0f) ? _kfX * -1.0f : _kfX;
}

float Signum(const float _kfX)
{
    if (_kfX > 0.0f) return  1.0f;
    if (_kfX < 0.0f) return -1.0f;
    return 0.0f;
}

float Floor(const float _kfX) {
    float _fT = static_cast<int>(_kfX);
    if (_fT > _kfX) {
        _fT -= 1.0f;
    };
    return _fT;
};

float Ceiling(const float _kfX) {
    float _fT = static_cast<int>(_kfX);
    if (_fT < _kfX) {
        _fT += 1.0f;
    };
    return _fT;
};

unsigned long long Factorial(const unsigned int _kdn) {
    unsigned long long _dr = 1;
    for (unsigned int i = 2; i <= _kdn; ++i) {
        _dr *= i;
    };
    return _dr;
};

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
