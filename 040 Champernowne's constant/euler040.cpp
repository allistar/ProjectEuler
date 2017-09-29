#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

 * 
 */

int main() {
  char *text = (char*)malloc(2000000);
  char *number = (char*)malloc(8);
  int i=1, len = 0, digits, result;
  
  while (len <= 1000000) {
    sprintf(number, "%i", i);
    digits = strlen(number);
    
    memcpy(text + len, number, digits);
    len += digits;
    
    i++;
  }
    
  result = (*text - '0') *
      (*(text + 9) - '0') *
      (*(text + 99) - '0') *
      (*(text + 999) - '0') *
      (*(text + 9999) - '0') *
      (*(text + 99999) - '0') *
      (*(text + 999999) - '0');
  
  printf("Answer: %i\n", result);
  
  free(number);
  free(text);

  return 0;
}
