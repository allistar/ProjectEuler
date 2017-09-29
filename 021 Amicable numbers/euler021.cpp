#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ? b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

 * 
 */


int sumOfDivisors(int number) {
  int i,
    sum = 1;
  float root = sqrt(number) + 1;
  
  for (i=2;i<root;i++) {
    if (number % i == 0) {
      sum += i;
      sum += number / i;
    }
  }
  return sum;
}


int main() {
  int i,
    factorSum, sum = 0;
  
  for (i = 1; i<10000; i++) {
    factorSum = sumOfDivisors(i);
    if ((factorSum != i) && (sumOfDivisors(factorSum) == i)) {
      printf("%i, %i\n", i, factorSum);
      sum += i;
    }
  };

  printf("Answer: %i\n", sum);
  return 0;
}
