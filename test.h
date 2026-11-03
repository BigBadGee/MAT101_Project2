#pragma once
#include "discretemaths.h"
class test
{
};

bool PerformTestMagnitude(const float _kfX);
bool PerformTestSignum(const float _kfX);
bool PerformTestFloor(const float _kfX);
bool PerformTestCeiling(const float _kfX);
bool PerformTestFactorial(const unsigned int _kdn);
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
