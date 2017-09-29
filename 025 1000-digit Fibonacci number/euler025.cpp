#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn?1 + Fn?2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

 * 
 */

int main() {
  cpp_int n1 = 1,
    n2 = 1,
    n3,
    limit = boost::multiprecision::pow(cpp_int(10), 999),
    index = 2;
  
  while (true) {
    //work out the new term
    n3 = n1 + n2;
    index ++;
    //have we reached the limit?
    if (n3 >= limit) {
      break;
    }

    //swap values around and continue
    n1 = n2;
    n2 = n3;

  }
  
  cout << "Answer: " << index << "\n";
  
  return 0;
}
