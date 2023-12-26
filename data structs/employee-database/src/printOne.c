#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne) { //need to fix the error statement
  int count = 0;
  a3Emp * point = headLL; //creating pointer of datatype from structure
  int tempCount = 0; //creating a counter to check if there is even an exployee at that index
  a3Emp * tempPoint = headLL;

  while (tempPoint != NULL) { //counting
    tempCount++;
    tempPoint = tempPoint->nextEmployee;
  }
  //printf("\ntemp count is %d, \n", tempCount);

  if (whichOne <= 0 || whichOne > tempCount) { //error validating
    printf("There is no employee at that index.\n");
  }

  while (point != NULL) { //printing the table of values
    if (count == (whichOne-1)) { //if the index value is equal to the user inputted argument
      printf("Employee position %d: \n", whichOne);
      printf("\tEmployee Id: %d\n", point->empId);
      printf("\tFirst name: %s\n", point->fname);
      printf("\tLast name: %s \n", point->lname);
      printf("\tEmployee's %d Dependents: ", point->numDependents);
      for (int i = 0; i < point->numDependents; i++) { //looping the number of dependents
        printf("%s ", point->dependents[i]);
      }
    }
    count++;
    point = point->nextEmployee; //moving to the next employee
    printf("\n");
  }
}
