#include "../include/headerA3.h"
void sortEmployeesId (struct employee * headLL){
  a3Emp * newTemp = headLL;
  a3Emp * temp = headLL;
  int count = 0; //initializing variables

  if(headLL == NULL){  //error validating
    printf("This list is empty.\n");
  }

  while(temp != NULL){ //counting how many variables for later for loop
    count++;
    temp = temp->nextEmployee;
  }

  a3Emp * empArr[count]; //making array of length for how many employees
  temp = headLL;

  int i = 0; //sorting the values of the ID
  while(temp != NULL){
    empArr[i++] = temp;
    temp = temp->nextEmployee;
  }

  for(int i = 0; i < count; i++){ //counting to see which ID's are greater or less than all previous ones
    for(int j = 0; j < count-i-1; j++){
      if(empArr[j]->empId > empArr[j+1]->empId){
        newTemp = empArr[j];
        empArr[j] = empArr[j+1];
        empArr[j+1] = newTemp;
      }
    }
  }

  for(int i = 0; i < count; i++){ //printing the values
    printf("\nEmployee #%d: \n", i + 1 );
    printf("\tEmployee Id: %d\n", empArr[i]->empId);
    printf("\tFirst name: %s\n", empArr[i]->fname);
    printf("\tLast name: %s\n", empArr[i]->lname);
    printf("\tDependents: ");
    for (int j = 0; j < empArr[i]->numDependents; j++) {
        printf("%s, ", empArr[i]->dependents[j]);
    }
    //printf("%s", empArr[i]->dependents[empArr[i]->numDependents-1]);
  }
}
