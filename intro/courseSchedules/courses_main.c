#include "courses.h"
#include <stdlib.h>

int main (int argc, char * argv[]) {

  //Variables in the struct
  struct courseStruct courseInfo [NUMBER_COURSES];
  struct profStruct profInfo [NUMBER_PROFS];

  int whichTask;
  int n;
  char profsNCourses [NUMBER_PROFS][MAX_STR];
  int courseNum;
  int cNumFound;
  char taughtBy[NUMBER_PROFS][MAX_STR];
  char cNameFound [50];
  char cName[50];
  float avg;

  // Task 0 and Task 1 - read data from files - names given from command line
  // FILE * fptr = openFileForReading (argv[1]);

//running the 2nd and 3rd tasks gm
  int task2 = readCourse (argv[1], courseInfo); //opens the file, read the given fuke and populates courseInfo
  if (task2 == 1) {
    printf("\n\nArray of Structs courseInfo populates successfully\n\n");
  }
  else {
    printf("\nArray courseInfo could not be created\n");
  }
  int task3 = readProfAndCoursesTaught (argv[2], profInfo, courseInfo);
  if (task3 != 1) {
    printf("\nArray profInfo could not be created\n");
  }
  
//do while loop for if the input it between 4 and 8
  //while (1) {
  do {
    printf("\n4.: Task 4");
    printf("\n5.: Task 5");
    printf("\n6.: Task 6");
    printf("\n7.: Task 7");
    printf("\n8.: Task 8");
    printf("\n9 to Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &whichTask);
    getchar();

    switch (whichTask) { // switch statement to run each value for the specific input
      case 4:
      { //main menu inputs and function calls to test my functions
        printf("\nEnter n: ");
        scanf("%d", &n);
        int numProfs = nCourses (n, profInfo, profsNCourses);
        printf("\n%d professors teach more than %d courses\n", numProfs, n);
        break;
      }
      case 5:
      {
        printf("Which course # do you want to find the name of: ");
        scanf(" %d", &courseNum);
        int courseNames = getCourseName(courseNum, cNameFound, courseInfo);
        printf("%d\t%s", courseNames,cNameFound);
        break;
      }
      case 6:
      {
        printf("What course do you want to find the # of: ");
        fgets(cName, MAX_STR, stdin);
        cName[strlen(cName)-1] = '\0';
        printf("%s|", cName);
        int courseNum = getCourseNum(cName, &cNumFound, courseInfo);
        printf("%d\t%d", courseNum, cNumFound);
        break;
      }
      case 7:
      {
        printf("Which course do you want to find profs teaching: ");
        scanf("%d", &courseNum);
        int cTeach = profsTeachingCourse (courseNum, profInfo, taughtBy);
        printf("%d", cTeach);
        break;
      }
      case 8:
      {
        avg = avgNumCourses(profInfo);
        printf("\nthe average is %.1f", avg);
        break;
      }

      case 9:
      {
        printf("Exit complete\n\n");
        return 0;
      }

      default: //if anything aside from numbers between 4-8 are inputted, it breaks
      {
        printf("That is an invalid choice \n");
        break;
      }
    }
  }
  while (whichTask >=4 && whichTask<=8);
  return 0;
}
//THE END!
