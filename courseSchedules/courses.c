#include "courses.h"

//task 1 - opens the file
FILE *openFileForReading(char fileName [MAX_STR]){
  FILE * fptr = fopen(fileName, "r"); //reading the file
  if (fileName == NULL){ // if the file is not found, it returns NULL
      printf("Sorry the file could not be found\n");
      return NULL;
  }
  else {
    return fptr;
  }
  //fclose(fileName);
}

//task 2 - retrieves text file data
int readCourse (char filename [MAX_STR], struct courseStruct courseInfo [NUMBER_COURSES]) {
  FILE * fptr = openFileForReading(filename);
  int numLines = 0; //counter
  int maxLines = 2*NUMBER_COURSES;
  char tempCourse[MAX_STR]; //tempvar
  if (fptr == NULL) {
    return -1;
  }

//runs for each line in the text file
  while (!feof(fptr)) {
    for (int i = 0; i < NUMBER_COURSES; i++) {
      fgets(tempCourse, MAX_STR, fptr);
      //int length[strlen(courseInfo[i].courseName[i])];
      tempCourse[strlen(tempCourse)-1] = '\0'; //replaces the last character with null to get rid of the newline
      strcpy(courseInfo[i].courseName, tempCourse);
      numLines++;
    }
    for (int j = 0; j < NUMBER_COURSES; j++) {
      fscanf(fptr, "\n%d ", &courseInfo[j].courseID);
      numLines++;
    }
  }
/*
  for (int n = 0; n < 10; n++){
    printf("\nCourse name: %s", courseInfo[n].courseName);
    printf("\tCourse ID: %d", courseInfo[n].courseID);
  }
*/
  fclose(fptr); //if there are more or less than 2 times the amount
  if (numLines > maxLines || numLines < maxLines) {
    return -1;
  }
  else {
    return 1;
  }
}

//task 3 - populates arrays for other tasks
int readProfAndCoursesTaught (char filename [MAX_STR], struct profStruct profInfo [NUMBER_PROFS], struct courseStruct courseInfo [NUMBER_COURSES]) {
  FILE * fptr = openFileForReading(filename);
  char doesTeach[MAX_STR];
  char tempProf[MAX_STR];

  if (fptr == NULL) {
    return -1;
  }
//similar process, looping through to get the names of the courses with fgets
  while (!feof(fptr)) {
    for (int i = 0; i < NUMBER_PROFS; i++) {
      //fscanf(fptr, "%s ", profInfo[i].profName);
      fgets(tempProf, MAX_STR, fptr);
      tempProf[strlen(tempProf)-1] = '\0';
      strcpy(profInfo[i].profName, tempProf);
      //printf("\n%s\n", profInfo[i].profName);
    }

//scanning the file for the arrays of whether or not a prof teaches a course
    for (int j = 0; j < NUMBER_PROFS; j++) {
      fscanf(fptr, "%s ", doesTeach);
      int pos = 0;
      for (int k = 0; k < NUMBER_COURSES; k++) {
        if (doesTeach[k] == 'y' || doesTeach[k] == 'Y') {
          profInfo[j].coursesTaught[k] = courseInfo[k].courseID;
          //printf("%d\n", profInfo[j].coursesTaught[k]);
          pos++;

        }
        else {
          profInfo[j].coursesTaught[k] = -1; //makes it -1 if the prof does not teach the course
        }
        //strcpy(profInfo[j].coursesTaught[k], doesTeach);
      }
      //printf("\n%ls\n", profInfo[j].coursesTaught);
    }
  }
  fclose(fptr);
  return 1;
}

/*
void printprof(struct profStruct profInfo [NUMBER_PROFS])
{
  for (int a = 0; a < NUMBER_PROFS; a++)
  {
    printf("%s ", profInfo[a].profName);
    for (int b = 0; b < NUMBER_COURSES; b++)
    {
      printf("%ls ", profInfo[b].coursesTaught);
    }
    printf("\n");
  }
}
*/

//task 4 - see's how many profs teachmore than a certain amount
int nCourses (int n, struct profStruct profInfo [NUMBER_PROFS], char profsNCourses [NUMBER_PROFS][MAX_STR]) {
  //printprof(profInfo);
  int countProfs = 0;

  //nested loops for the array of whether a prof teaches a course or not
  for (int i = 0; i < NUMBER_PROFS; i++) {
    int countTeach = 0;
    for (int j = 0; j < NUMBER_COURSES; j++) {
      if (profInfo[i].coursesTaught[j] != -1) {
        countTeach++;
        //printf("%d\n", countTeach);
      }
    }
//if the counter of how many 'yes's' there are in the array is larger than the user inputted n value to check
    if (countTeach >= n) {
      //then it will copy the name of the prof into the array of the profsNCourses
      strcpy(profsNCourses[countProfs], profInfo[i].profName);
                         // this should be the counter and not i^
      // what is supposed to happen: Ritu Gary Mom dad "" ""
      // what I did that was wrong: Ritu "" Gary "" Mom dad

      //printf("%s teaches more  or equal than %d classes\n", profInfo[i].profName, n);
      countProfs++;
      //printf("%i\n", countProfs);
    }
    else { //populates the array with an empty string otherwise
      strcpy(profsNCourses[i], "");
    }
  }
  return countProfs;
}


//task 5 - gets the name of a course when given the code
int getCourseName (int courseNum, char cNameFound [50], struct courseStruct courseInfo [NUMBER_COURSES]) {
  int pos = 0;
  for (int i = 0; i < NUMBER_COURSES; i++) { //loops through the array and compares it to the user input to equate the same index from the struct of the names
    if (courseNum == courseInfo[i].courseID) {
      //printf("%d", courseNum);
      strcpy(cNameFound, courseInfo[i].courseName);
      //printf("%s", cNameFound);
      pos = 1;

    }
  }
  return pos;
}

//task 6 - gets the code when given the name
int getCourseNum (char cName [50], int * cNumFound, struct courseStruct courseInfo [NUMBER_COURSES]) {
  //int pos = 0;
  for (int i = 0; i < NUMBER_COURSES; i++) { //loops through to compare positions of the course name and code ID's
    if (strcmp(cName, courseInfo[i].courseName) == 0) { //compares strings
      *cNumFound = courseInfo[i].courseID;
      //printf("%d", *cNumFound);
      return 1;
    }
  }
  return 0;
}

//task 7 - checks which profs are teaching what
int profsTeachingCourse (int courseNum, struct profStruct profInfo [NUMBER_PROFS], char taughtBy [NUMBER_PROFS][MAX_STR]) {
  int profsTeaching = 0;
//populates array taughtBy with the courses taught to verify who teaches what
  for (int i = 0; i < NUMBER_PROFS; i++) {
    for (int j = 0; j < NUMBER_COURSES; j++) {
      if (courseNum == profInfo[i].coursesTaught[j]) {
        strcpy(taughtBy[profsTeaching], profInfo[i].profName);
                  // this ^ used to be i but it has to be profsTeaching
        profsTeaching++;
        //printf("\n%s\n", profInfo[i].profName);
      }
      else {
        strcpy(taughtBy[i], ""); //populates array with nothing otherwise
        //return 0;
      }
      //printf("%s", taughtBy[i]);
    }
  }
  return profsTeaching;
}


//Task 8 - finds the average amount of courses taught by all the profs
float avgNumCourses (struct profStruct profInfo [NUMBER_PROFS]) {
  float totCourses = 0;
  float average = 0;
//if the original coursesTaught array is not an empty value, then the counter iterates for all the courses taught
  for (int i = 0; i < NUMBER_PROFS; i++) {
    for (int j = 0; j < NUMBER_COURSES; j++) {
      if (profInfo[i].coursesTaught[j] != -1) {
        //printf("\n%d\n", profInfo[i].coursesTaught[j]);
        totCourses++;
      }
    }
  }
  average = totCourses/(float)NUMBER_PROFS; //calculates average
  average = ceil(average); //rounds up with ceiling function
  //printf("the average is %f\n", average);
  return average;
}
