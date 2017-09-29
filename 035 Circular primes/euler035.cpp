#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 
 *
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?

 */

bool isPrime(int number) {
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

int getRotation(int number, int digitCount, int rotation) {
	//rotating by 1 means going from 1234 to 4123
	int multiplier1 = pow(10, rotation);
	int multiplier2 = pow(10, digitCount - rotation);
	return ((number % multiplier1) * multiplier2) + (number / multiplier1);
}

bool isCircularPrime(int number) {
	//get the number of digits for this number
	int digitCount = 0, rotation, n = number, digit;

	while (n != 0) {
		digit = n % 10;
		//do a quick bail - this cannot be circular prime if digit is 0, 2, 4, 5, 6 or 8
		if ((digit == 2) || (digit == 4) || (digit == 5) || (digit == 6) || (digit == 8) || (digit == 0)) {
			return false;
		}

		digitCount++;
		n = n / 10;
	}

	//is this number prime?
	if (!isPrime(number)) {
		return false;
	}

	//rotate the number as many times as there are digits less 1 (we've already tested the original rotation)
	for (n=1; n<digitCount; n++) {
		rotation = getRotation(number, digitCount, n);
		//test this for prime-ness
		if (!isPrime(rotation)) {
			return false;
		}
	}

	return true;
}

int main() {
 	int i, limit=1000000, count = 4;

 	//start at 11, "count" already includes 2, 3, 5, 7. Only check odd numbers
 	for (i=11; i<limit; i+=2) {
 		if (isCircularPrime(i)) {
 			count++;
 		}
 	}

 	printf("There are %i circular primes less than %i\n", count, limit);
    return 0;
}
