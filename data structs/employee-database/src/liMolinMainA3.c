#include "../include/headerA3.h"

//i pushed this one initially for the bonus 2% but then my actual mainA3.c is used in the program, this file is not in my makefile
int main (int argc, char *argv[]) {

  //struct employee * headA3;
//temp head for testing
  //struct employee * temp;
/*
  int choice = 0;       // Menu selection choice
  a3Emp *empArr = NULL; // new employee
  a3Emp *temp = empArr;
  int pos = 0;      // F3 - position of list chosen
  int SearchID = 0; // F4 - search ID
  char *FullName = malloc(sizeof(char) * (2 * MAX_LENGTH));
  int totalF6 = 0; // total F6
  int resultF5 = 0;
  int firePos = 0; // F8
  char fire = 'n'; // F9 - fire choice
  int count = 0;   // counting
*/
  int whichOne = 0;
  int whichEmpId = 0;
  printf("Hello World!\n");

  loadEmpData (&headA3, argv[1]);

  do {
    // Menu selection
    printf("\n");
    printf("1. Add a new employee.\n");
    printf("2. Print data of all employees.\n");
    printf("3. Print data of the nth employee\n");
    printf("4. Search for employee based on empId\n");
    printf("5. Search for employee based on full name\n");
    printf("6. Count the total number of employees\n");
    printf("7. Sort the employees based on their empId\n");
    printf("8. Remove the nth employee in the current LL\n");
    printf("9. Remove all employees in the current LL\n");
    printf("10. Exit\n");

    printf("\n");
    printf("Choose a menu option: "); //user selects choice
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        recruitEmployee(&empArr);
        break;
      case 2:
        printAll(empArr);
        break;
      case 3:
        printf("Enter a position: ");
        scanf("%d", whichOne);
        printOne(empArr, whichOne);
        printf("\n");
        break;
      case 4:
        printf("Enter an employee ID: ");
        scanf("%d", whichEmpId);
        lookOnId(empArr, whichEmpId);
        printf("\n");
        break;
      case 5:


  //temp = headA3;

  while (headA3->nextEmployee != NULL) { //you will lose the head of the linked list
    printf("FN = %s \n", headA3->fname);
    headA3
  }
}
