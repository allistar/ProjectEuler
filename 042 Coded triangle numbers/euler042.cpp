#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 *

The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

 * 
 */

inline bool isInArray(int array[100], int n) {
	for(int i=0;i<=100;i++) {
		if (array[i] == n) {
			return true;
		}
		if (array[i] > n) {
			return false;
		}
	}
	return false;
}

int main() {
  //NOTE: the file was sorted using this shell command:
  // tr , '\n' < p042_words.txt | tr -d '"' > p042_words_cleaned.txt

  FILE *file = fopen("p042_words_cleaned.txt", "r");
  char *word = (char*)malloc(128);
  char *letter;
  int pos = 0, wordSum, count = 0;

  //work out the first 100 triangle numbers
  int triangleNumbers[100];
  for(int i=0;i<=100;i++) {
  	triangleNumbers[i] = 0.5 * i * (i + 1);
  }

  while (fgets(word, 128, file)) {
    pos++;

    letter = word;
    wordSum = 0;
    while (*letter != '\n') {
      wordSum += (*letter - 'A' + 1);
      letter++;
    }
	//is this a triangle number?
	if (isInArray(triangleNumbers, wordSum)) {
		count++;
	}
  }

  fclose(file);

  printf("%i of the words are triangle words\n", count);
  return 0;
}
