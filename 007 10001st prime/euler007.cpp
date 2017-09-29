#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

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
  int i=2,
    count = 0;
  
  while (true) {
     count += isPrime(i) ? 1 : 0;
     
     if (count == 10001) {
       break;
     }

     i++;
  }
  
  cout << "Answer: " << i << "\n";
  return 0;
}
