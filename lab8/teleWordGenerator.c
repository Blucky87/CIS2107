/**
 * Name: Brian Luckenbill
 * TUID: 915149546
 * Date: March 31 2017
 * Course: CIS2107
 * Section: 003
 * Homework Number: 8 "TeleWordGenerator"
 *
 * Objective: To master file processing in C and solve a real-life challenge for businesses.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FILE_DESTINATION "luckenbill_lab8.txt"

//Takes in an array of 7 integers representing a phone number
//Generates a text file with words based on the inputted array values
void telewordFile(int phoneDigits[]);

//Recursively builds strings containing all possible letters from a keypad listed in an array
void recursiveLetterPlacement(char word[], int index, int phoneDigits[], FILE *file);

int main() {
    char input[9] = {0};
    int phoneDigits[7] = {0};
    int i, j = 0;

    printf("Format: 234-5678\nDigits: 2 thru 9 only\n");
    printf("Enter a Formatted Phone Number: ");
    scanf("%s", input);

    //iterate through the input for the digits
    for(i = 0; i < 8; i++){
        //if the input at the index is a digit, store it as an integer in an array
        if(isdigit(input[i])){
            phoneDigits[j] = input[i] - '0';
            j++;
        }
    }

    telewordFile(phoneDigits);
}


void telewordFile(int phoneDigits[]) {
    char word[8] = {0};
    //Create new file for writing
    FILE *file = fopen(FILE_DESTINATION, "w");

    //Generate telewords based off the phone number array of integers
    recursiveLetterPlacement(word, 0, phoneDigits, file);

    //Close file
    fclose(file);
}


void  recursiveLetterPlacement(char word[], int index, int phoneDigits[], FILE *file) {
    int i;
    char keyPad[10][5] = { {0},                         //0
                           {0},                         //1
                           {'A', 'B', 'C'},             //2
                           {'D', 'E', 'F'},             //3
                           {'G', 'H', 'I'},             //4
                           {'J', 'K', 'L'},             //5
                           {'M', 'N', 'O'},             //6
                           {'P', 'Q', 'R', 'S'},        //7
                           {'T', 'U', 'V'},             //8
                           {'W', 'X', 'Y', 'Z'} };      //9

    if(index == 7) {
        //print the completed word into the file
        fprintf(file, "%s\n", word);
        return;
    }

    int length = strlen(keyPad[phoneDigits[index]]);

    for(i = 0; i < length; i++) {
        //set the char from the keypad to the correct index in the word
        word[index] = keyPad[phoneDigits[index]][i];
        //must go deeper... run this function again but with an incremented index
        recursiveLetterPlacement(word, index+1, phoneDigits, file);
    }
}

