#pragma once
#include "discretemaths.h"
#include <iostream>
class test
{
};

void RunAlTests();
bool PerformTestMagnitude(const float _kfX, const float _expectedState);
bool PerformTestSignum(const float _kfX, const float _expectedState);
bool PerformTestFloor(const float _kfX, const float _expectedState);
bool PerformTestFactorial(const unsigned int _kdn, const float _expectedState);
bool PerformTestCeiling(const float _kfX, const float _expectedState);
bool PerformTestFactorial(const unsigned int _kdn, const float _expectedState);
bool PerformTestCombination(const unsigned int _kuin, const unsigned int _kuir, const float _expectedState);
bool PerformTestPermutation(const unsigned int _kuin, const unsigned int _kuir, const float _expectedState);
bool PerformTestCardinality(Set& _rSet, const int _expectedState);
bool PerformTestPower(Set& _rSet,const int _expectedState);
bool PerformTestCartesianProduct(Set& _rA, Set& _rB, const unsigned long long _expectedState);
bool PerformTestEquals(Set& _rA, Set& _rB, bool _expectedState);
bool PerformTestSubset(Set& _rA, Set& _rB, bool _expectedState);
bool PerformTestSuperset(Set& _rA, Set& _rB, bool _expectedState);
bool PerformTestDisjoint(Set& _rA, Set& _rB, Set& _rResultant, bool _expectedState);
bool PerformTestUnion(Set& _rResultant, Set& _expectedState);
bool PerformTestIntersection(Set& _rResultant, Set& _expectedState);
bool PerformTestSetDifference(Set& _rResultant, Set& _expectedState);
bool PerformTestSymmetricDifference(Set& _rResultant, Set& _expectedState);
bool PerformTestComplement(Set& _rA, Set& _rResultant, int _expectedState);
