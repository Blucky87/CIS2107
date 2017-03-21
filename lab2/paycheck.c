/*
*
* Name: Brian Luckenbill
* Date: February 10 2017
* Course: CIS2107
* Homework Number: Lab02 "Paycheck"
*
* Write a C program called paycheck to calculate the paycheck for a Temple employee based on
* the hourlySalary, weeklyTime(working for maximum of 40 hours) and overtime (working for more than 40 hours).
*
*/


#include<stdio.h>
#include<stdlib.h>

//Number used to calculate overtime
#define OT_RATE 1.5

int main (void){
    int employeeNumber;
    float hourlySalary, weeklyTime;

    printf("\n");
    printf("Welcome to \"TEMPLE UNIVERSITY RESOURCES\"\n");
    printf("\n");

    //Get user input for Employee Number
    printf("\tEnter Employee Number: ");
    scanf("%d", &employeeNumber);

    //If the Employee Number is 0 or less display a message and exit the program
    if(employeeNumber < 1){
        printf("\n");
        printf("\tThis is not a valid Employee Number.\n");
        printf("\tPlease run the program again\n");
        printf("\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        printf("\n");
        exit(0);
    }

    //Get user input for Hourly Salary
    printf("\tEnter Hourly Salary: ");
    scanf("%f", &hourlySalary);

    //If the Salary is less or equal to 0 display a message and exit program
    if(hourlySalary <= 0){
        printf("\n");
        printf("\tThis is not a valid hourly hourlySalary amount.\n");
        printf("\tPlease run the program again\n");
        printf("\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        printf("\n");
        exit(0);
    }

    //Get user input for Weekly weeklyTime worked
    printf("\tEnter Weekly Time: ");
    scanf("%f", &weeklyTime);

    //If Hours Worked is less or equal to 0 display a message and exit program
    if(weeklyTime <= 0){
        printf("\n");
        printf("\tThis is not a weekly time.\n");
        printf("\tPlease run the program again\n");
        printf("\n");
        printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        printf("\n");
        exit(0);
    }

    printf("\t==============================\n");

    //Calculate and store amount earned through overtime
    float overtimePay = (weeklyTime > 40) ? ((weeklyTime - 40) * (OT_RATE * hourlySalary)) : 0;

    //Calculate amount of regular pay
    float regularPay = (weeklyTime > 40) ? (40 * hourlySalary) : (weeklyTime * hourlySalary);

    //Output final results
    printf("\tEmployee #: %d\n", employeeNumber);
    printf("\tHourly Salary: $%.1f\n", hourlySalary);
    printf("\tWeekly Time: %.1f\n", weeklyTime);
    printf("\tRegular Pay: $%.1f\n", regularPay);
    printf("\tOvertime Pay: $%.1f\n", overtimePay);
    printf("\tNet Pay: $%.1f\n", regularPay + overtimePay);
    printf("\t==============================\n");
    printf("Thank you for using \"TEMPLE HUMAN RESOURCES\"\n");
    printf("\n");

}
