#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 *

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

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

inline bool isPandigital(int n1, int bitChecks[]) {
	int result = 0, digit, bits, length = 0;

	//1st
	while (n1 > 0) {
		digit = (n1 % 10);
		if (digit == 0) {
			return false;
		}
		bits = (1 << (digit - 1));
		if ((result & bits) != 0) {
			return false;
		}
		result |= bits;
		n1 = n1 / 10;
		length++;
	}

	return result == bitChecks[length];
}

int main() {
	int i;
	int bitChecks[9];
	//build the integers that help us check a number of length i is it's pandigital
	for(i=1;i<=9;i++) {
		bitChecks[i] = pow(2, i) - 1;
	}

	//NOTE: a 9 digit pandigital number can't be prime
	//NOTE: an 8 digit pandigital number can't be prime
	for(i=7654321;i>1;i-=2) {
		if (isPandigital(i, bitChecks) && isPrime(i)) {
			printf("The largest pandigital prime is %i\n", i);
			break;
		}
	}
    return 0;
}
