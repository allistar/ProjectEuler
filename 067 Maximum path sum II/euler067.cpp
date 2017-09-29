#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using boost::multiprecision::cpp_int;
using namespace std;

/**
 * 


By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)

 * 
 */

void importData(int data[128][128], int *rows) {
  FILE *file = fopen("data.txt", "r");
  char *line = (char*)malloc(512);
  int row = 0, column, number, digit;
  char *pos;
  
  while (fgets(line, 512, file)) {
     //read data for this row
     pos = line;
     number = 0;
     column = 0;
     digit = 1;
     while (true) {
	if (*pos == '\n') {
	  break;
	} else if (*pos == ' ') {
	  number = 0;
	  pos++;
	  digit = 1;
	  continue;
	}
	//hard coded to find two digit numbers only
	if (digit == 1) {
	  number = 10 * (*pos - '0');
	} else {
	  number = number + (*pos - '0');
	  data[row][column] = number;
	  column++;
	}
	digit++;
	pos++;
     }
     row++;
  }
  *rows = row;
  fclose(file);
}

void printData(int data[128][128], int rows) {
  int row, column;
  
  //prints the data upside down
  for(row=rows-1;row>=0;row--) {
   for(column=0;column<=row;column++) {
     printf("%i ", data[row][column]);
   }
    printf("\n");
  }
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
  int data[128][128];
  int rows = 0,
    row, column;
  
  importData(data, &rows);
  
  //starting at the 2nd to last rows
  for (row=rows-2;row>=0;row--) {
    //starting from the end position
    for (column = row; column>=0; column--) {
      data[row][column] += max(data[row+1][column], data[row+1][column+1]);
    }
  }

  printData(data, rows);
  return 0;
}
