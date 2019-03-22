#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/*
 * If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?
*/

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

bool isPalindrome(cpp_int number) {
  string result = boost::lexical_cast<std::string>(number);
  string reversed = result;
  reverse(reversed.begin(), reversed.end());
  return result.compare(reversed) == 0;
}

cpp_int reverseAndSum(cpp_int number) {
	string result = boost::lexical_cast<std::string>(number);
	string reversed = result;
	reverse(reversed.begin(), reversed.end());
	reversed.erase(0, reversed.find_first_not_of('0'));
	cpp_int r = boost::lexical_cast<cpp_int>(reversed);
	return r + number;
}

bool isLycrel(int n) {
	cpp_int sum = n;

//	if (isPalindrome(n)) {
//		return true;
//	}
	
	for (int count=0;count < 50;count++) {
		sum = reverseAndSum(sum);
		if (isPalindrome(sum)) {
			return true;
		}
	}
		
	return false;
}

/**
 * 
 * 
 */
int main() {
    int count = 0;
	for (int i=1; i<10000; i++) {
		if (!isLycrel(i)) {
			count++;
		}
	}
	
	printf("There are %i Lycrel numbers less than 10,000\n", count);
    return 0;
}
