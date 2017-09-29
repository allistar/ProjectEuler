#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 *

It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

 * 
 */

inline bool hasSameDigits(int a, int b) {
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
	int i = 1;

	while (true) {
		if (hasSameDigits(i, i*2) &&
				hasSameDigits(i, i*3) &&
				hasSameDigits(i, i*4) &&
				hasSameDigits(i, i*5) &&
				hasSameDigits(i, i*6)) {
			break;
		}
		i++;
	}

	printf("Answer: %i\n", i);
    return 0;
}
