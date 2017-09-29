#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <map>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

The following iterative sequence is defined for the set of positive integers:

n ? n/2 (n is even)
n ? 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 ? 40 ? 20 ? 10 ? 5 ? 16 ? 8 ? 4 ? 2 ? 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

 * 
 */

inline long collatz(long n) {
  if (n % 2 == 0) {
    return n/2;
  } else {
    return (3 * n) + 1;
  }
}

inline int getChainLength(long start, long long int cache[]) {
  long i = start,
    count = 0;
  
  while (i != 1) {    
    //have we already worked out the chain length for this starting number?
    if ((i < 1000001) && (cache[i] != 0)) {
      count += cache[i];
      break;
    }
    
    i = collatz(i);
    count++;
  }
  
  //cache this
  if (start < 1000001) {
    cache[start] = count;
  }
  return count;
}

int main() {
  long start = 1,
    longestStart = 0,
    chainLength,
    longestChainLength = 0;
    
  long long int cache[1000001] = {0};  
  
  for (start=1;start<1000000;start++) {
    chainLength = getChainLength(start, cache);
        
    if (chainLength > longestChainLength) {
      longestChainLength = chainLength;
      longestStart = start;
    }
  }

  cout << "Answer: " << longestStart << " with a chain length of " << longestChainLength << "\n";
  return 0;
}
