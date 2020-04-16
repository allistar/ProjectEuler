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

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)

 * 
 */

void importData(int data[16][16], int *rows) {
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

void printData(int data[16][16], int rows) {
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
  int data[16][16];
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
