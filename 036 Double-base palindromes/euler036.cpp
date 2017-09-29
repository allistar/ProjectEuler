#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

 */

bool isPalindromeBaseN(int n, int base) {
	int digits[32] = {0};
	int size = 0;
	int i = 0, j;
	//get digits
	while (n != 0) {
		digits[size++] = n % base;
		n = n / base;
	}

	//see if it's a palindrome
	j = size - 1;
	if (i == j) {
		return true;
	}
	while (i < j) {
		if (digits[i++] != digits[j--]) {
			return false;
		}
	}
	return true;
}

int main() {
	int i, sum = 0;

	for (i=1;i<1000000;i+=2) {
		if (isPalindromeBaseN(i, 10) && isPalindromeBaseN(i, 2)) {
			sum += i;
		}
	}

	printf("Finished! The sum is %i.\n", sum);
	return 0;
}
