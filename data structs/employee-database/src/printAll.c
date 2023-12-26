#include "../include/headerA3.h"

void printAll (struct employee *headLL) {
  int index = 0;
  int sum = 0;
  a3Emp * point = headLL; //creating pointer of datatype from structure

  while (point != NULL) { //printing the information from LL if LL isn't empty
    printf("Employee #%d: \n", (index+1));
    printf("\tEmployee Id: %d\n", point->empId);
    printf("\tFirst name: %s\n", point->fname);
    printf("\tLast name: %s\n", point->lname);
    printf("\tEmployee's %d Dependents: ", point->numDependents);
    for (int i = 0; i < point->numDependents; i++) { //for loop for different amounts of dependents
        printf("%s, ", point->dependents[i]);
    }

    //moving to the next employee and incrementing counters
    printf("\n");
    index++;
    sum++;
    point = point->nextEmployee;
  }

  if (headLL == NULL) { //printing how many employees there are
    printf("There are no employees.\n");
  }
  printf("There is/are %d employee(s) in total. \n", sum);
}
