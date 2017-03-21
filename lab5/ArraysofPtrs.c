/**
 * Name: Brian Luckenbill
 * TUID: 915149546
 * Date: March 2 2017
 * Course: CIS2107
 * Section: 003
 * Homework Number: 5 "2DArrays & Arrays of Pointers to Functions"
 *          Part 2: Arrays of Pointers to Functions
 * Objective: To design and implement arrays of pointers to functions
 */

#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

// function prototypes
void minimum(const int grades[][EXAMS], int pupils, int tests);
void maximum(const int grades[][EXAMS], int pupils, int tests);
void average(const int grades[][EXAMS], int pupils, int tests);
void printArray(const int grades[][EXAMS], int pupils, int tests);
//array of pointers
void (*funcPtr[3])(const int[][EXAMS], int, int);

// function main begins program execution
int main(void) {
  int input;
  // initialize student grades for three students (rows)
  const int studentGrades[STUDENTS][EXAMS] =
          { { 77, 68, 86, 73 },
            { 96, 87, 89, 78 },
            { 70, 90, 86, 81 } };

  //Assign the functions in the menu to the corresponding index in the array of pointers
  funcPtr[0] = &printArray;
  funcPtr[1] = &minimum;
  funcPtr[2] = &maximum;
  funcPtr[3] = &average;

  //main menu loop
  do {
      //menu selection loops
      do {
          printf("\nEnter a choice:\n");
          printf("\t0 Print the array of grades\n");
          printf("\t1 Find the minimum grade\n");
          printf("\t2 Find the maximum grade\n");
          printf("\t3 Print the average on all tests for each student\n");
          printf("\t4 End Program\n");
          printf("Choice: ");
          scanf("%d", &input);
      } while (input < 0 || input > 4);

      printf("\n");

      //Exit the menu loop if user selects End Program
      if(input == 4){
          break;
      }

      //Run the function based on user input
      (*funcPtr[input])(studentGrades, STUDENTS, EXAMS);
  }while(1);

}

// Find the minimum grade
void minimum(const int grades[][EXAMS], int pupils, int tests) {
  int lowGrade = 100; // initialize to highest possible grade
  int i, j;

  // loop through rows of grades
  for (i = 0; i < pupils; ++i) {

      // loop through columns of grades
      for (j = 0; j < tests; ++j) {

          if (grades[i][j] < lowGrade) {
              lowGrade = grades[i][j];
          }
      }
  }

  printf("Lowest Grade: %d\n",lowGrade);
}

// Find the maximum grade
void maximum(const int grades[][EXAMS], int pupils, int tests) {
  int highGrade = 0; // initialize to lowest possible grade
  int i, j;

  // loop through rows of grades
  for (i = 0; i < pupils; ++i) {

      // loop through columns of grades
      for (j = 0; j < tests; ++j) {

          if (grades[i][j] > highGrade) {
              highGrade = grades[i][j];
          }
      }
  }

  printf("Highest grade is: %d\n", highGrade);
}

// Determine the average grade for a particular student
void average(const int grades[][EXAMS], int pupils, int tests) {
  int total;
  int i, j;

  for (i = 0; i < pupils; ++i) {
      total = 0;
      // loop through columns of grades
      for (j = 0; j < tests; ++j) {
          total += grades[i][j];
      }

      printf("Student %d average = %d\n", i, total/EXAMS);
  }

}

// Print the array
void printArray(const int grades[][EXAMS], int pupils, int tests) {
  int i;
  int j;
  // output column heads
  printf("%s", "                 [0]  [1]  [2]  [3]");

  // output grades in tabular format
  for (i = 0; i < pupils; ++i) {

      // output label for row
      printf("\nstudentGrades[%d] ", i);

      // output grades for one student
      for (j = 0; j < tests; ++j) {
          printf("%-5d", grades[i][j]);
      }
  }

  printf("\n");
}
