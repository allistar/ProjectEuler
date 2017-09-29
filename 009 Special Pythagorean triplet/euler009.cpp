#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 
 * 

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

 */

int main() {
  int a, b, c;
  
  //brute force
  for (a=1;a<1000;a++) {
    for (b=a;b<1000;b++) {
      //c must be (1000 - a - b)
      c = 1000 - a - b;
      if ((c < b) || (c < a)) {
	continue;
      }
      
      //is it a triplet?
      if (a*a + b*b != c*c) {
	continue;
      }
      
      //we have it!
      printf("a=%i, b=%i, c=%i\n", a, b, c);
      printf("Answer: %i\n", a * b * c);
      return 0;
    }
  }
  
  return 0;
}
