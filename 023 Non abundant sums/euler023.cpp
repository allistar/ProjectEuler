#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as
the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

 * 
 */

bool isAbundant(int number) {
  int i,
    sum = 1,
    remainder = number, p;
  
  if (number == 0) {
     return false;
  }
  for(i=2; i*i<=remainder;i++) {
    p = 1;
    while (remainder % i == 0) {
      p = p*i + 1;
      remainder/=i;
    }
    sum *= p;
  }
  if (remainder > 1)
    sum*=1+remainder;
  sum -= number;
  return sum > number;
}

int main() {
  const int limit = 28123;
  int i, j, count = 0;
  int sum = 0;
  int abundantNumbers[limit];
  bool sumOfAbundantNumbers[limit] = {false};
    
  //first find all abundant numbers < 28123
  for (i=0; i<=limit; i++) {
     if (isAbundant(i)) {
       abundantNumbers[count++] = i;
     }
  }

  //now find all numbers that cannot be written as a sum of two abundant numbers
  for (i=0; i<count; i++) {
    for (j=0; j<count; j++) {
      if (abundantNumbers[i] + abundantNumbers[j] > limit) {
	continue;
      }
      sumOfAbundantNumbers[abundantNumbers[i] + abundantNumbers[j]] = true;
    }
  }
  
  //count what we have
  for (i=0; i<=limit; i++) {
    if (!sumOfAbundantNumbers[i]) {
      sum += i;
    }
  }
  
  printf("Answer: %i\n", sum);
  return 0;
}
