#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**********************************************************************
Compiling the program:
The program should be compiled using the following flags -std=c99 -Wall

compiling:
gcc -std=c99 -Wall sequenceDNA.c

running:./a.out
**********************************************************************/

#define SIZE 100
#define NUMPROTEINS 64

//function prototypes:
bool isBasePair (char neu1, char neu2); //done
bool isItaDnaSequence (char strand1[SIZE], char strand2[SIZE]); //done
void reverse (char aStrand[SIZE]); //done
void complementIt (char aStrand[SIZE]); //done
bool isItPalindrome (char aStrand[SIZE]); //done
bool isStrandDnaPalindrome (char aStrand[SIZE]); //done
int howMany(char aStrand [SIZE], char neu); //done
void dnaToMrna (char aSeq [SIZE], char mRNA[SIZE]); //done
void translateDnaToMrnaProteins (char aSeq[SIZE]); //done
char getCode(char protein[3]);

int main() { //testing out my functions to see if they work
   int result1, result2, result3, x, i;
   char dnaStrand1[SIZE] = {"GCTA"};
   char dnaStrand2[SIZE] = {"CGAT"};

   input1 = 'A';
   input2 = 'T';

   result1 = isBasePair(input1, input2);

   if (result1 == 1){
      printf("%c and %c are a pair. \n", input1, input2);
   }
   else if (result1 == 0) {
      printf("These are not a pair. \n");
   }

   result2 = isItaDnaSequence (dnaStrand1, dnaStrand2);

   if (result2 == 1) {
      printf("These two DNA strands are a pair. \n");
   }

   else if (result2 == 0) {
      printf("These two DNA strands are not a pair. \n");
   }

   reverse(dnaStrand1);
   printf("%s\n", dnaStrand1);

   complementIt(dnaStrand1);
   printf("%s\n", dnaStrand1);

   result3 = isItPalindrome(dnaStrand1);

   if (result3 == 1) {
      printf("This is a palindrome\n");
   }
   else if (result3 == 0) {
      printf("This is not a palindrome\n");
   }
}


//donefunction1 - checks to see if they are valid base pairs
bool isBasePair (char neu1, char neu2) {
   //either of these can be true to validate whether the base pair exists
   if (neu1 == 'A' && neu2 == 'T') {
      return 1;
   }
   else if (neu1 == 'T' && neu2 == 'A') {
      return 1;
   } //same with G and C which are complementary
   else if (neu1 == 'G' && neu2 == 'C') {
      return 1;
   }
   else if (neu1 == 'C' && neu2 == 'G') {
      return 1;
   }
   else {
      return 0;
   }
}

//donefunction2
bool isItaDnaSequence (char strand1 [SIZE], char strand2 [SIZE]){
   int i, isSequence;
   int length = strlen(strand1);

  //finds the string length and iterates if it is lower than that length
   for (i = 0; i < length; i++){
      if ((strand1[i] == 'A' && strand2[i] == 'T') || (strand1[i] == 'T' && strand2[i] == 'A')){
         isSequence = 1;
      }
  //repeats the same step for the other sequence possibilities
      else if ((strand1[i] == 'G' && strand2[i] == 'C') || (strand1[i] == 'C' && strand2[i] == 'G')){
         isSequence = 1;
      }
      else {
         return 0;
      }
   }
   //giving true or false return boolean values, 1 is true, 0 is false
   if (isSequence == 1) {
      return 1;
   }
   else {
      return 0;
   }
}

//donefunction 3
void reverse (char aStrand[SIZE]){
   char reversedStrand[SIZE] = ""; //creates a temporary empty array
   int length = strlen(aStrand); // finds the length
   //int positions = (length - 1);
   strcpy(reversedStrand, aStrand);

   for (int positions = (length - 1); positions >= 0; positions--){
     //aStrand[positions] = reversedStrand[i];
     reversedStrand[positions] = aStrand[length - positions - 1];
   } //reverses the original array onto the temporary array
   strcpy(aStrand, reversedStrand); //moving it back to the original
   //printf("%s", aStrand[length])
   //for (int i = 0; i<= positions; i++) {
     //printf("%c", aStrand[i]);
   //}
}

// done function 4
void complementIt (char aStrand [SIZE]) {

// loops through each value of the array and re assigns it to the complement
   for(int i = 0; i < SIZE; i++) {
      if (aStrand[i] == 'A') {
         aStrand[i] = 'T';
      }

      else if (aStrand[i] == 'T') {
         aStrand[i] = 'A';
      } //neucleotide A and T are complements

      else if (aStrand[i] == 'G') {
         aStrand[i] = 'C';
      }

      else if (aStrand[i] == 'C') {
         aStrand[i] = 'G'; //the 4 if and else if statements give us the new version of aStrand
      }
      //printf("%c", aStrand[i]);
   }
}

// done function 5 - finds palindrome
bool isItPalindrome (char aStrand [SIZE]) {
   char checkPal[SIZE] = ""; //creates empty string
   int length = strlen(aStrand); //find length
   //int positions = (length - 1);
   strcpy(checkPal, aStrand);

   for (int positions = (length - 1); positions >= 0; positions--) {
      aStrand[length - positions - 1] = checkPal[positions];
   } //the reverse function

   int compare = strcmp(checkPal, aStrand); //compares, if they are the same it will give 0

   if (compare == 0) {
      return 1; //the boolean for true
      //printf("this is a palindrome");
   }

   else {
      return 0;
      //printf("this is not a palindrome");
   }
}


//done function 6

bool isStrandDnaPalindrome (char aStrand [SIZE]) {
   char tempStrand[SIZE] = "";
   int length = strlen(aStrand);
   //int positions = (length - 1);
   int isDnaPalindrome = 0;
   int i = 0;


   strcpy(tempStrand, aStrand);
   //printf("%s\n", tempStrand);
   reverse(tempStrand);
   //printf("%s\n", tempStrand);
   complementIt(tempStrand);
   //printf("%s\n",tempStrand);
   for (i = 0; i < length; i++){
      if ((tempStrand[i] == aStrand[i])) {
         isDnaPalindrome = 1;
      }
      else {
         return 0;
      }
   }
   return isDnaPalindrome;
}

// done function 7 - find how many neucleotides are in a strand
int howMany (char aStrand[SIZE], char neu){
  int amount = 0;
  int length = strlen(aStrand);
  for (int i = 0; i < length; i++){ // for loop to go through each position
    if (aStrand[i] == neu){ // if they are equal to the thing
      amount++; //counter
    }
  }
  return amount;
}

// done function 8
void dnaToMrna (char aSeq[SIZE], char mRNA[SIZE]) { //same as complement except T is replaced by U in the mRNA
   int length = strlen(aSeq);
   for (int i = 0; i < length; i++) {
      if (aSeq[i] == 'A') {
         mRNA[i] = 'U';
      }
      else if (aSeq[i] == 'T') {
         mRNA[i] = 'A';
      }
      else if (aSeq[i] == 'G') {
         mRNA[i] = 'C';
      }
      else if (aSeq[i] == 'C') {
         mRNA[i] = 'G';
      }
      else {
        mRNA[i] = aSeq[i];
      }
   }
}


//STUB!!!! function 9 - I did not get this function to output the desired output
void translateDnaToMrnaProteins(char aSeq[SIZE]) {
  int i = 0, j = 0;

  //initializing variables again
  int length = strlen(aSeq);
  int lengthOfThree = (length / 3);  //to make sure it gets cut into even sections of 3
  char mRNA[SIZE];
  char threeMRNANeu[SIZE];
  char aminoAcid;

  dnaToMrna(aSeq, mRNA); //function 8 repeated to get the mRNA strand of the DNA strand
  printf("%s", mRNA);

//printing the output
  printf("\nDNA: %s", aSeq);
  printf("\nmRNA: %s, which translates to: \n", mRNA);

//if there are 3 sections which can be split up into an amino acid then the for loop runs
  if (length >= 3) { //possible to have mRNA
    for (i = 0; i < lengthOfThree; i++) { //takes the whole and gets rid of the extras
      for (j = 0; j < 3; j++) { // loops for every 3 sections withing the array as a whole
         threeMRNANeu[j] = mRNA[i*3 + j];
      }
      aminoAcid = getCode(threeMRNANeu); //calling the provided function
      printf("%s : %c\n", threeMRNANeu, aminoAcid);
      if (aminoAcid == 'Z') { //the input validation
         printf("The input sequence has an incorrect base\n");
      }
      //printing everything out
      //printf("%s : %c", threeMRNANeu, aminoAcid);
      //printf(" : %c", aminoAcid);
    }
  }
  printf("\n");
}
// the function that I copied and pasted from CourseLink
char getCode (char protein [3]) {
    // array allProteins has a list of all 3-triplet amino acids required for this assignment
    char allProteins [NUMPROTEINS][SIZE] = {"GCA", "GCC", "GCG", "GCU", "AGA","AGG", "CGA", "CGC","CGG","CGU","GAC", "GAU","AAC","AAU","UGC","UGU","GAA","GAG","CAA","CAG", "GGA", "GGC","GGG","GGU","CAC", "CAU","AUA","AUC","AUU", "UUA", "UUG","CUA","CUC", "CUG", "CUU", "AAA", "AAG","AUG", "UUC","UUU", "CCA", "CCC", "CCG", "CCU", "AGC","AGU","UCA","UCC","UCG", "UCU","ACA","ACC","ACG", "ACU", "UGG","UAC","UAU", "GUA","GUC","GUG", "GUU"};
    // array allCodes stores the single-letter code of each triplet given in the above array
    char allCodes [NUMPROTEINS] = {'A','A','A','A','R','R','R','R','R','R','D','D','N','N','C','C','E','E','Q','Q', 'G','G','G','G','H','H','I','I','I', 'L','L','L','L','L','L','K','K','M','F','F','P','P','P','P','S','S','S','S','S','S','T','T','T','T', 'W','Y','Y','V','V','V','V'};
    for (int i = 0; i < NUMPROTEINS; i++) {
        if  (strncmp (protein, allProteins[i], 3) == 0) {
            return allCodes [i];
        }
    }
    return 'Z';   // to indicate an incorrect code - code that doesn't exist in array allCodes
}
//DONE!!
