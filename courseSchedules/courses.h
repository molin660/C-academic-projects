#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h> //adding the math library for the ceil function

/**********************************************************************
Make file:

lastnameFirstnameA1: lastnameFirstnameA1.o lastnameFirstnameA1Main.o
 gcc -Wall -std=c99 lastnameFirstnameA1.o lastnameFirstnameA1Main.c -o lastnameFirstnameA1
lastnameFirstnameA1.o: lastnameFirstnameA1.c givenA1.h
 gcc -Wall -std=c99 -c lastnameFirstnameA1.c
lastnameFirstnameA1Main.o: lastnameFirstnameA1Main.c givenA1.h
 gcc -Wall -std=c99 -c lastnameFirstnameA1Main.c
clean:
rm *.o lastnameFirstnameA1
***********************************************************************************/

#define NUMBER_PROFS 6
#define NUMBER_COURSES 10
#define MAX_STR 50

struct courseStruct {
   char courseName [MAX_STR];
   int courseID;
};

struct profStruct {
   char profName [MAX_STR];
   int  coursesTaught [NUMBER_COURSES];
};

/* Task 1 */
FILE *openFileForReading(char fileName [MAX_STR]);

/* Task 2 */
int readCourse (char filename [MAX_STR],
                struct courseStruct courseInfo [NUMBER_COURSES]
                );

/* Task 3 */
int readProfAndCoursesTaught (char filename [MAX_STR],
                               struct profStruct profInfo [NUMBER_PROFS],
                              struct courseStruct courseInfo [NUMBER_COURSES]
                               );

/* Task 4 */
int nCourses (int n,
              struct profStruct profInfo [NUMBER_PROFS],
              char profsNCourses [NUMBER_PROFS][MAX_STR]
              );

/* Task 5 */
int getCourseName (int courseNum,
                   char cNameFound [50],
                   struct courseStruct courseInfo [NUMBER_COURSES]
                   );

/* Task 6 */
int getCourseNum (char cName [50],
                  int * cNumFound,
                  struct courseStruct courseInfo [NUMBER_COURSES]
                  );

/* Task 7 */
int profsTeachingCourse (int courseNum,
                         struct profStruct profInfo [NUMBER_PROFS],
                         char taughtBy [NUMBER_PROFS][MAX_STR]
                         );


/*Task 8 */
float avgNumCourses (struct profStruct profInfo [NUMBER_PROFS]);
