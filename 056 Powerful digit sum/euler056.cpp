#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**

A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?

 * 
 */

int sumIt(cpp_int number) {
	string text = number.str();
	int sum = 0;
	for(std::string::size_type i = 0; i < text.size(); ++i) {
		sum += (text[i] - '0');
	}	
	return sum;
}

int main() {
	cpp_int power, maxPower;
	int sum, maxSum = 0;
	
	for (int i=1;i<=100;i++) {
		for (int j=1;j<=100;j++) {
			power = boost::multiprecision::pow(cpp_int(i), j);
			sum = sumIt(power);
			if (sum > maxSum) {
				maxSum = sum;
				maxPower = power;
			}
		}
	}
	
	printf("The maximum sum is %i\n", maxSum);
	cout << maxPower << "\n";
	return 0;
}
