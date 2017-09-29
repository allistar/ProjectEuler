#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 
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

int Limit = 1000000;

int main() {
	int primes[Limit] = {0};
	int primeChecks[Limit] = {false};

	int longestRun = 0, longestRunStart;
	int start;
	int i, j = 0, prime, primeCount;
	unsigned long long longestSum = 0;
	unsigned long long currentSum;

	//get all primes up to 1,000,000
	primes[primeCount++] = 2;
	for(i=3;i<Limit;i+=2) {
		if (isPrime(i)) {
			primes[primeCount++] = i;
			primeChecks[i] = true;
		}
	}
	//walk the primes
	start = 0;
	while (start < Limit - longestRun) {
		currentSum = 0;

		for(i=start;i<=primeCount;i++) {
			prime = primes[i];
			currentSum += prime;
			if (currentSum >= Limit) {
				break;
			}
			if ((currentSum < longestSum) || !primeChecks[currentSum]) {
				continue;
			}
			//this sum is a prime and it's a longer run than we've seen so far
			if (i - start + 1 > longestRun) {
				longestRun = i - start + 1;
				longestRunStart = start;
				longestSum = currentSum;
			}
		}
		start++;
	}

	printf("Longest run of %i terms starting at %i and summing to %llu\n", longestRun, primes[longestRunStart], longestSum);
    return 0;
}
