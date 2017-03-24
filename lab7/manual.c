/**
 * Name: Brian Luckenbill
 * TUID: 915149546
 * Date: March 24 2017
 * Course: CIS2107
 * Section: 003
 * Homework Number: 7 "Manual"
 * Objective: To design and implement functions to process characters and strings
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


typedef struct {
    int areaCode;
    long lineNumber;
    char concat[8];
}Telephone;

//Every other character uppercase then lowercase
char *lowerUpper(const char *string);
//takes a pointer to a pointer of strings and converts to them to integers and adds them
int convertStrtoInt(char **string, unsigned number);
//takes a pointer to a pointer of strings and converts to them to floats and adds them
float convertStrtoFloat(char **string, unsigned number);
//compares two strings and returns a string describing if the 1st is greater than, equal to or less than the second
char *compareStr(const char *string1, const char *string2);
//compares two strings up to a certain length and returns a string describing if the 1st is greater than, equal to or less than the second
char *comparePartialStr(const char *string1, const char *string2, unsigned number);
//prints a random story composed of preset words
void randomize();
//takes a telephone number as a string in the form "(000) 000-0000" and converts portions of it into a int and long
Telephone *tokenizeTelNum(char string[15]);
//Takes a string and breaks up by words and prints it in reverse order
void reverse(char string[]);
//searches an array of strings for a specific substring and returns how many it found
int countSubstr(char *search, char *strings[], int numStrings);
//searches and array of strings for a specific character and returns how many it found
int countChar(char search, char *strings[], int numStrings);
//takes an array of strings and prints how many of each alphabet letter it found
void countAlpha(char *strings[], int numStrings);
//takes an array of string pointers and returns how many words total it has found
int countWords(char *strings[], int numStrings);
//takes an array of string pointers and prints the strings that begin with a 'B' or 'b'
void startsWithB(char *strings[], int numStrings);
//takes an array of string pointers and prints only the strings that end in "ed"
void endsWithed(char *strings[], int numStrings);

//used in the reverse function to get tokens and return how many there are
int getTokens(char *tokens[], int numTokens, char string[]);
//returns the given string with the first letter capitalized used in the randomized story
char *getCapWord(char string[]);



int main() {
    char *tempStr1 = "This is a temporary String";
    char *tempStr2 = "This is a temporary String";
    char *tempStr3 = "This is a temporary String";
    char *tempStr4 = "This is a temporary String";
    char tempStr5[] = "This is a temporary String";
    char string2[12] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
    char *stringInt[8] = {"1", "2", "3", "4", "5", "1", "2", "99"};
    char *stringFloat[8] = {"1.1", "2.4884", "3.1123", "4.912821", "5.22", "1.88", "2.2", "99.3"};
    char phone[] = "(555) 555-5555";
    Telephone *telephone = NULL;
    char *tempStrings[4];

    printf("\n----------------------------------------------\n\n");

    printf("Function lowerUpper:\n\n");
    printf("Input: \"%s\"\n", string2);
    printf("Output: \"%s\"", lowerUpper(string2));

    printf("\n\n----------------------------------------------\n\n");

    printf("Function convertStrToInt:\n\n");
    printf("Input: \"%s\",  \"%s\",  \"%s\",  \"%s\"\n", stringInt[0], stringInt[1], stringInt[2], stringInt[3]);
    printf("Output: %d", convertStrtoInt(stringInt, 4));

    printf("\n\n----------------------------------------------\n\n");

    printf("Function convertStrToFloat:\n\n");
    printf("Input: \"%s\",  \"%s\",  \"%s\",  \"%s\"\n", stringFloat[0], stringFloat[1], stringFloat[2], stringFloat[3]);
    printf("Output: %f", convertStrtoFloat(stringFloat, 4));

    printf("\n\n----------------------------------------------\n\n");

    tempStr1 = "This is String 1";
    tempStr2 = "The other one";

    printf("Function compareStr:\n\n");
    printf("Input: \"%s\",  \"%s\"\n", tempStr1, tempStr2);
    printf("Output: \"%s\" is <%s> \"%s\"", tempStr1, compareStr(tempStr1, tempStr2), tempStr2);

    printf("\n\n----------------------------------------------\n\n");

    printf("Function comparePartialStr:\n\n");
    printf("Input: \"%s\",  \"%s\"  :  using %d characters\n", tempStr1, tempStr2, 7);
    printf("Output: \"%s\" is <%s> \"%s\"", tempStr1, comparePartialStr(tempStr1, tempStr2, 7), tempStr2);

    printf("\n\n----------------------------------------------\n\n");

    printf("Function randomize:\n\n");
    printf("Output:\n\t");
    randomize();

    printf("\n\n----------------------------------------------\n\n");

    printf("Function tokenizeTelNum:\n\n");
    printf("Input: \"%s\"\n", phone);
    telephone = tokenizeTelNum(phone);
    printf("Output: %d %ld", telephone->areaCode, telephone->lineNumber);

    printf("\n\n----------------------------------------------\n\n");

    printf("Function reverse:\n\n");
    printf("Input: \"%s\"\n", tempStr5);
    printf("Output: ");
    reverse(tempStr5);

    printf("\n\n----------------------------------------------\n\n");

    tempStr1 = "string test 1";
    tempStr2 = "test string 2";
    tempStr3 = "other testing one";
    tempStr4 = "final string to use the string";


    tempStrings[0] = tempStr1;
    tempStrings[1] = tempStr2;
    tempStrings[2] = tempStr3;
    tempStrings[3] = tempStr4;

    printf("Function countSubstr:\n\n");
    printf("Input: \"%s\", \"%s\", \"%s\", \"%s\"\n", tempStrings[0], tempStrings[1], tempStrings[2], tempStrings[3]);
    printf("Substring: \"%s\"\nOccurrences: %d", "string", countSubstr("string", tempStrings, 4));

    printf("\n\n----------------------------------------------\n\n");

    tempStr1 = "character";
    tempStr2 = "char test";
    tempStr3 = "cup of coffee";
    tempStr4 = "candy";

    tempStrings[0] = tempStr1;
    tempStrings[1] = tempStr2;
    tempStrings[2] = tempStr3;
    tempStrings[3] = tempStr4;

    printf("Function countChar:\n\n");
    printf("Input: \"%s\", \"%s\", \"%s\", \"%s\"\n", tempStrings[0], tempStrings[1], tempStrings[2], tempStrings[3]);
    printf("Character: \'%c\'\nOccurrences: %d", 'c', countChar('c', tempStrings, 4));

    printf("\n\n----------------------------------------------\n\n");

    tempStrings[0] = "The quick Brown";
    tempStrings[1] = "Fox jumps";
    tempStrings[2] = "over The";
    tempStrings[3] = "lazy Dog";

    printf("Function countAlpha:\n\n");
    printf("Input: \"%s\", \"%s\", \"%s\", \"%s\"\n", tempStrings[0], tempStrings[1], tempStrings[2], tempStrings[3]);
    countAlpha(tempStrings,4);

    printf("\n\n----------------------------------------------\n\n");

    tempStr1 = "character";
    tempStr2 = "char test";
    tempStr3 = "cup of coffee";
    tempStr4 = "candy";

    tempStrings[0] = tempStr1;
    tempStrings[1] = tempStr2;
    tempStrings[2] = tempStr3;
    tempStrings[3] = tempStr4;

    printf("Function countChar:\n\n");
    printf("Input: \"%s\", \"%s\", \"%s\", \"%s\"\n", tempStrings[0], tempStrings[1], tempStrings[2], tempStrings[3]);
    printf("# of words: %d", countWords(tempStrings, 4));

    printf("\n\n----------------------------------------------\n\n");

    tempStrings[0] = "Blue";
    tempStrings[2] = "Broken";
    tempStrings[3] = "Bike";

    printf("Function startsWithB:\n\n");
    printf("Input: \"%s\", \"%s\", \"%s\", \"%s\"\n", tempStrings[0], tempStrings[1], tempStrings[2], tempStrings[3]);
    printf("Output:\n");

    startsWithB(tempStrings, 4);

    printf("\n----------------------------------------------\n\n");

    tempStrings[1] = "Pedaled";
    tempStrings[3] = "coded";

    printf("Function endsWithed:\n\n");
    printf("Input: \"%s\", \"%s\", \"%s\", \"%s\"\n", tempStrings[0], tempStrings[1], tempStrings[2], tempStrings[3]);
    printf("Output:\n");

    endsWithed(tempStrings, 4);

    printf("\n----------------------------------------------\n\n");


    return 0;
}

char *lowerUpper(const char *string){
    char *rtnPntr = NULL;
    size_t i, length;

    length = strlen(string);
    rtnPntr = malloc(length);
    int (*foo) (int);

    for(i = 0; i < length; i++){
        foo = (i & 1) ? toupper : tolower;
        *(rtnPntr++) = (char) foo(*(string++));
    }

    *rtnPntr = '\0';

    return (rtnPntr - length);
}

int convertStrtoInt(char **string1, unsigned number){
    size_t i;
    int temp;

    for(i = 0, temp = 0; i < number; i++){
        temp += atoi(*(string1++));
    }

    return temp;
}

float convertStrtoFloat(char **string1, unsigned number){
    size_t i;
    float temp;

    for(i = 0, temp = 0; i < number; i++){
        temp += atof(*(string1++));
    }

    return temp;
}

char *compareStr(const char *string1, const char *string2){
    char *temp = NULL;
    int value = strcmp(string1, string2);

    if(value > 0){
        temp = "greater than";
    } else if(value < 0){
        temp = "less than";
    }else {
        temp = "equal to";
    }

    return temp;
}

char *comparePartialStr(const char *string1, const char *string2, unsigned number){
    char *temp = NULL;
    int value = strncmp(string1, string2, number);

    if(value > 0){
        temp = "greater than";
    } else if(value < 0){
        temp = "less than";
    }else {
        temp = "equal to";
    }

    return temp;
}

//it works..
void randomize(){
    char *article[]     = {"the", "a", "one", "some", "any"};
    char *noun[]        = {"boy", "girl", "dog", "town", "car"};
    char *verb[]        = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[] = {"to", "from", "over", "under", "on"};
    int i, rand1, rand2;
    char *sentences[20] = { 0 };
    char paragraph[1024];
    char *temp;
    const int paragraphSize = 10;

    srand((unsigned)time(NULL));

    for(i = 0; i < 20; i++){
        temp = malloc(64);
        rand1 = rand() % 5;
        rand2 = rand() % 5;
        sprintf(temp, "%s %s %s %s %s %s. ", getCapWord(article[rand1]), noun[rand2], verb[rand1], preposition[rand2], article[rand2], noun[rand1]);
        sentences[i] = temp;
    }

    strcpy(paragraph, sentences[0]);
    for(i = 1; i < paragraphSize; i++){
        strcat(paragraph, sentences[i]);
    }

    printf("\n\"%s\"", paragraph);
}

char *getCapWord(char string[]){
    char *tempString = malloc(16);

    strcpy(tempString, string);
    *tempString = (char)toupper(*tempString);

    return tempString;

}

Telephone *tokenizeTelNum(char *string){
    Telephone *temp = NULL;
    temp = malloc(sizeof(Telephone));
    char *delim = "()-";

    temp->areaCode = atoi(strtok(string, delim));
    strtok(NULL, delim);
    temp->lineNumber = atol(strtok(NULL, delim));
    sprintf(temp->concat, "%d%ld", temp->areaCode, temp->lineNumber);

    return temp;
}

void reverse(char string[]){
    const int maxTokens = 16;
    int numTokens, i;
    char *tokens[maxTokens];

    numTokens = getTokens(tokens,maxTokens,string);

    for(; numTokens > 0; numTokens--){
        printf("%s ", tokens[numTokens-1]);
    }

}

int getTokens(char *tokens[], int maxTokens, char string[]){
    int i = 0;
    char *ptr = strtok(string, " ");

    while(ptr != NULL && i <= maxTokens){
        tokens[i++] = ptr;
        ptr = strtok(NULL, " ");
    }

    int temp = i;

    for(;temp < maxTokens; temp++){
        tokens[temp] = NULL;
    }

    return i;
}

int countSubstr(char *search, char *strings[], int numStrings){
    int i = 0;
    int substrings = 0;

    for(i = 0; i < numStrings; i++){
        while((strings[i] = strstr(strings[i], search)) != NULL){
            substrings++;
            strings[i]++;
        }
    }

    return substrings;
}


int countChar(char search, char *strings[], int numStrings){
    int i = 0;
    int charCount = 0;
    int j = 0;
    int iterator = 0;

    for(i = 0; i < numStrings; i++){
        char *temp = strings[i];
        while((strings[i] = strchr(strings[i], search)) != NULL){
            charCount++;
            strings[i]++;
        }
        strings[i] = temp;
    }

    return charCount;
}

void countAlpha(char *strings[], int numStrings){
    int alphabet[26];

    alphabet[0]  = (countChar('a',strings, numStrings) + countChar('A', strings, numStrings));
    alphabet[1]  = (countChar('b',strings, numStrings) + countChar('B', strings, numStrings));
    alphabet[2]  = (countChar('c',strings, numStrings) + countChar('C', strings, numStrings));
    alphabet[3]  = (countChar('d',strings, numStrings) + countChar('D', strings, numStrings));
    alphabet[4]  = (countChar('e',strings, numStrings) + countChar('E', strings, numStrings));
    alphabet[5]  = (countChar('f',strings, numStrings) + countChar('F', strings, numStrings));
    alphabet[6]  = (countChar('g',strings, numStrings) + countChar('G', strings, numStrings));
    alphabet[7]  = (countChar('h',strings, numStrings) + countChar('H', strings, numStrings));
    alphabet[8]  = (countChar('i',strings, numStrings) + countChar('I', strings, numStrings));
    alphabet[9]  = (countChar('j',strings, numStrings) + countChar('J', strings, numStrings));
    alphabet[10] = (countChar('k',strings, numStrings) + countChar('K', strings, numStrings));
    alphabet[11] = (countChar('l',strings, numStrings) + countChar('L', strings, numStrings));
    alphabet[12] = (countChar('m',strings, numStrings) + countChar('M', strings, numStrings));
    alphabet[13] = (countChar('n',strings, numStrings) + countChar('N', strings, numStrings));
    alphabet[14] = (countChar('o',strings, numStrings) + countChar('O', strings, numStrings));
    alphabet[15] = (countChar('p',strings, numStrings) + countChar('P', strings, numStrings));
    alphabet[16] = (countChar('q',strings, numStrings) + countChar('Q', strings, numStrings));
    alphabet[17] = (countChar('r',strings, numStrings) + countChar('R', strings, numStrings));
    alphabet[18] = (countChar('s',strings, numStrings) + countChar('S', strings, numStrings));
    alphabet[19] = (countChar('t',strings, numStrings) + countChar('T', strings, numStrings));
    alphabet[20] = (countChar('u',strings, numStrings) + countChar('U', strings, numStrings));
    alphabet[21] = (countChar('v',strings, numStrings) + countChar('V', strings, numStrings));
    alphabet[22] = (countChar('w',strings, numStrings) + countChar('W', strings, numStrings));
    alphabet[23] = (countChar('x',strings, numStrings) + countChar('X', strings, numStrings));
    alphabet[24] = (countChar('y',strings, numStrings) + countChar('Y', strings, numStrings));
    alphabet[25] = (countChar('z',strings, numStrings) + countChar('Z', strings, numStrings));

    printf("A=%d\tB=%d\tC=%d\tD=%d\tE=%d\tF=%d\tG=%d\n",alphabet[0],alphabet[1],alphabet[2],alphabet[3],alphabet[4],alphabet[5],alphabet[6]);
    printf("H=%d\tI=%d\tJ=%d\tK=%d\tL=%d\tM=%d\tN=%d\n",alphabet[7],alphabet[8],alphabet[9],alphabet[10],alphabet[11],alphabet[12],alphabet[13]);
    printf("O=%d\tP=%d\tQ=%d\tR=%d\tS=%d\tT=%d\tU=%d\n",alphabet[14],alphabet[15],alphabet[16],alphabet[17],alphabet[18],alphabet[19],alphabet[20]);
    printf("V=%d\tW=%d\tX=%d\tY=%d\tZ=%d",alphabet[21],alphabet[22],alphabet[23],alphabet[24],alphabet[25]);

}

int countWords(char *strings[], int numStrings){
    int totalWords = 0;
    int i;
    char *ptr = NULL;
    char tempString[256];

    for(i = 0; i < numStrings; i++) {
        strcpy(tempString, strings[i]);
        ptr = strtok(tempString, " ");

        while (ptr != NULL) {
            totalWords++;
            ptr = strtok(NULL, " ");
        }
    }

    return totalWords;
}

void startsWithB(char *strings[], int numStrings){
    int i;
    char tempString[256];

    for(i = 0; i < numStrings; i++) {
        strcpy(tempString, strings[i]);
        if(*tempString == tolower('B') || *tempString == toupper('B')){
            printf("\t%s\n", tempString);
        }
    }
}

void endsWithed(char *strings[], int numStrings){
    int i;

    for(i = 0; i < numStrings; i++){
        if(strstr(strings[i], "ed\0") != NULL){
            printf("\t%s\n", strings[i]);
        }
    }
}