#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 
 *

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

    d2d3d4=406 is divisible by 2
    d3d4d5=063 is divisible by 3
    d4d5d6=635 is divisible by 5
    d5d6d7=357 is divisible by 7
    d6d7d8=572 is divisible by 11
    d7d8d9=728 is divisible by 13
    d8d9d10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.

 */
inline int section(char string[], int start) {
	int i = (*(string + start - 1) - 48) * 100;
	i += (*(string + start) - 48) * 10;
	i += (*(string + start + 1) - 48);
	return i;
}

bool matches(char string[]) {
	return ((section(string, 2) % 2 == 0)  &&
		(section(string, 3) % 3 == 0) &&
		(section(string, 4) % 5 == 0) &&
		(section(string, 5) % 7 == 0) &&
		(section(string, 6) % 11 == 0) &&
		(section(string, 7) % 13 == 0) &&
		(section(string, 8) % 17 == 0));
}

int main() {
	char string[] = "1234567890";
	char *end = string + strlen(string);
	unsigned long long number, sum = 0;

	do {
		if (*string == '0') {
			continue;
		}

		if (matches(string)) {
			number = atoll(string);
			printf("%llu passes. %s\n", number, string);
			sum += number;
		}
	} while (next_permutation(string, end));

	printf("\nThe sum is %llu\n", sum);
    return 0;
}
