/**
 * Name: Brian Luckenbill
 * TUID: 915149546
 * Date: February 24 2017
 * Course: CIS2107
 * Section: 003
 * Homework Number: 4 "FunWith1DArrays"
 * Objective: Write a C Program to populate a 1D array with random integers and functions to reverse and search it
 */


#include<stdlib.h>
#include<time.h>
#include<stdio.h>

#define RANDOM_INTEGER_MAX  100
#define RANDOM_INTEGER_MIN 0
#define ARRAY_SIZE_MAX 40

//Fills the global array's indexes up to arraySize with random numbers from randomRangeLow to randomRangeHigh
void fillArray(int randomRangeLow, int randomRangeHigh, int arraySize);
//Returns the index of the largest element between indexes low and high of the global array
int findWithRange(int low, int high);
//Reverses the array data in between the indexes low and high
void reverseArray(int low, int high, int arraySize);
//print the array with marks to show the selected indexes
void printArrayWithSelection(int low, int high, int arraySize);
//prints out the standard array
void printArray(int arraySize);
//Returns the index of the first occurance of the tom and jerry sequence in the global array
int findSequence(int tom, int jerry, int arraySize);

static int array[ARRAY_SIZE_MAX];

int main(){

  srand(time(NULL));
  int i, random, randomRangeLow, randomRangeHigh, sectionReverseLow, sectionReverseHigh;
  int findRangeLow, findRangeHigh;
  int tomAndJerrySequenceIndex, tom, jerry;
  int arraySize = 0;

  printf("\n");

  //Get the size of elements to be in the array
  do{
    printf("\n");
    printf("MAX ARRAY SIZE ALLOWED: %d\n", ARRAY_SIZE_MAX);
    printf("Please Enter the Size of the Array: ");
    scanf("%i", &arraySize );
  } while(arraySize < 1 || arraySize > ARRAY_SIZE_MAX);


  //Get the range LOW and HIGH for the random integers to be generated.
  printf("\n----------------------------------------\n");

  printf("MAXIMUM INTEGER FOR RANDOM RANGE: %d\n", RANDOM_INTEGER_MAX-1);
  printf("MINIMUM INTEGER FOR RANDOM RANGE: %d\n", RANDOM_INTEGER_MIN );
  printf("Please enter the lowest number that may be generated.\n" );

  printf("Low: ");
  scanf("%d", &randomRangeLow );
  if(randomRangeLow < RANDOM_INTEGER_MIN){
    randomRangeLow = RANDOM_INTEGER_MIN;
    printf("Number too low, defaulting to: %d", randomRangeLow);
  }
  else if(randomRangeLow > RANDOM_INTEGER_MAX - 1){
    randomRangeLow = RANDOM_INTEGER_MAX - 1;
    printf("Number too high, defaulting to: %d", randomRangeLow);
  }

  printf("\n");
  printf("MAXIMUM INTEGER FOR RANDOM RANGE: %d\n", RANDOM_INTEGER_MAX);
  printf("MINIMUM INTEGER FOR RANDOM RANGE: %d\n", randomRangeLow + 1);
  printf("Please enter the High range of the random numbers generated.\n" );

  printf("High: ");
  scanf("%d", &randomRangeHigh );
  if(randomRangeHigh <= randomRangeLow){
    randomRangeHigh = randomRangeLow + 1;
    printf("\n** Number too low, defaulting to: %d **\n", randomRangeHigh);
  }
  else if(randomRangeHigh > RANDOM_INTEGER_MAX){
    randomRangeHigh = RANDOM_INTEGER_MAX;
    printf("\n** Number too high, defaulting to: %d **\n", randomRangeHigh);
  }

  //Select the index range to find the largest element in the selected range
  printf("\n----------------------------------------\n");

  printf("MAXIMUM INTEGER INDEX: %d\n", arraySize-1);
  printf("MINIMUM INTEGER INDEX: %d\n", 0);
  printf("Between which indexes would you like to find the highest intger?\n");

  printf("Low: ");
  scanf("%d", &findRangeLow);
  if(findRangeLow < 0) {
    findRangeLow = 0;
    printf("\n** Number too low, defaulting to: %d **\n", findRangeLow);
  } else if(findRangeLow > arraySize - 1){
    findRangeLow = arraySize - 1;
    printf("\n** Number too high, defaulting to: %d **\n", findRangeLow);
  }

  printf("High: ");
  scanf("%d", &findRangeHigh);
  if(findRangeHigh < findRangeLow + 1) {
    findRangeHigh = 0;
    printf("\n** Number too low, defaulting to: %d **\n", findRangeHigh);
  } else if(findRangeHigh > arraySize) {
    findRangeHigh = arraySize;
    printf("\n** Number too high, defaulting to: %d **\n", findRangeHigh);
  }

  //Chooses the index range of the array to reverse
  printf("\n----------------------------------------\n");
  printf("MAXIMUM INTEGER INDEX: %d\n", arraySize - 1);
  printf("MINIMUM INTEGER INDEX: %d\n", 0);
  printf("Between Which Indexes would you like to reverse.\n");

  printf("Low: ");
  scanf("%d", &sectionReverseLow);
  if(sectionReverseLow < 0) {
    sectionReverseLow = 0;
    printf("\n** Number too low, defaulting to: %d **\n", sectionReverseLow);
  } else if(sectionReverseLow > arraySize - 1){
    sectionReverseLow = arraySize - 1;
    printf("\n** Number too high, defaulting to: %d **\n", sectionReverseHigh);
  }

  printf("\n");
  printf("MAXIMUM INTEGER INDEX: %d\n", arraySize);
  printf("MINIMUM INTEGER INDEX: %d\n", sectionReverseLow + 1);
  printf("Between Which Indexes would you like to reverse.\n");

  printf("High: ");
  scanf("%d", &sectionReverseHigh);
  if(sectionReverseHigh < sectionReverseLow + 1) {
    sectionReverseHigh = 0;
    printf("\n** Number too low, defaulting to: %d **\n", sectionReverseHigh);
  } else if(sectionReverseHigh > arraySize) {
    sectionReverseHigh = arraySize;
    printf("\n** Number too high, defaulting to: %d **\n", sectionReverseHigh);
  }


  //generate the array and print it out in the various forms
  printf("\n-Fills a 1D array with integers between %d and %d-\n\n", randomRangeLow, randomRangeHigh);
  fillArray(randomRangeLow, randomRangeHigh, arraySize);
  printArray(arraySize);

  printf("\n");

  printf("\n-Finding the maximum value in specified index range-\n\n");
  printArrayWithSelection(findRangeLow, findRangeHigh, arraySize);

  int largestInSelectionIndex;
  largestInSelectionIndex = findWithRange(findRangeLow, findRangeHigh);

  printf("\n\n");
  printf(" Max = %02d", array[largestInSelectionIndex]);
  printf("\n\n");
  printf("\n-Reverse the entire array-\n\n");
  reverseArray(0, arraySize-1, arraySize);
  printArray(arraySize);

  printf("\n\n");

  reverseArray(sectionReverseLow, sectionReverseHigh, arraySize);
  printf("\n-Reverse only the specified index ranges-\n\n");
  printArrayWithSelection(sectionReverseLow, sectionReverseHigh, arraySize);

  printf("\n\n");

  printf("\n----------------------------------------\n");
  printf("Search for Tom and Jerry sequence. *Please Exclude Leading Zeros if Number is Below 10*\n");
  printf("Tom: ");
  scanf("%d", &tom);
  printf("Jerry: ");
  scanf("%d", &jerry);
  tomAndJerrySequenceIndex = findSequence(tom, jerry, arraySize);
  if(tomAndJerrySequenceIndex != -1){
    printf("\nSequence found at index %d\n", tomAndJerrySequenceIndex);
  } else {
    printf("\nSequence not found\n");
  }

  printf("\n\n");

  return 0;
}

void printArray(int arraySize){
  int i;

  printf(" ");
  for(i = 0; i < arraySize; i++){
    printf("%02d  ", array[i]);

    if(!((i+1) % 5))
      printf("\n ");
  }

}

void printArrayWithSelection(int low, int high, int arraySize){
  int i;
  int marker = 0;

  for(i = 0; i < arraySize; i++){
    if(i == low){
      printf("[%02d-", array[i]);
    } else if(i == high || ((i == high) && (high >= arraySize))) {
      printf("-%02d]", array[i]);
    } else if(i > low && i < high) {
      printf("-%02d-", array[i]);
    } else {
      printf(" %02d ", array[i]);
    }

    if(!((i+1) % 5))
      printf("\n");

  }

}

void fillArray(int randomRangeLow, int randomRangeHigh, int arraySize) {
  int i, randomNumber;

  for(i = 0; i < arraySize; i++){
    array[i] = randomRangeLow + random() % (randomRangeHigh - randomRangeLow);
  }

}


int findWithRange(int lowestIndex, int highestIndex) {
  int i, indexOfLargest;

  indexOfLargest = lowestIndex;

  for(i = lowestIndex; i <= highestIndex; i++){
    if(array[i] > array[indexOfLargest]){
      indexOfLargest = i;
    }
  }

  return indexOfLargest;
}

void reverseArray(int low, int high, int arraySize){
  int i, j, temp;

  for(i=low, j=high; i < j; i++, j--){
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

int findSequence(int tom, int jerry, int arraySize){
  int i;

  for(i=0; i<arraySize-1; i++){
    if(array[i] == tom && array[i+1] == jerry){
      return i;
    }
  }

  return -1;
}
