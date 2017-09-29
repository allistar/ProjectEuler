#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

 * 
 */

bool isPrime(int number) {
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
  const int limit = 2000000;
  int i=2;
  cpp_int sum = 0;
  
  for (i=2;i<limit;i++) {
    if (isPrime(i)) {
      sum += i;
    }
  }
  
  cout << "Answer: " << sum << "\n";
  return 0;
}