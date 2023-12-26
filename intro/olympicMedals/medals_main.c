/**********************************************************************
Compiling the program:
The program should be compiled using the following flags -std=c99 -Wall

compiling:
gcc -std=c99 -Wall medals_main.c

running:./a.out
**********************************************************************/
#include <stdio.h>
#include <string.h>
#include "medals.h"

int main (int argc, char * argv[]) {//declare all variables here
    // given variables from function prototypes
    int country [COUNTRIES][MEDALCAT];
    char countryNames [COUNTRIES][MAX_LENGTH_CNAME];
    char countryName[MAX_LENGTH_CNAME];
    //char fileWithMedals[30];
    int choice;
    int totalAllCountries[COUNTRIES];
    int totalAllMedals[MEDALCAT];
    int whichMedal;
    int indexOfCountries[COUNTRIES];
    //int indexMedal;

//personal user defined variables
    int medalIndex; //case 3 variable
    int chooseMedal; //for choosing which medal type, gold, silver, or bronze
    int chooseMedal2;
    int minOrMax = 0; //user input for choosing min or max
    char metalTypes[3][10] = {"Gold", "Silver", "Bronze"}; //strings for the medal types
    // call function readFromFile to populate your arrays
    readFromFile (argv[1], country, countryNames); //argv[0] is ./a.out

    do { //provided block of text prompting the user to select a function from the menu
        printf ("\n\nHere is the menu\n");
        printf ("1. Display all country names read from file and the total number of medals won by each\n");
        printf ("2.    Function 2 - Find total number of medals won by each country\n");
        printf ("3.    Function 3 - Finds total number of medals in each category (Gold, Silver, Bronze)\n");
        printf ("4.    Function 4 – Display horizontal histogram\n");
        printf ("5.    Function 5 – Search for a country and return the total number of medals won by it\n");
        printf ("6.    Function 6 – Rank and display top three countries in order of total medals won\n");
        printf ("7.    Function 7 – Rank and display top three countries in order of total gold medals won\n");
        printf ("8.    Function 8 – Find and display all countries that won no X medals, given X as either Gold, Silver or Bronze\n");
        printf ("9.    Function 9 – Find and display all countries that won ONLY X medals, given X as either Gold, Silver or Bronze\n");
        printf ("10.   Function 10 – Find and display name of the country that has minimum or maximum length among all countries read in option 1\n");
        printf ("11.   Exit\n");

        printf ("Enter your choice: "); //user input from keyboard
        scanf ("%d", &choice);

//switch statement
        switch (choice) {
            case 1: // write code to display all country names read from file and the total number of medals won by each country
                //readFromFile(fileWithMedals,)
                for (int i = 0; i < COUNTRIES; i++) {
                    printf("\n%s, %d, %d, %d", countryNames[i], country[i][0], country[i][1], country[i][2]); //printing each value
                }
                break;

            case 2: // write code to call Function 2 - Find total number of medals won by each country
                findTotalPerCountry(country, totalAllCountries);
                for (int i = 0; i < COUNTRIES; i++){
                  printf("\ntotal of %s is %d", countryNames[i], totalAllCountries[i]); //printing total
                }
                break;

            case 3: //Finds total number of medals in each category (Gold/Silver/Bronze) and stores them in array totalAllMedals, it will output the maximum value
                medalIndex = findTotalPerMedal(country, totalAllMedals, &whichMedal);
                for (int j = 0; j < MEDALCAT; j++) {
                  printf("\nTotal of all %s medals = %d", metalTypes[j], totalAllMedals[j]); //total of all medals for a certain type
                }
                printf("\n%s has the maximum value (%d)\n", metalTypes[medalIndex], totalAllMedals[medalIndex]); //printing max value
                break;

            case 4: //Displays a horizontal histogram of stars, where each star represents 2 medals (any remaining medal will also count as 1 star).
                findTotalPerCountry(country, totalAllCountries); //populating the arrays
                hHistogram(countryNames, totalAllCountries);
                break;

            case 5: //Returns the total number of medals won by a country
                printf("Please input a country's name (no spaces and case sensitive): ");
                scanf("%s", countryName);
                findTotalPerCountry(country, totalAllCountries); //user input to send as argument in parameters of function definition
                int countryIndex = searchCountry(countryName, countryNames, totalAllCountries);
                if (countryIndex != -1) { //if it was valid in the function, it prints how many that country won
                    printf("\nTotal number of medals won by %s is %d\n", countryName, totalAllCountries[countryIndex]);
                }
                else {
                    printf("Invalid country name entered. Please try again\n");
                }
                break;

            case 6: //Displays the top three country names and the total medals won by each of them – the display must be in order of total medals won.
                findTotalPerCountry(country, totalAllCountries); //populating the array
                rankTopThreeByTotal(totalAllCountries, countryNames);
                break;

            case 7: //Displays the top three country names and the total gold medals won by each of them – the display must be in order of total gold medals won.
                findTotalPerCountry(country, totalAllCountries); //populating the array
                rankTopThreeByMedal(country, countryNames);
                break;

            case 8: //Returns the total number of countries with no type of a medal = indexMedal (1 for Gold, 2 for Silver, 3 for Bronze)
                printf("Which medal do you want to find? (0 = Gold, 1 = Silver, 2 = Bronze) ");
                scanf("%d", &chooseMedal);
                if(chooseMedal < 0 || chooseMedal > 2) { //validating user input
                    printf("This is not a medal category \n");
                    break;
                }
                int foundCountries = findAllWithNoXMedals(country, chooseMedal, indexOfCountries);
                for(int i = 0; i < foundCountries; i++){ //printing out which countries have not won medals in the category
                    if (chooseMedal == 0){
                        printf("\n%s won no Gold medals\n", countryNames[indexOfCountries[i]]);
                    }
                    else if (chooseMedal == 1){
                        printf("\n%s won no Silver medals\n", countryNames[indexOfCountries[i]]);
                    }
                    else if (chooseMedal == 2){
                        printf("\n%s won no Bronze medals\n", countryNames[indexOfCountries[i]]);
                    }
                }
                if (foundCountries == 0){ //if all countries won medals in that category then no medals being found it indicated
                    printf("No coutries found for this medal value\n");
                }
                break;

            case 9: //Returns the total number of countries that have ONLY won medals of a specific category with the same indexMedal as case 8:
                printf("Which medal (0 = Gold, 1 = Silver, 2 = Bronze) would you like to pick? "); //everything from case 8 can be applied here too
                scanf("%d", &chooseMedal2);
                if(chooseMedal2 < 0 || chooseMedal2 > 2){
                    printf("This is not a medal category \n");
                    break;
                }
                int foundCountries2 = findAllWithOnlyXMedals(country, chooseMedal2, indexOfCountries);
                for(int i = 0; i < foundCountries2; i++){
                    if (chooseMedal2 == 0){
                        printf("\n%s has won only Gold medals\n", countryNames[indexOfCountries[i]]);
                    }
                    else if (chooseMedal2 == 1) {
                        printf("\n%s has won only Silver medals\n", countryNames[indexOfCountries[i]]);
                    }
                    else if (chooseMedal2 == 2) {
                        printf("\n%s has won only Bronze medals\n", countryNames[indexOfCountries[i]]);
                    }
                }
                if(foundCountries2 == 0){
                    printf("No countries found that have only won that medal value\n");
                }
                break;

            case 10: //Returns the index of the countryName that has min or max length and then selects which country that is
                printf("Find minimum(1) or maximum(2) name length?: "); //asks user if they want the min or the max
                scanf("%d", &minOrMax);
                if(minOrMax != 1 && minOrMax != 2){ //validating input
                    printf("This is an invalid choice\n");
                    break;
                }
                else { //printing the value from the function call
                    int indexCountry = findCountryIndexWithMinOrMaxLength(minOrMax, countryNames);
                    if (minOrMax == 1) {
                        printf("\n%s has the minumum name length\n", countryNames[indexCountry]);
                    }
                    else if (minOrMax == 2) {
                        printf("\n%s has the maximum name length\n", countryNames[indexCountry]);
                    }
                }
                break;

            case 11:
                return 0;
                // write all other cases
            default: printf ("That is an invalid choice\n");
        }
    }
    while (choice != 11);
    return 0;
}
//DONE!!
