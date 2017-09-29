#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

n! means n × (n ? 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

 * 
 */

int main() {
  cpp_int number = 1,
    sum = 0;
  int i;
  
  for (i=1;i<=100;i++) {
    number *= i;
  }
  
  string text = number.str();
    
  for(std::string::size_type i = 0; i < text.size(); ++i) {
    sum += (text[i] - '0');
  }  
  cout << sum << "\n";
  
  return 0;
}
