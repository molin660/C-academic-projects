#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId) {
  int count = 0;
  a3Emp * point = headLL; //creating pointer of datatype from structure

  while (point != NULL) { //printing the values
    if (whichEmpId == point->empId) { //if the value of the user inputted parameter is equal to the index in loop
      printf("Employee Id from user %d: \n", whichEmpId);
      printf("\tEmployee Id: %d\n", point->empId);
      printf("\tFirst name: %s\n", point->fname);
      printf("\tLast name: %s \n", point->lname);
      printf("\tEmployee's %d Dependents: ", point->numDependents);
      for (int i = 0; i < point->numDependents; i++) {
        printf("%s ", point->dependents[i]);
      }
    }
    count++;
    point = point->nextEmployee; //go to next
    printf("\n");
  }

  if (headLL == NULL) { //if there is nothing
    printf("There is no employee at that index.\n");
    return -1;
  }
  return count;
}
