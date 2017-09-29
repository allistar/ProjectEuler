#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 
 * 
 */

int main() {
  int i;
  cpp_int sum;
  
  for(i=1;i<=1000;i++) {
    sum += boost::multiprecision::pow(cpp_int(i), i);
  }
  
  cout << "Answer: " << sum << "\n";
  return 0;
}
