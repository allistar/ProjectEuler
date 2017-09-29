#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 

In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?

 * 
 */

int combinations(int coins[], int index, int capacity) {
  int withoutItem, withItem;
  
  if (capacity == 0)
    return 1;
  if (capacity < 0 || index <= 0)
    return 0;
  
  withoutItem = combinations(coins, index - 1, capacity);
  withItem = combinations(coins, index, capacity - coins[index - 1]);
  return withoutItem + withItem;
}

int main() {
  int coins[] = {1,2,5,10,20,50,100,200};
  int coinCount = 8;
  
  printf("Answer: %i\n", combinations(coins, coinCount, 200));
  

  return 0;
}
