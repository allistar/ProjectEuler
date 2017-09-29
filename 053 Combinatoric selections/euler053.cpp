#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 *

There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general,
nCr =
n!
r!(n−r)!
	,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.

It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?

 * 
 */
int Limit = 100;
int Target = 1000000;

int main() {
	cpp_int factorials[Limit+1] = {0};
	cpp_int nCr;
	int i, n, r, count = 0;
	//calculate factorials
	factorials[0] = 1;
	for(i=1;i<=Limit;i++) {
		factorials[i] = factorials[i-1] * i;
	}

	for (n=23;n<=Limit;n++) {
		for (r=1;r<=n;r++) {
			nCr = factorials[n] / (factorials[r] * factorials[n-r]);
			if (nCr > 1000000) {
				count++;
			}
		}
	}

	printf("Answer: %i\n", count);
    return 0;
}
