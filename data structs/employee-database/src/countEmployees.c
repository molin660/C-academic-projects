#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL) {
  int count = 0;
  a3Emp * point = headLL; //initializing variables

  while (point != NULL) { //while loop to count the number of employees in the LL
    count++;
    point = point->nextEmployee;
  }
  return count;
}

