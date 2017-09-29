#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 
 * 

Euler discovered the remarkable quadratic formula:

n² + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

The incredible formula  n² + 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, ?79 and 1601, is ?126479.

Considering quadratics of the form:

    n² + an + b, where |a| < 1000 and |b| < 1000

    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |?4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.

 */

bool isPrime(long number) {
  long i;
  
  //test positive
  if (number <= 1) {
    return false;
  }
  //test 2
  if (number == 2) {
    return true;
  }
  //test divisibility by 2
  if (number % 2 == 0) {
    return false;
  }
  for (i=3;i*i<number;i+=2) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  const int limit = 1000;
  long a, b, n;
  long answer;
  int currentPrimeRun, maximumPrimeRun = 0, maximumA, maximumB;
    
  //a goes from -999 to +999 and must be odd
  for(a=-(limit - 1);a<limit;a += 2) {
    //b goes from 3 to +999 in steps of 2 (because b must be prime)
    for(b=3;b<limit;b += 2) {
      //n goes from 0 to b
      currentPrimeRun = 0;
      //n must be < b and < (b - a)
      for(n=0;n<b && n < b-a;n++) {
	//work out the quadratic
	answer = n * n + a * n + b;
	if (!isPrime(answer)) {
	  break;
	}
	currentPrimeRun++;
      }
      if (currentPrimeRun > maximumPrimeRun) {
	maximumPrimeRun = currentPrimeRun;
	maximumA = a;
	maximumB = b;
      }
    }
  }

  printf("a: %i, b: %i, run length %i\n", maximumA, maximumB, maximumPrimeRun);
  printf("Answer: %i\n", maximumA * maximumB);
  return 0;
}
