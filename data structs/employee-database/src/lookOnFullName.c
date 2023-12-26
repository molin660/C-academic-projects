#include "../include/headerA3.h"

int lookOnFullName (struct employee * headLL, char whichName [100]) {
  char firstN[MAX_LENGTH]; //making dummy variables
  char lastN[MAX_LENGTH];
  sscanf(whichName, "%s %s", firstN, lastN); //splitting the user input
  a3Emp * point = headLL;
  int i = 1;

  while (point != NULL) { //if LL is not empty
    //printf("First name: |%s|", firstN);
    //printf("Last name: |%s|", lastN);
    if (strcmp(firstN, point->fname) == 0) { //check if the first and last name are equivalent to the user input
      if (strcmp(lastN, point->lname) == 0) {
        return i;
      }
    }
    i++;
    point = point->nextEmployee; //move onto the next
  }
  printf("\nThere is no employee with this full name %s", whichName);
  return -1;
}
