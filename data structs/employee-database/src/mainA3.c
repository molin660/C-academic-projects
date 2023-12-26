#include "../include/headerA3.h"


int main (int argc, char *argv[]) {
  a3Emp * empArr = NULL;
  loadEmpData (&empArr, "proFile.txt");

  int choice = 0; //for menu selection

  int printWhichOne = 0; //which one do you want to print
  int whichEmpId = 0; //which ID do you want to find
  char whichName[100]; //which name do you want to find
  //int fun4 = 0; //calling function 4
  int fun5 = 0; //calling function 5
  //int numEmployees = 0;
  int firedOne = 0; //which one do you want to fire
  char firedAll[5]; //do you want to fire all, y or n

  do { //do while loop with contion that the choice is

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

    switch (choice) { //switch statement for the menu
      case 1: //adding new employees to LL
        recruitEmployee(&empArr);
        break;
      case 2: //printing all of the employees to LL
        printAll(empArr);
        break;
      case 3: //printing a specific employee to LL
        printf("Enter a position: ");
        scanf("%d", &printWhichOne);
        printOne(empArr, printWhichOne);
        printf("\n");
        break;
      case 4: //printing the info of an employee with a specific employee ID
        printf("Enter an employee ID: ");
        scanf("%d", &whichEmpId);
        lookOnId(empArr, whichEmpId);
        printf("\n");
        break;
      case 5: //printing the info of an inputted name
        while ((getchar()) != '\n');
        printf("Enter the full name of the employee: ");
        fgets(whichName, 2*MAX_LENGTH, stdin);
        printf("\nThe full name you entered is %s \n", whichName);
        fun5 = lookOnFullName(empArr, whichName);

        if (fun5 != -1) { //error validating
            printf("\nThis employee is at position #%d.\n", fun5); // Emp found.
            printOne(empArr, fun5);
        }
        else if (fun5 == -1) {
            printf("There is no employee with this name.\n");
        }
        break;
      case 6: //counts the total number of employees
        printf("\nTotal number of employees = %d \n", countEmployees(empArr));
        break;
      case 7: //sorting the employees by the value of the employee ID
        printf("\nAfter sorting on empId, the employees are as follows: \n\n");
        sortEmployeesId(empArr);
        break;
      case 8: //counting how many employees
        printf("There are currently %d employees \n", countEmployees(empArr));
        if (countEmployees(empArr) != 0) {
          printf("Which employee do you wish to fire – enter a value between 1 and %d: ", countEmployees(empArr));
          scanf("%d", &firedOne);
          fireOne(&empArr, firedOne);
          printAll(empArr);
        }
        else {
          printf("There are no employees to fire lol\n");
        }
        break;
      case 9: //firing every employee by emptying linked list
        printf("Are you sure you want to fire everyone (y/n): ");
        getchar();
        fgets(firedAll, 5, stdin);
        if (strcmp(firedAll, "y\n") == 0 || strcmp(firedAll,"Y\n") == 0) { //error testing
          fireAll(&empArr);
        }
        else {
          printf("no employees were fired\n");
          break;
        }
        printf("\nSuccess\n");
        break;
      case 10: //ending the program
        printf("\nEnd of program, thank you <3.\n");
        return 0;
      default:
        break;
    }
  } while (choice != 10); //condition of do-while-loop
}

  //temp = headA3;
/*
  while (temp->nextEmployee != NULL) { //you will lose the head of the linked list
    printf("FN = %s \n", temp->fname);
    //headA3;
  }
  */
