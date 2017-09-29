#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 
 * 

The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 ? 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

 */

int main() {
  const int range = 100;
  int sum1 = 0,
    sum2 = 0,
    i;
    
  for (i=1;i<=range;i++) {
    sum1 += i*i;
    sum2 += i;
  }
  
  sum2 *= sum2;
  
  cout << "Answer: " << (sum2 - sum1) << "\n";

  return 0;
}
