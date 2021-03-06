#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 *

Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:
Triangle 	  	Tn=n(n+1)/2 	  	1, 3, 6, 10, 15, ...
Pentagonal 	  	Pn=n(3n−1)/2 	  	1, 5, 12, 22, 35, ...
Hexagonal 	  	Hn=n(2n−1) 	  	1, 6, 15, 28, 45, ...

It can be verified that T285 = P165 = H143 = 40755.

Find the next triangle number that is also pentagonal and hexagonal.

 */

inline bool isPentagonNumber(unsigned long long n) {
	double result = (sqrt((24 * n) + 1) + 1) / 6;
	return result - (unsigned long long)(result) == 0;
}

inline unsigned long long getHexagonNumber(unsigned long long n) {
	return n * (2 * n - 1);
}

int main() {
	unsigned long long i = 144;
	unsigned long long triangle, hex;
	double temp;

	while (true) {
		hex = getHexagonNumber(i);
		if (isPentagonNumber(hex)) {
			break;
		}
		i++;
	}

	printf("The answer is %llu (%llu)\n", hex, i);
    return 0;
}
