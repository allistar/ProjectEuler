#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 
 *
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

 */

inline bool isPrime(int number) {
  int i;
  float limit = sqrt(number) + 1;

  //test 1 and 2
  if (number == 1) {
  	return false;
  }
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

inline bool isTruncatablePrime(int number) {
	int length = 0, digit;
	int n = number, truncated;
	int i;

	//count the number of digits
	while (n > 0) {
		digit = n % 10;
		//is this a legal digit?
		if ((digit == 4) || (digit == 6) || (digit == 8)) {
			return false;
		}
		n /= 10;
		length++;
	}

	//truncate from the left
	i = length;
	while (i > 0) {
		truncated = number % (int)pow(10, i);
		//is this number a prime?
		if (!isPrime(truncated)) {
			return false;
		}
		i--;
	}

	//truncate from the right
	i = 1;
	while (i < length) {
		truncated = number / pow(10, i);
		//is this number a prime?
		if (!isPrime(truncated)) {
			return false;
		}
		i++;
	}
	return true;
}

int main() {
	int i = 0;
	int limit = pow(10, 6);
	int sum = 0, count = 0;


	for (i=11; i<=limit; i+=2) {
		if (isTruncatablePrime(i)) {
			printf("%i is a truncatable prime\n", i);
			sum += i;
			count++;
			if (count == 11) {
				break;
			}
		}
	}

	printf("Sum of truncatable primes: %i\n", sum);
    return 0;
}
