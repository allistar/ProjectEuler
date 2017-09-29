#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

 * 
 */

int main() {
  long digit, i, j, sum, answerSum = 0;
  char *text = (char*)malloc(64);
  
  for (i=2;i<=1000000;i++) {
    //get the individual digits out
    sprintf(text, "%li", i);
    sum = 0;
    for (j=0;j<strlen(text);j++) {
      sum += pow(*(text + j) - '0', 5);
    }

    if (sum == i) {
      //we have a match
      answerSum += sum;
      printf("Match: %li\n", i);
    }
  }

  printf("Answer: %li\n", answerSum);
  
  free(text);
  return 0;
}
