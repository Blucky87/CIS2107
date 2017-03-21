/**
 * Name: Brian Luckenbill
 * TUID: 915149546
 * Date: March 2 2017
 * Course: CIS2107
 * Section: 003
 * Homework Number: 6 "Race"
 *          Part 2: Arrays of Pointers to Functions
 * Objective: To design and implement functions to process pointers
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <mem.h>
#include <unistd.h>

//how big to make arrays for the track
#define SQUARESIZE 71

//Fills string with ' ' 71 times
void createTrack(char *track);
//places a character at position in string
void updateTrack(char *track, int position, char icon);
//gets how much to move the tortise by using a random number
int getTortiseMove();
//gets how much to move the hare by using a random number
int getHareMove();


int main() {
    char track[SQUARESIZE];
    char ouchTrack[SQUARESIZE];
    int step = 1;
    int tortPreviousPosition = 0;
    int tortCurrentPosition = 0;
    int harePreviousPosition = 0;
    int hareCurrentPosition = 0;

    srand(time(NULL));

    printf("ON YOUR MARK, GET SET\n");
    printf("BANG !!!!!\n");
    printf("AND THEY'RE OFF !!!!!\n");

    createTrack(track);

    do{

        //keeps track of the previous position to clear it from the track
        tortPreviousPosition = tortCurrentPosition;
        //gets the new position and adds it to the previous
        tortCurrentPosition += getTortiseMove();
        //makes sure the position does not go into the negatives
        if(tortCurrentPosition < 0) tortCurrentPosition = 0;

        //keeps track of the previous position to clear it from the track
        harePreviousPosition = hareCurrentPosition;
        //gets the new position and adds it to the previous
        hareCurrentPosition += getHareMove();
        //makes sure the position does not go into the negatives
        if(hareCurrentPosition < 0) hareCurrentPosition = 0;

        //prints Ouch if the positions are the same and it is not the first move
        if(hareCurrentPosition == tortCurrentPosition && step != 1){
            strcpy(ouchTrack, track);
            updateTrack(track, harePreviousPosition, ' ');
            updateTrack(track, tortPreviousPosition, ' ');
            updateTrack(ouchTrack, harePreviousPosition, ' ');
            updateTrack(ouchTrack, tortPreviousPosition, ' ');
            ouch(ouchTrack, hareCurrentPosition);
            printf("%s\n", ouchTrack);
        } else {
            //updates the positions on the track
            updateTrack(track, harePreviousPosition, ' ');
            updateTrack(track, tortPreviousPosition, ' ');
            updateTrack(track, tortCurrentPosition, 'T');
            updateTrack(track, hareCurrentPosition, 'H');
            printf("%s\n", track);
        }

        printf("\n");

        if(hareCurrentPosition >= SQUARESIZE-1 && tortCurrentPosition >= SQUARESIZE-1){
            printf("\nIt's a tie\n");
            break;
        }else if(tortCurrentPosition >= SQUARESIZE-1){
            printf("\nTORTOISE WINS!!! YAY!!!\n");
            break;
        } else if(hareCurrentPosition >= SQUARESIZE-1){
            printf("\nHare wins. Yuch.\n");
            break;
        } else {
            step++;
            //sleep(1);
        }

    } while(1);

    return 0;
}

void updateTrack(char *track, int position, char icon){
    track[position] = icon;
}

void ouch(char *track, int position){
    int o = 0;
    char *ouch = "OUCH !!!";
    while(track[position] != '\0' && ouch[o] != '\0'){
        track[position++] = ouch[o++];
    }
}

void createTrack(char *track){
    int i;

    for(i = 0; i < SQUARESIZE; i++)
        track[i] = ' ';

    track[SQUARESIZE-1] = '\0';
}

int getTortiseMove() {
    int r = (rand() % 10) + 1;
    int movement = 0;

    if(r >= 1 && r <= 5)
        movement = 3;
    if(r >= 6 && r <= 7)
        movement = -6;
    if(r >= 8 && r <=10)
        movement = 1;

    return movement;
}

int getHareMove() {
    int r = (rand() % 10) + 1;
    int movement = 0;

    if(r >= 1 && r <= 2)
        movement = 0;
    if(r >= 3 && r <= 4)
        movement = 9;
    if(r == 5)
        movement = -12;
    if(r >= 6 && r <= 8)
        movement = 1;
    if(r >= 9 && r <=10)
        movement = -2;

    return movement;
}