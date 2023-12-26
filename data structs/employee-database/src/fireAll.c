#include "../include/headerA3.h"

void fireAll (a3Emp ** headLL) {
  a3Emp * point = *headLL; //initializing variables
  a3Emp * temp = *headLL;

  if (*headLL == NULL) { //empty LL
    printf("this list is empty\n");
  }

  while (temp != NULL) { //freeing all nodes to fire all employees lol
    for (int i = 0; i < temp->numDependents; i++) {
      free(temp->dependents[i]);
    }
    free(temp->dependents);
    point = temp->nextEmployee;
    free(temp);
    temp = point;
  }
  printf("\nAll fired. Linked list is now empty.");
  *headLL = NULL; //setting LL to nothing 
}
