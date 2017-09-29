#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 *

The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?

 * 
 */

inline bool isPrime(int number) {
  int i;
  float limit = sqrt(number) + 1;

  //test 2
  if (number == 2) {
    return true;
  }
  //test divisibility by 2
  if (number % 2 == 0) {
    return false;
  }
  for (i=3;i<limit;i+=2) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

bool isPermutation(int a, int b) {
	int digitsA[10] = {0};
	int i;
	//get the digits of a
	while (a > 0) {
		digitsA[a % 10]++;
		a /= 10;
	}
	//get the digits of b, see if they're in a
	while (b > 0) {
		digitsA[b % 10]--;
		b /= 10;
	}
	//we have matching digits if digitsA is all zeros
	for(i=0;i<10;i++) {
		if (digitsA[i]!= 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int i, prime, perm1, gap;
	bool primes[10000] = {false};
	char *string = (char*)malloc(5);

	//get all 4 digit primes
	for (i=1000; i<=9999;i++) {
		primes[i] = isPrime(i);
	}
	//walk all 4 digit primes
	for(prime=1000;prime<=9999;prime++) {
		if (!primes[prime]) {
			continue;
		}
		sprintf(string, "%i", prime);
		//get permutations
		while (next_permutation(string, string + 4)) {
			perm1 = atoi(string);
			if (!primes[perm1]) {
				continue;
			}
			//get the gap between that permutation and the original prime
			gap = perm1 - prime;
			if ((gap < 0) || (perm1 + gap > 9999)) {
				continue;
			}
			//see if the number plus the gap is also a prime and is a permutation
			if (primes[perm1 + gap] && isPermutation(prime, perm1 + gap)) {
				printf("%i, %i, %i (%i)\n", prime, perm1, perm1 + gap, gap);
			}
		}
	}
	free(string);
    return 0;
}
