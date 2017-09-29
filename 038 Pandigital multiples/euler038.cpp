#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

Take the number 192 and multiply it by each of 1, 2, and 3:

    192 ? 1 = 192
    192 ? 2 = 384
    192 ? 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?

 */

bool isPandigital(int n1) {
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

	return result == 0x1ff;
}

inline int getLength(int n, int powers[]) {
	for (int i=0; i<9; i++) {
		if (n < powers[i]) {
			return i;
		}
	}
}

int main() {
	int i, j, current, largest = 0, product, currentLength, productLength;

	//populate powers of 10
	int powers[9] = {1};
	for (i = 1; i<9; i++) {
		powers[i] = powers[i-1] * 10;
	}

	for (i=1; i<10000; i++) {
		current = 0;
		currentLength = 0;
		for (j=1; j<=9; j++) {
			product = i * j;
			productLength = getLength(product, powers);
			//see if it will be too long
			if (currentLength + productLength > 9) {
				break;
			}
			//concatenate the product to "current" by shifting "current" along and adding "product"
			current = current * powers[productLength] + product;

			currentLength += productLength;
			//see if the product length is exactly 9
			if (currentLength == 9) {
				//see if it's pandigital
				if (isPandigital(current)) {
					printf("%i is pandigital (%i x {1..%i})\n", current, i, j);
					if (current > largest) {
						largest = current;
					}
				}
				break;
			}
		}
	}

	printf("The largest pandigital multiple is %i\n", largest);
    return 0;
}
