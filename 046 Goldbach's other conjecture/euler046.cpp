#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 *

It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

 */
int PrimeLimit = 10000;

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

inline bool isSquare(int n) {
	double result = sqrt(n);
	return result - int(result) == 0;
}

int main() {
	int i = 2, j, prime, primeListCount = 0, primeListSize;
	bool primeFlags[PrimeLimit] = {false};
	int primes[PrimeLimit] = {0};
	int halfDifference;
	bool found;

	while (i < PrimeLimit) {
		if (isPrime(i)) {
			primeFlags[i] = true;
			primes[primeListCount++] = i;
		}
		i++;
	}
	primeListSize = primeListCount;

	for (i=3;i<PrimeLimit;i+=2) {
		//we only care about composite numbers
		if (primeFlags[i]) {
			continue;
		}
		found = false;
		for(j=0;j<primeListSize;j++) {
			prime = primes[j];
			if (prime > i) {
				break;
			}
			//see if half the difference is a square number
			if ((i - prime) % 2 != 0) {
				continue;
			}
			if (isSquare((i - prime) / 2)) {
				found = true;
				break;
			}
		}
		if (!found) {
			break;
		}
	}

	printf("%i has no match\n", i);
    return 0;
}
