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
bool PerformTestCombination(const unsigned int _kuin, const unsigned int _kuir);
bool PerformTestPermutation(const unsigned int _kuin, const unsigned int _kuir);
bool PerformTestCardinality(Set& _rSet);
bool PerformTestPower(Set& _rSet);
bool PerformTestCartesianProduct(Set& _rA, Set& _rB);
bool PerformTestEquals(Set& _rA, Set& _rB);
bool PerformTestSubset(Set& _rA, Set& _rB);
bool PerformTestSuperset(Set& _rA, Set& _rB);
bool PerformTestDisjoint(Set& _rA, Set& _rB, Set& _rResultant);
bool PerformTestUnion(Set& _rA, Set& _rB, Set& _rResultant);
bool PerformTestIntersection(Set& _rA, Set& _rB, Set& _rResultant);
bool PerformTestSetDifference(Set& _rA, Set& _rB, Set& _rResultant);
bool PerformTestSymmetricDifference(Set& _rA, Set& _rB, Set& _rResultant);
bool PerformTestComplement(Set& _rA, Set& _rResultant);
