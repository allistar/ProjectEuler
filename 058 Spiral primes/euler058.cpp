#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?

 * 
 */

inline bool isPrime(int number) {
  int i;
  float limit = sqrt(number) + 1;

  //test 2
  if (number == 2) {
    return true;
  }
  //test divisibility by 2
  if (number % 2 == 0) {
    return false;
  }
  for (i=3;i<limit;i+=2) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
	int number = 3, gap = 2;
	int primes = 0, total = 1;
	
	while (true) {
		//Top right
		total++;
		if (isPrime(number))
			primes++;
		
		//Top left
		number += gap;
		total++;
		if (isPrime(number))
			primes++;

		//bottom left
		number += gap;
		total++;
		if (isPrime(number))
			primes++;

		//bottom right
		number += gap;
		total++;
		if (isPrime(number))
			primes++;
		
		number += 1;
		number += gap + 1;
		gap = gap+2;

		if (primes * 10 < total)
			break;
	}
	printf("%i %f\n", gap - 1, (float)primes * 100.00 / float(total));
	
	return 0;
}
