#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne){
  a3Emp *temp = *headLL; //initialize temp LL and pointer
  a3Emp *point = NULL;
  int count = 1;

  if(*headLL == NULL){ //empty LL
    printf("This list is empty.\n");
  }

  while (temp != NULL && count < whichOne) { // iterate to find specif node to remove
    point = temp;
    temp = temp->nextEmployee;
    count++;
  }

  if (temp != NULL) {  //removes the node
    if (point == NULL) {
      *headLL = temp->nextEmployee;
    }
    else {
      point->nextEmployee = temp->nextEmployee;
    }

    for(int i = 0; i < temp->numDependents; i++){ //freeing memory
      free(temp->dependents[i]);
    }
    free(temp->dependents);
    free(temp);
  }
}
