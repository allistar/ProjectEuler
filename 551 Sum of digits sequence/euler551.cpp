#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
//#include <unordered_map>
#include <map>


using boost::multiprecision::cpp_int;
using namespace std;

typedef unsigned long long ull;
/**
 * 
 *

Let a0, a1, a2, ... be an integer sequence defined by:

    a0 = 1;
    for n ≥ 1, an is the sum of the digits of all preceding terms.

The sequence starts with 1, 1, 2, 4, 8, 16, 23, 28, 38, 49, ...
You are given a106 = 31054319.

Find a1015.

 */

inline ull digitSum(ull number) {
	ull newSum = 0;
	int digit;

	while (number > 0) {
		digit = number % 10;
		number = number / 10;
		//accumulate the digit
		newSum += digit;
	}

	return newSum;
}

struct CacheValue {
	ull index;
	ull sum;
};

typedef std::pair<ull,ull> CacheKey;
typedef std::map<CacheKey, CacheValue> CacheType;

inline CacheValue *findInCache(ull a, ull b, CacheType *cache) {
	CacheType::iterator it = cache->find(std::make_pair(a, b));
	if (it == cache->end()) {
		return NULL;
	}
	return &(it->second);
}

inline void insertInCache(ull a, ull b, ull index, ull sum, CacheType *cache) {
	CacheValue value;
	value.index = index;
	value.sum = sum;

	cache->insert(std::make_pair( std::make_pair(a, b), value));
}

void calculate(ull ds1, ull s2, ull modulus, CacheType *cache, ull *newIndex, ull *newSum) {
	//see if we have a value in the cache for this
	CacheValue *value = findInCache(ds1, s2, cache);
	if (value != NULL) {
		*newIndex = value->index;
		*newSum = value->sum;
		return;
	}

	ull i = 0;
	ull s = s2;
	while (s < modulus) {
		i++;
		s += digitSum(s) + ds1;
	}
	s = s % modulus;
	//insert this into the cache
	insertInCache(ds1, s2, i, s, cache);
	//return the result
	*newIndex = i;
	*newSum = s;
}

int main() {
	CacheType cache;

	ull s1 = 0, s2 = 1, di, sn;
	ull limit = pow(10, 15);
	ull modulus = pow(10, 8);
	ull i=1;

	while (i < limit - modulus) {
		calculate(digitSum(s1), s2, modulus, &cache, &di, &sn);
		i += di;
		s1 += 1;
		s2 = sn;
	}

	ull s = s1 * modulus + s2;
	while (i < limit) {
		i++;
		s += digitSum(s);
	}

	printf("The answer is %llu\n", s);
	return 0;
}

/*
Results:
Modulus 10^10: 82m58s
Modulus  10^9: 10m14.5s.
Modulus  10^8:  8m 6.03s
Modulus  10^7: took too long
*/
