#include <stdio.h>
#include <string.h>
#include "medals.h"

//write code to display all country names read from file and the total number of medals won by each country
void readFromFile (char fileWithMedals [30], int country [COUNTRIES][MEDALCAT], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){
    FILE * theFile;
    theFile = fopen(fileWithMedals, "r"); //opens the file
    if(theFile == NULL){
        printf("Sorry the file could not be found\n");
        return;
    }
    else {
        for (int i = 0; i < COUNTRIES; i++) { //scans each string and integer from the file
            fscanf(theFile, "%s %d %d %d", countryNames[i], &country[i][0], &country[i][1], &country[i][2]);
        }
    }

    fclose(theFile);
}

// write code to call Function 2 - Find total number of medals won by each country
void findTotalPerCountry (int country [COUNTRIES] [MEDALCAT], int totalAllCountries [COUNTRIES]) {
  for (int i = 0; i < COUNTRIES; i++) { //iterates for each medal position in the array for the 15 countries
    totalAllCountries[i] = (country[i][0] + country[i][1] + country[i][2]);
  }
}

//Finds total number of medals in each category (Gold/Silver/Bronze) and stores them in array totalAllMedals, it will output the maximum value
int findTotalPerMedal (int country [COUNTRIES][MEDALCAT], int totalAllMedals [MEDALCAT], int * whichMedal) {
    for (int i = 0; i < MEDALCAT; i++) { //the total amount of gold, silver, and bronze medals will be appended to the total of the array
      totalAllMedals[i] = 0;
      for (int j = 0; j < COUNTRIES; j++) { //iterates the total value for the 15 countries
        totalAllMedals[i] += country[j][i];
      }
    }
    * whichMedal = 0;
    for (int k = 0; k < MEDALCAT; k++) { // finding which medal is the highest one and returning the pointer value in main
      if (totalAllMedals[k] > totalAllMedals[*whichMedal]) {
        * whichMedal = k;
      }
    }
    return * whichMedal;
}

//Displays a horizontal histogram of stars, where each star represents 2 medals (any remaining medal will also count as 1 star).
void hHistogram (char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]) {
    int starsOfCountry[COUNTRIES];
    for (int i = 0; i < COUNTRIES; i++) { //loops for each line of the countries
        printf("\n%s: ", countryNames[i]); //country name
        starsOfCountry[i] = totalMedals[i];
        if (totalMedals[i] % 2 == 0) { //if there is an even amount, it divides by 2
            starsOfCountry[i] = (totalMedals[i] / 2);
        }
        else if (totalMedals[i] % 2 == 1){ //if there is an odd number, add an extra star
            starsOfCountry[i] = (totalMedals[i] / 2) + 1;
        }
        for (int g = 0; g < starsOfCountry[i]; g++) { //printing the line of stars
            printf("*");
        }
        printf("(%d)",totalMedals[i]); //printing the amount of medals won
    }
}

//Returns the total number of medals won by a country
int searchCountry (char countryName [MAX_LENGTH_CNAME], char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalAllCountries [COUNTRIES]) {
    for(int i = 0; i < COUNTRIES; i++){
        int isCountry = strcmp(countryName, countryNames[i]); //if the case-sensitive argument from main is the same as one in the index of arrays for countries
        if (isCountry == 0) {
            return i; //returns the value of the index
        }
    }
    return -1;
}

//Displays the top three country names and the total medals won by each of them – the display must be in order of total medals won.
void rankTopThreeByTotal (int totalAllCountries [COUNTRIES], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]) {
    int first = -1, second = -1, third = -1; //makes sure they will get replaced
    char firstC[MAX_LENGTH_CNAME], secondC[MAX_LENGTH_CNAME], thirdC[MAX_LENGTH_CNAME]; //the names of the countries
    printf("\nTop 3 based on all medals");
    for (int i = 0; i < COUNTRIES; i++) {
        if (totalAllCountries[i] > first) { //assigns the highest to first then checks again for each vale of totalAllCountries
            third = second;
            second = first;
            first = totalAllCountries[i];
            strcpy(firstC, countryNames[i]);
        }
        else if (totalAllCountries[i] > second) { //same concept as first
            third = second;
            second = totalAllCountries[i];
            strcpy(secondC, countryNames[i]);
        }
        else if (totalAllCountries[i] > third) { //same concept as first and second
            third = totalAllCountries[i];
            strcpy(thirdC, countryNames[i]);
        }
    }
    printf("\n%s (%d)", firstC, first); //printing it out
    printf("\n%s (%d)", secondC, second);
    printf("\n%s (%d)", thirdC, third);
}

//Displays the top three country names and the total gold medals won by each of them – the display must be in order of total gold medals won.
void rankTopThreeByMedal (int country[COUNTRIES][MEDALCAT], char countryNames[COUNTRIES][MAX_LENGTH_CNAME]) { //this code is similar to the previous function 7
    int first = -1, second = -1, third = -1;
    char firstC[MAX_LENGTH_CNAME], secondC[MAX_LENGTH_CNAME], thirdC[MAX_LENGTH_CNAME];
    printf("\nTop 3 based on Gold medals");
    for (int i = 0; i < COUNTRIES; i++) { // same as 7 but instead of totall all countries array, it uses the country array because it is only looking for gold at index 0 in the 2D array
        if (country[i][0] > first) {
            third = second;
            second = first;
            first = country[i][0];
            strcpy(firstC, countryNames[i]);
        }
        else if (country[i][0] > second) {
            third = second;
            second = country[i][0];
            strcpy(secondC, countryNames[i]);
        }
        else if (country[i][0] > third) {
            third = country[i][0];
            strcpy(thirdC, countryNames[i]);
        }
    }
    printf("\n%s (%d)", firstC, first); //same printing
    printf("\n%s (%d)", secondC, second);
    printf("\n%s (%d)", thirdC, third);
}

//Returns the total number of countries with no type of a medal = indexMedal (1 for Gold, 2 for Silver, 3 for Bronze)
int findAllWithNoXMedals (int country [COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries [COUNTRIES]) {
    int count = 0; //counts how many countries have no medals at each index
    for (int i = 0; i < COUNTRIES; i++) {
        indexOfCountries[i] = -1; //initialized as something to be replaced
        if (country [i][indexMedal] == 0) { //if they find it is empty
            indexOfCountries[count] = i; //i represents the countries index when looped, count represents how many have nothing
            count++;
        }
    }
    return count; //returns how many countries have no medals at the category chosen by the user
}

//Returns the total number of countries that have ONLY won medals of a specific category with the same indexMedal as case 8:
int findAllWithOnlyXMedals (int country [COUNTRIES][MEDALCAT], int indexMedal, int indexOfCountries [COUNTRIES]) {
    int count = 0; //similar to function 8, we count how many countries only have that specific medal type
    for(int i = 0; i < COUNTRIES; i++){
      indexOfCountries[i] = -1;
      //this if statement is checking if the value at that country will have 0 medals at 0, 1, or 2 places which represent medal types. since indexMedal is an input, it must get the complememts of 0, 1, and 2
        if(country[i][indexMedal] != 0 && country[i][(indexMedal+1)%MEDALCAT] == 0 && country[i][(indexMedal+2)%MEDALCAT] == 0){
            indexOfCountries[count] = i;
            count++;
        }
    }
    return count; //returns how many countries only have medals in certain categories
}

//Returns the index of the countryName that has min or max length and then selects which country that is
int findCountryIndexWithMinOrMaxLength (int minOrMax, char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){
    int indexMinOrMax = 0; //the index of any country with the min or max length name
    for(int i = 0; i < COUNTRIES; i++){ //loop to checlk for each country
        if(minOrMax == 2 && (strlen(countryNames[i]) > strlen(countryNames[indexMinOrMax]))) { //the string length is compared to the previous ones to check which is lowest or highest
            indexMinOrMax = i;
        }
        else if (minOrMax == 1 && (strlen(countryNames[i]) < strlen(countryNames[indexMinOrMax]))) { //this does the exact same thing except for max instead of min
            indexMinOrMax = i;
        }
    }
    return indexMinOrMax; //returns the index for which is lowest or highest length name
}
