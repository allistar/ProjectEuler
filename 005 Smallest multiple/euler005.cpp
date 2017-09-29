#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

 * 
 */

int main() {
  int number=2520,
    factor;
  bool divisible;
  
  while (true) {
    //is this number divisible by 1..20?
    divisible = true;
    
    for (factor=2;factor<=20;factor++) {
      if (number % factor != 0) {
	divisible = false;
	break;
      }
    }
    
    if (divisible) {
      break;
    }
    
    number++;
  }
  
  cout << "Answer: " << number << "\n";
  return 0;
}
