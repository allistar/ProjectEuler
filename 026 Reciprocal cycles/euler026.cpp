#include <boost/multiprecision/cpp_dec_float.hpp>
#include <iostream>
//#include <string>

using namespace boost::multiprecision;
using namespace std;

/**
 * 

A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10	= 	0.1 

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

 * 
 */

const int MAX = 5000;
typedef number<cpp_dec_float<MAX> > cpp_dec_float_big;


bool doesRepeat(char *buffer, int bufferLength, int repeatLength, char *repeat) {
  int found = -1, k;
  //get the repeat
  memcpy(repeat, buffer, repeatLength);
  
  for (k=repeatLength;k<bufferLength - repeatLength;k += repeatLength) {
    found = 1;
    //has it been repeated?
    if (memcmp(buffer + k, repeat, repeatLength) != 0) {
      found = 0;
      break;
    }
  }
 
  return found == 1;
}


int main() {
  int i, repeatStart, repeatLength, len;
  char *jth;
  bool found;
  int maxRepeatLength = 0, maxRepeatNumber = 0, maxRepeatStart = 0;
  int max = MAX + 2;
  
  cpp_dec_float_big fraction;
  stringstream text;
  
  char *buffer = (char*)malloc(MAX + 8);
  char *repeat = (char*)malloc(MAX + 8);
  char *maximum = (char*)malloc(MAX + 8);
  
  for (i=1;i<1000;i++) {
  
    fraction = cpp_dec_float_big(1) / cpp_dec_float_big(i);
    
    text.str("");
    text << std::setprecision(std::numeric_limits<cpp_dec_float_big>::digits10);
    text << fraction;
    
    sprintf(buffer, "%s", text.str().c_str());
    len = strlen(buffer);
    //does it repeat
    if (len < max) {
      continue;
    }
    //lose the last character because of rounding
    *(buffer + len - 1) = '\0';
    len--;
    
    //does this have repeating digits?
    //start at 2 to skip the first "0."    
    found = false;
    //start the repeat length at 6 as we know 1/7 has a 6 long repeat
    for (repeatStart=2; repeatStart < max; repeatStart++) {
      for (repeatLength = 1; repeatLength < MAX; repeatLength++) {
	found = doesRepeat(buffer + repeatStart, len - repeatStart, repeatLength, repeat);
	if (found && (repeatLength > maxRepeatLength)) {
	    maxRepeatLength = repeatLength;
	    maxRepeatNumber = i;
	    maxRepeatStart = repeatStart;
	    sprintf(maximum, "%s", buffer);	  
	}
	if (found) {
	  break;
	}
      }
      if (found) {
	break;
      }
    }
  }

  printf("Answer: %i with a repeat length of %i starting at %i\n", maxRepeatNumber, maxRepeatLength, maxRepeatStart);
  printf("%s\n", maximum);
  
  free(buffer);
  free(repeat);
  free(maximum);
  
  return 0;
}

/*

//A mathematical solution:

int main(){
  int i,value,max,counter,max2,z;
  max=0;
  for (i=1;i<1000;i++){
    counter=0;
    value = 10%i;
    z=1000;

    //multiply by ten then divide by i, if the answer is 1 then this is the end of the repeat.
    //this is like long division.
    while (value != 1 && z>0){
      value = value *10;
      value = value % i;
      counter++;
      z--;
    }

    if (counter>max && z>1){
      max=counter;
      max2=i;
    }
  }
  printf("%d\n",max2);
return 0;
}
