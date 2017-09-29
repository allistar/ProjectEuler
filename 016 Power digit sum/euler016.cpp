#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

 */

int main() {
  cpp_int number = boost::multiprecision::pow(cpp_int(2), 1000);
  cpp_int sum=0;
  
  string text = number.str();
    
  for(std::string::size_type i = 0; i < text.size(); ++i) {
    sum += (text[i] - '0');
  }
  
  cout << "Answer: " << sum << "\n";
  return 0;
}
