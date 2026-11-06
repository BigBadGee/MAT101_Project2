#include "discretemaths.h"
//#include "test.h"

bool isNaN(float _kfX) {

    union { float _fF; unsigned int _uiI; } _uU;
    _uU._fF = _kfX;
    //using bitwise & to remove the sign of nan 
    //0x7FFFFFFF = 0111 1111 1111 1111 1111 1111 1111 1111 - leaves the first bit which is the sign 
    return (_uU._uiI & 0x7FFFFFFFu) > 0x7F800000u;
}

bool isNegative(float _kfX) {
    union { float _fF; unsigned int _uiI; } _uU;
    _uU._fF = _kfX;
    //return true if non zero and false if not.
    return (_uU._uiI & 0x80000000u) != 0u;
}
// I know union hasnt been taught in class, but I need to be handle to handle nan's


//The size of the variable
float Magnitude(const float _kfX) {
    return (_kfX < 0.0f) ? (0.0f - _kfX) : ((_kfX == 0.0f) ? 0.0f : _kfX);
}
//Positive, Negitive or 0 
float Signum(const float _kfX){
    if (isNaN(_kfX)) return _kfX;
    if (_kfX > 0.0f) return  1.0f;
    if (_kfX < 0.0f) return -1.0f;
    return 0.0f;
}

//Rounds down towards zero
float Floor(const float _kfX) {
    if (isNaN(_kfX) || _kfX == 0.0f) return _kfX;
    if (_kfX >= 2147483647.0f || _kfX <= -2147483647.0f) return _kfX;
    float _fT = static_cast<float>(static_cast<int>(_kfX));
    if (_fT > _kfX) _fT -= 1.0f;
    return _fT;
}
//Rounds up away from zero
float Ceiling(const float _kfX) {
    if (isNaN(_kfX) || _kfX == 0.0f) {
        return _kfX;
    }
    if (_kfX == static_cast<int>(_kfX) || _kfX > 2147483647.0f || _kfX < -2147483647.0f) {
        return _kfX;
    }
    int _iT = static_cast<int>(_kfX);
    float _fT = static_cast<float>(_iT);
    if (_fT < _kfX) {
        _fT += 1.0f;
    };
    return _fT;
}
//Multuply all ints from 1 to given factorial 5 1x2x3x4x5
unsigned long long Factorial(const unsigned int _kdn) {
    unsigned long long _dr = 1;
    if (isNaN(_kdn)) return _kdn;
    // this still doesnt work how i want it too. 
    if (_kdn > 20) return 0;
    //skipped 1, starting at 2, because multiply by 1 is useless
    for (unsigned int i = 2; i <= _kdn; ++i) {
        _dr *= i;
    };
    return _dr;
}
//Order doesnt matter in combination, so number of ways to choose n from r. n!/(r!(n−r)!)
// need to fix divide by zero
unsigned long long Combination(const unsigned int _kuin, const unsigned int _kuir) {
    //added bountry cheked
    if (_kuir > _kuin) return 0;
    unsigned long long _ulln = Factorial(_kuin);
    unsigned long long _ulld = Factorial(_kuir) * Factorial(_kuin - _kuir);
    if (_ulld == 0) return 0;
    return _ulln / _ulld;
}

//Order does matter in Permutation n!/(n−r)!
unsigned long long Permutation(const unsigned int _kuin, const unsigned int _kuir) {
    if (_kuir > _kuin) return 0;
    return Combination(_kuin, _kuir) * Factorial(_kuir);
}
//How many unique elements in a set.
int Cardinality(Set& _rSet){
    int _iC = 0;
    for (int i = 1; i <= SET_SIZE_MAX; i++)
        if (_rSet.ContainsElement(i)) {
            _iC++;
        }
    return _iC;
}

//The power set is set of all Subetsets include the set itself and a empty set, this confused me because it return  
//Calculate power of
unsigned long long Power(Set& _rSet) {
    unsigned long long _ullC = Cardinality(_rSet);
    unsigned long long _ullR = 1;
    for (int i = 0; i < _ullC; i++) {
        _ullR *= 2;
    }
    return _ullR;
}
//All ordered pairs from set a and set b, So the number of of possible pairs ?
unsigned long long CartesianProduct(Set& _rA, Set& _rB) {
    unsigned long long _ullA = Cardinality(_rA);
    unsigned long long _ullB = Cardinality(_rB);
    return _ullA * _ullB;
};
//Test if both sets contains all the same elements
bool Equals(Set& _rA, Set& _rB) {
    for (int i = 1; i <= SET_SIZE_MAX; i++)
    {
        if (_rA.ContainsElement(i) != _rB.ContainsElement(i))
            return false;
    }
    return true;            
}
//Test if all of the element set a are in set b 
bool Subset(Set& _rA, Set& _rB){
    for (int i = 1; i <= SET_SIZE_MAX; i++) {
        if (_rA.ContainsElement(i) && !_rB.ContainsElement(i)){
            return false;
        }
    }
    return true;
}
//Test if all of the element set b are in set a 
bool Superset(Set& _rA, Set& _rB){
    for (int i = 1; i <= SET_SIZE_MAX; i++){
        if (_rB.ContainsElement(i) && !_rA.ContainsElement(i)) {
            return false;
        }
    }
    return true;           
}
//Tests of any elements A are in set B they arent disjoint 
bool Disjoint(Set& _rA, Set& _rB) {
    for (int i = 1; i <= SET_SIZE_MAX; i++){
        if (_rA.ContainsElement(i) && _rB.ContainsElement(i)) {
            return false;
        }
    }
    return true;
}
//Combines set a and set b and returns a new set Resultant
Set& Union(Set& _rA, Set& _rB, Set& _rResultant){
    _rResultant.SetClear();
    for (int i = 1; i <= SET_SIZE_MAX; i++) {
        if (_rA.ContainsElement(i) || _rB.ContainsElement(i)) {
            _rResultant.AddElement(i);
        }
    }
    return _rResultant;
}

//Only returns elements in both set a and set b as Resultant
Set& Intersection(Set& _rA, Set& _rB, Set& _rResultant){
    _rResultant.SetClear();
    for (int i = 1; i <= SET_SIZE_MAX; i++){
        if (_rA.ContainsElement(i) && _rB.ContainsElement(i)) {
            _rResultant.AddElement(i);
        }
    }
    return _rResultant;
}
//Only returns elements that dont intersect, what is a and not b
Set& SetDifference(Set& _rA, Set& _rB, Set& _rResultant) {
    _rResultant.SetClear();                   
    for (int i = 1; i <= SET_SIZE_MAX; i++){
        if (_rA.ContainsElement(i) && !_rB.ContainsElement(i))
            _rResultant.AddElement(i);   
    }
    return _rResultant;
}
//Only returns elements in a or b not both
Set& SymmetricDifference(Set& _rA, Set& _rB, Set& _rResultant) {
    _rResultant.SetClear();
    for (int i = 1; i <= SET_SIZE_MAX; i++){
        if (_rA.ContainsElement(i) != _rB.ContainsElement(i))
            _rResultant.AddElement(i);
    }
    return _rResultant;
}
//Everything in the univerial set that is not in set a
Set& Complement(Set& _rA, Set& _rResultant){
    _rResultant.SetClear();
    for (int i = 1; i <= SET_SIZE_MAX; i++){
        if (!_rA.ContainsElement(i))
            _rResultant.AddElement(i);
    }
    return _rResultant;
}
