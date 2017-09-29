#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 
 *
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

 */

int isDigitCancelling(int i, int j) {
	int i1, i2, j1, j2;
	double result = (double)i / j, trial;
	//get the digits
	i1 = i / 10;
	i2 = i % 10;
	j1 = j / 10;
	j2 = j % 10;

	if (i >= j) {
		return 0;
	}

	//do any digits match? (making sure to avoid dividing by zero!)
	if (i1 && (i1 == j1) && j2) {
		trial = (double)i2 / j2;
		if (trial == result) {
			return i1;
		}
	}

	if (i1 && (i1 == j2) && j1) {
		trial = (double)i2 / j1;
		if (trial == result) {
			return i1;
		}
	}

	if (i2 && (i2 == j1) && j2) {
		trial = (double)i1 / j2;
		if (trial == result) {
			return i2;
		}
	}

	if (i2 && (i2 == j2) && j1) {
		trial = (double)i1 / j1;
		if (trial == result) {
			return i2;
		}
	}
	return 0;
}

int main() {
	int i, j, cancelledDigit, productI = 1, productJ = 1;

	for (i=10;i<100;i++) {
		for (j=10;j<100;j++) {
			cancelledDigit = isDigitCancelling(i, j);
			if (cancelledDigit) {
				printf("Yes, %i and %i can have the %i digit cancelled\n", i, j, cancelledDigit);
				productI *= i;
				productJ *= j;
			}
		}
	}

	printf("%i/%i = %f\n", productI, productJ, ((double)productI / productJ));
	return 0;
}
