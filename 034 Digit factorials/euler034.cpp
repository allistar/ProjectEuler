#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 *

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.

 * 
 */

int factorial(int n) {
	int product = 1;
	for(int i=2; i<=n; i++) {
		product *= i;
	}
	return product;
}

int sumOfDigitFactorialsLimited(int n, int factorials[]) {
	int sum = 0, digit, number = n;
	while (number > 0) {
		digit = (number % 10);
		sum += factorials[digit];
		//see if it's too large
		if (sum > n) {
			return 0;
		}
		number = number / 10;
	}
	return sum;
}

int main() {
	int i, sum = 0;
	int factorials[10];
	//calculate factorials
	for (i=0;i<10;i++) {
		factorials[i] = factorial(i);
	}

	for (i=11; i<100000; i++) {
		if (sumOfDigitFactorialsLimited(i, factorials) == i) {
			printf("%i\n", i);
			sum += i;
		}
	}

	printf("Finished. Sum is %i\n", sum);
	return 0;
}
