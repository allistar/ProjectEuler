#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

1 1
2 25
3 101
 * 
 */


int main() {
  const int maxWidth = 1001;
  int sum = 1, shell = 1, width, square;
  
  for (shell=2, width=3; width <= maxWidth; shell++, width = shell * 2 - 1) {
    //the starting diagonal (top right) on this shell is width^2
    square = width * width;
    sum += square;
    //the other 3 diagonals on this row are width - 1 apart
    sum += 3 * square - 6 * (width - 1);    
  }
  
  printf("Answer: %i\n", sum);
  return 0;
}
