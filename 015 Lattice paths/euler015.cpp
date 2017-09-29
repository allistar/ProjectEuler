#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 
 * 

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?

 */

int main() {
  const int rows = 20;
  const int columns = 20;
  
  long paths[rows+1][columns+1];
  int row, column;
  
  //Strategy: the path to an edge is the number of paths to the edge above plus the number of paths to the edge to the left.
  for (row=0;row<=rows;row++) {
    for (column=0;column<=columns;column++) {
      if ((row == 0) || (column == 0)) {
	paths[row][column] = 1;
      } else {
	paths[row][column] = paths[row-1][column] + paths[row][column - 1];
      }
    }
  }
  
  printf("Answer: %li\n", paths[rows][columns]);

  return 0;
}
