#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 *
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

 * 
 */

bool isPandigital(int n1, int n2, int n3) {
	int result = 0, digit, bits;

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
	}
	//2nd
	while (n2 > 0) {
		digit = (n2 % 10);
		if (digit == 0) {
			return false;
		}
		bits = (1 << (digit - 1));
		if ((result & bits) != 0) {
			return false;
		}
		result |= bits;
		n2 = n2 / 10;
	}
	//3rd
	while (n3 > 0) {
		digit = (n3 % 10);
		if (digit == 0) {
			return false;
		}
		bits = (1 << (digit - 1));
		if ((result & bits) != 0) {
			return false;
		}
		result |= bits;
		n3 = n3 / 10;
	}

	return result == 0x1ff;
}

bool hasSolution(int solutions[], int solution) {
	for (int i = 0; i<1000; i++) {
		if (solutions[i] == 0) {
			return false;
		}
		if (solutions[i] == solution) {
			return true;
		}
	}
	return false;
}

int sumSolutions(int solutions[]) {
	int sum = 0;
	for (int i = 0; i<1000; i++) {
		if (solutions[i] == 0) {
			return sum;
		}
		sum += solutions[i];
	}
	return sum;
}

int main() {
	int i, j, product, limit;
	int solutions[1000] = {0};
	int solutionSize = 0;

	for (i=1;i<10000;i++) {
		limit = 10000 / i;
		for (j=1;j<limit;j++) {
			product = i * j;
			if (isPandigital(i, j, product)) {
				//we have a solution!
				if (!hasSolution(solutions, product)) {
					printf("%i x %i = %i\n", i, j, product);
					solutions[solutionSize++] = product;
				}
			}
		}
	}

	printf("Finished. The sum of unique solutions is %i.\n", sumSolutions(solutions));
	return 0;
}
