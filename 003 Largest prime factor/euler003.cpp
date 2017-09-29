#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;

/**
 * 

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

 * 
 */

int main() {
  cpp_int number = 600851475143,
    currentNumber = number,
    largestPrimeFactor = 0,
    currentFactor;
  
  //brute force approch
  for(currentFactor=2;currentFactor<number;currentFactor++) {
    while (currentNumber % currentFactor == 0) {
      //keep dividing
      currentNumber /= currentFactor;
    }
    if (currentNumber == 1) {
      break;
    }
  }
  
  std::cout << "Answer: " << currentFactor << "\n";

  return 0;
}
