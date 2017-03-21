/**
 * Name: Brian Luckenbill
 * TUID: 915149546
 * Date: March 2 2017
 * Course: CIS2107
 * Section: 003
 * Homework Number: 5 "2DArrays & Arrays of Pointers to Functions"
 *          Part 1: 2D Arrays Processing
 * Objective: To design and implement functions to proces 2DArrays
 */

#include<stdio.h>

//returns the maximum integer found in an arrray
int max(int col, int row, int array[][col]);
//returns the sum of a row of an array, vector is the row number and vectorLength is how many columns to include
int rowSum(int col, int array[][col], int vector, int vectorLength);
//returns the sum of a column of an array, vector is the column number and vectorLength is how many rows to include
int columnSum(int col, int array[][col], int vector, int vectorLength);
//returns 0 if col and row are not equal, 1 if they do
int isSquare(int col, int row);
//prints the elemts of a 2D array
void displayOutput(int col, int row, int array[][col]);
//adds elements of a 2D array, inner is the row start point, innerEnd is what row to stop, outer is column start point, outerEnd is what column to stop
int sumElements(int col, int array[][col], int inner, int innerEnd, int outer, int outerEnd);


int main (void){
    int arraySizeRow, arraySizeColumn;
    int i, j;

    printf("\nLet's create a 2Dim array!\n");

    do{
        printf("\tHow many rows? ");
        scanf("%d", &arraySizeRow);
    }while(arraySizeRow <= 0);

    printf("\n");

    do{
        printf("\tHow many columns? ");
        scanf("%d", &arraySizeColumn);
    }while(arraySizeColumn <= 0);

    printf("\n");

    //Declare 2D array
    int theArray[arraySizeRow][arraySizeColumn];

    //Enter integers into all indexes of the array
    for (i = 0; i < arraySizeRow; i++) {
        for (j = 0; j < arraySizeColumn; j++) {
            printf("\tenter [%d][%d]: ", i, j);
            scanf("%d", &theArray[i][j]);
        }
    }

    printf("\n");

    //prints the sum of a row, looped iterate over all rows
    for(i = 0; i < arraySizeRow; i++){
        printf("Sum of row %d = %d\n", i+1, rowSum(arraySizeColumn, theArray, i, arraySizeColumn));
    }

    printf("\n");

    //prints the sum of a column, looped to iterate over all the columns
    for(i = 0; i < arraySizeColumn; i++){
        printf("Sum of column %d = %d\n", i+1, columnSum(arraySizeColumn, theArray, i, arraySizeRow));
    }

    printf("\n");

    //check if the array is a square, prints appropriate message
    if(isSquare(arraySizeColumn, arraySizeRow)){
        printf("This is a square array");
    } else {
        printf("This is not a square array");
    }

    printf("\n");

    //Display the output of the array
    displayOutput(arraySizeColumn, arraySizeRow, theArray);


}


int max(int col, int row, int array[][col]){
    int i, j;
    int max = array[0][0];

    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(array[i][j] > max){
                max = array[i][j];
            }
        }
    }

    return max;
}

int sumElements(int col, int array[][col], int inner, int innerEnd, int outer, int outerEnd){
    int total = 0;

    int incrementInner = !(inner == innerEnd);
    int incrementOuter = !(outer == outerEnd);

    do {
        do{
            total += array[inner][outer];

            if(incrementOuter) ++outer;
        }while(outer != outerEnd);

        if(incrementInner) ++inner;
    }while(inner != innerEnd);

    return total;
}

int rowSum(int col, int array[][col], int vector, int vectorLength){
    return sumElements(col, array, vector, vector, 0, vectorLength);
}

int columnSum(int col, int array[][col], int vector, int vectorLength){
    return sumElements(col, array, 0, vectorLength, vector, vector);
}

int isSquare(int col, int row){
    return (row == col);
}

void displayOutput(int col, int row, int array[][col]) {
    int i;
    int j;

    printf("\nHere is your 2Dim array:\n");

    for(i = 0; i < row; i++){
        printf("[ ");
        for(j = 0; j < col; j++){
            printf("%d", array[i][j]);
            if(j != col-1){
                printf(", ");
            }
        }
        printf(" ]\n");
    }

    printf("\n");
}
