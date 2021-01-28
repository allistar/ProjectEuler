#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <map>

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
std::map<string,cpp_int> cache;
bool useCache = true;
bool recursive = false;
bool iterative = false;
bool iterative2 = !recursive;

int StackMaxSize = 100000;
int StackMaxDepth = 0;	
int CacheLookups = 0;
int CacheHits = 0;
int CacheSets = 0;

cpp_int combinationsRecursive(int coins[], int index, int capacity) {	
	cpp_int withoutItem, withItem;
	if (capacity == 0) {
		return 1;
	}
	if (capacity < 0 || index <= 0) {
		return 0;
	}

	char ix[20];
	if (useCache) {
		sprintf(ix, "%i,%i", index, capacity);
		cpp_int value = cache[ix];
		CacheLookups++;
		if (value > 0) {
			CacheHits++;
			return value;
		}
	}
	
	withoutItem = combinationsRecursive(coins, index - 1, capacity);
	withItem = combinationsRecursive(coins, index, capacity - coins[index - 1]);
	if (useCache) {
		cache[ix] = withoutItem + withItem;
		CacheSets++;
	}
	return withoutItem + withItem;
}

cpp_int combinationsIterative(int coins[], int index, int capacity) {
	cache.clear();
	//define a stack
	int indexes[StackMaxSize];
	int capacities[StackMaxSize];
	int stackPos = 0;
	
	indexes[stackPos] = index;
	capacities[stackPos] = capacity;
	int stackIndex, stackCapacity;
	cpp_int answer = 0;
	char ix[20];
	
	//walk the stack until it's empty
	while (stackPos >= 0) {		
		//pop the top item off the stack
		stackIndex = indexes[stackPos];
		stackCapacity = capacities[stackPos];
		stackPos--;
		
		if (useCache) {
			sprintf(ix, "%i,%i", stackIndex, stackCapacity);
		}
		//accumulate the answer
		if (stackCapacity == 0) {
			answer++;
			if (useCache) {
				cache[ix] += answer;
				CacheSets++;
//				cout << "Cache set: " << ix << " = " << answer << std::endl;
			}
			continue;
		}
		if (stackCapacity < 0 || stackIndex <= 0) {
			if (useCache) {
				cache[ix] += answer;
				CacheSets++;
//				cout << "Cache set: " << ix << " = " << answer << std::endl;
			}
			continue;
		}
		
		if (useCache) {
			cpp_int cacheValue = cache[ix];
			CacheLookups++;
			if (cacheValue > 0) {
				answer += cacheValue;
				CacheHits++;
				continue;
			}
		}
		
		//push the "without item" call to the stack
		stackPos++;
		indexes[stackPos] = stackIndex - 1;
		capacities[stackPos] = stackCapacity;
		//push the "with item" call to the stack
		stackPos++;
		indexes[stackPos] = stackIndex;
		capacities[stackPos] = stackCapacity - coins[stackIndex - 1];
				
		if (stackPos > StackMaxDepth)
			StackMaxDepth = stackPos;
	}
	
//	printf("Max depth: %i\n", maxDepth);
	return answer;
}

cpp_int combinationsIterative2(int coins[], int index, int capacity) {
	cpp_int *table = new cpp_int[capacity+1];
	for(int i=0; i<capacity; i++)
		table[i] = 0;
	
	table[0] = 1;
	
    for(int i=0; i<index; i++) 
        for(int j=coins[i]; j<=capacity; j++) {
            table[j] += table[j-coins[i]]; 
		}

	cpp_int answer = table[capacity];
	delete[] table;
	return answer;
}

int main() {
	int coins[] = {1,5,10,25,50,100};
	int coinCount = 6;
	int sumStart = 10;
	int sumMax = 100000000;
	
	for(int sum=sumStart; sum<= sumMax; sum*=10) {
		if (recursive) {
			cout << sum << ": " << combinationsRecursive(coins, coinCount, sum) << std::endl;
		}
		if (iterative2) {
			cout << sum << ": " << combinationsIterative2(coins, coinCount, sum) << std::endl;
		}
	}
  return 0;
}
