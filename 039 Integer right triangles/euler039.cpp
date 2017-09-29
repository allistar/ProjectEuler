#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?

 */

int main() {
	int solutionCount[1000] = {0};
	int a, b, h, p;
	float hypotenuse;

	for (a=1;a<1000;a++) {
		for (b=1;b<1000;b++) {
			//work out the hypotenuse
			hypotenuse = sqrt(a * a + b * b);
			h = int(hypotenuse);
			//is the hypotenuse integral?
			if (hypotenuse - h != 0) {
				continue;
			}
			//work out the perimeter
			p = a + b + h;
			if (p > 1000) {
				continue;
			}
			solutionCount[p]++;
		}
	}

	//work out which perimeter is the most popular
	int i, max=0, maxI=0;
	for (i=1;i<=1000;i++) {
		if (solutionCount[i] > max) {
			max = solutionCount[i];
			maxI = i;
		}
	}

	printf("The most popular perimeter is %i with a count of %i\n", maxI, max);
    return 0;
}
