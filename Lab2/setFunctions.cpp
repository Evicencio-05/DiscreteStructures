#include "setFunctions.h"
#include "set.h"
#include "set.cpp"

using namespace std;
// Returns a set that is the Union of the two sets s1 and s2
Set<char> setUnion(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;

	size_t set1_current = 0;
	size_t set1_cardinality = s1.cardinality();
	
	while (set1_current < set1_cardinality)
	{
		result.insertElement(s1[set1_current++]);
	}
	
	size_t set2_current = 0;
	size_t set2_cardinality = s2.cardinality();

	while (set2_current < set2_cardinality)
	{
		result.insertElement(s2[set2_current++]);
	}

	return result;
}

// Returns a set that is the intersection of the two sets s1 and s2
Set<char> setIntersection(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;
	
	size_t set1_current = 0;
	size_t set1_cardinality = s1.cardinality();
	
	while (set1_current < set1_cardinality)
	{
		if (s2.isElement(s1[set1_current]))
		{
			result.insertElement(s1[set1_current]);
		}
		set1_current++;
	}

	return result;
}

// Returns a set that is the s1 - s2
Set<char> setDiff(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;

	size_t set1_current = 0;
	size_t set1_cardinality = s1.cardinality();
	
	while (set1_current < set1_cardinality)
	{
		if (!s2.isElement(s1[set1_current]))
		{
			result.insertElement(s1[set1_current]);
		}
		set1_current++;
	}

	return result;
}

// Returns a set that is the symmetric difference of the two sets s1 and s2
Set<char> setSymDiff(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;

	result = setUnion(setDiff(s1,s2), setDiff(s2,s1));

	return result;
}

// Returns true if s1 is a subset of s2
bool isSubSet(const Set<char>& s1, const Set<char>& s2)
{
	if (s1.cardinality() > s2.cardinality()) return false;

	size_t set1_current = 0;
	size_t set1_cardinality = s1.cardinality();
	
	while (set1_current < set1_cardinality)
	{
		if (!s2.isElement(s1[set1_current]))
		{
			return false;
		}
		set1_current++;
	}

	return true;
}

// Returns true if s1 is a proper subset of s2
bool isProperSubSet(const Set<char>& s1, const Set<char>& s2)
{
	if (s1.cardinality() >= s2.cardinality()) return false;

	size_t set1_current = 0;
	size_t set1_cardinality = s1.cardinality();
	
	while (set1_current < set1_cardinality)
	{
		if (!s2.isElement(s1[set1_current]))
		{
			return false;
		}
		set1_current++;
	}

	return true;
}

// Returns the Power Set of set s as a set of sets
Set<Set<char>> PowerSet(const Set<char>& s)
{
	Set<Set<char>> result;

	size_t length = s.cardinality();
	size_t num_of_subsets = 1 << length;

	for (size_t i = 0; i < num_of_subsets; ++i)
	{
		Set<char> subset;

		for (size_t j = 0; j < length; ++j)
		{
			if (i & (1 << j))
			{
				subset.insertElement(s[j]);
			}
		}

		result.insertElement(subset);
	}

	return result;
}

// Returns true if the sets in p make up a Partition of set s
bool isPartition(const Set<Set<char>>& p, const Set<char>& s)
{
	return (p == PowerSet(s)) ? true : false;
}