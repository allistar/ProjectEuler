#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>


using boost::multiprecision::cpp_int;
using namespace std;
/**
 * 
 
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

 * 
 */

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

bool isPalindrome(int number) {
  string result = convertInt(number);
  string reversed = result;
  reverse(reversed.begin(), reversed.end());
  return result.compare(reversed) == 0;
}

int main() {
  int int1, int2, product, largestPalindrome = 0;
  
  for (int1=100;int1<=999;int1++) {
    for (int2=100;int2<=999;int2++) {
      product = int1 * int2;
      //is this a palindrome?
      if (isPalindrome(product) && (product > largestPalindrome)) {
	largestPalindrome = product;
      }
    }    
  }
  
  //display the result
  cout << "Answer: " << largestPalindrome << "\n";

  return 0;
}
