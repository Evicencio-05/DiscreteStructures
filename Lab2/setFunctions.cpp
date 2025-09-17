#include "setFunctions.h"
#include "set.h"
#include "set.cpp"

using namespace std;
// Returns a set that is the Union of the two sets s1 and s2
Set<char> setUnion(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;

	size_t i = 0, j = 0;
    size_t s1_cardinality = s1.cardinality();
    size_t s2_cardinality = s2.cardinality();

    while (i < s1_cardinality && j < s2_cardinality)
    {
        if (s1[i] < s2[j]) {
            result.insertElement(s1[i++]);
        } else if (s2[j] < s1[i]) {
            result.insertElement(s2[j++]);
        } else { // Elements are equal
            result.insertElement(s1[i++]);
            j++;
        }
    }

    while (i < s1_cardinality) {
        result.insertElement(s1[i++]);
    }

    while (j < s2_cardinality) {
        result.insertElement(s2[j++]);
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
	size_t p_cardinality = p.cardinality();
	Set<char> union_set;
	for (size_t i = 0; i < p_cardinality; ++i)
	{
		// False if the intersection between the union set and current set is greater than 0
		if (setIntersection(union_set, p[i]).cardinality() > 0) return false;
		
		// False if the current set is an empty set
		if (p[i].cardinality() == 0) return false;
		
		union_set = setUnion(union_set, p[i]);
	}
	
	return (union_set == s) ? true : false;
}