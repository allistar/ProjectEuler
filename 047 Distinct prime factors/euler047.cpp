#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 
 *

The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?

 */

int numberOfDistinctPrimeFactors(int n) {
	int i = 2, prev = 0, count = 0, increment = 1;

	while (i <= n) {
		if (n % i == 0) {
			n = n / i;
			if (i != prev) {
				count++;
				prev = i;
			}
		} else {
			i+=increment;
			if (i == 3) {
				increment = 2;
			}
		}
	}

	return count;
}

int main() {
	int i = 2;

	while (true) {
		//first number
		if (numberOfDistinctPrimeFactors(i++) != 4) {
			continue;
		}
		//second number
		if (numberOfDistinctPrimeFactors(i++) != 4) {
			continue;
		}
		//third number
		if (numberOfDistinctPrimeFactors(i++) != 4) {
			continue;
		}
		//forth number
		if (numberOfDistinctPrimeFactors(i++) != 4) {
			continue;
		}
		//we have 4 in a row!
		printf("The first of the four numbers in a row is %i\n", i - 4);
		break;
	}
    return 0;
}
