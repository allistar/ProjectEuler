#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

 * 
 */

const char *getTextForLowNumber(int number) {
    switch(number) {
      case 90: return "ninety";
      case 80: return "eighty";
      case 70: return "seventy";
      case 60: return "sixty";
      case 50: return "fifty";
      case 40: return "forty";
      case 30: return "thirty";
      case 20: return "twenty";
      case 19: return "nineteen";
      case 18: return "eighteen";
      case 17: return "seventeen";
      case 16: return "sixteen";
      case 15: return "fifteen";
      case 14: return "fourteen";
      case 13: return "thirteen";
      case 12: return "twelve";
      case 11: return "eleven";
      case 10: return "ten";
      case 9: return "nine";
      case 8: return "eight";
      case 7: return "seven";
      case 6: return "six";
      case 5: return "five";
      case 4: return "four";
      case 3: return "three";
      case 2: return "two";
      case 1: return "one";
      default: return "";
    }
}

void getTextForNumber(int number, char *text) {
  char word[4];
  int i, digit;
  sprintf(text, '\0');
  sprintf(word, "%i", number);

  int len = strlen(word),
    tens, hundreds = 0, thousands = 0;
  
  
  if (number < 100) {
    tens = number;
  } else if (number < 1000) {
    tens = (10 * (word[len - 2] - '0')) + (word[len - 1] - '0');
    hundreds = (word[len - 3] - '0');
  } else {
    tens = (10 * (word[len - 2] - '0')) + (word[len - 1] - '0');
    thousands = (word[len - 4] - '0');
    hundreds = (word[len - 3] - '0');
  }

  if (thousands) {
    sprintf(text, "%s %s thousand", text, getTextForLowNumber(thousands));
  }
  
  if (hundreds) {
    sprintf(text, "%s %s hundred", text, getTextForLowNumber(hundreds));    
  }
    
  if (tens) {
    if (thousands || hundreds) {
      sprintf(text, "%s and", text);
    }
    sprintf(word, "%i", tens);
    if (tens <= 20) {
      sprintf(text, "%s %s", text, getTextForLowNumber(tens));    
    } else {      
      sprintf(text, "%s %s", text, getTextForLowNumber(10 * (word[0] - '0')));    
      sprintf(text, "%s %s", text, getTextForLowNumber(word[1] - '0'));
    }
  }
}

int countNonSpaces(char *text) {
    int len = strlen(text),
      i, sum = 0;
    
    for (i=0; i<len; i++) {
      if (text[i] != ' ') {
	sum++;
      }
    }
    return sum;
}

int main() {
  char *text = (char*)malloc(512);
  int i, sum, total = 0;
  
  for (i=1;i<=1000;i++) {
    getTextForNumber(i, text);
    sum = countNonSpaces(text);
    total += sum;
  }

  printf("Answer: %i\n", total);
  return 0;
}
