/*
*
* Name: Brian Luckenbill
* Date: February 10 2017
* Course: CIS2107
* Homework Number: Lab02 "Revenue"
*
* Write a C program called revenue to calculate the revenue from a sale based
* on the unit price and quantity of a product input by the user.
*
*/


#include<stdio.h>
#include<stdlib.h>


int main(void){
	int quantity;
	float price, discount;

	printf("\n");
	printf("Welcome To \"Temple\" store\n");
	printf("\n");

	//Get user input for Item price
	printf("\tEnter item price: ");
	scanf("%f", &price);

	//If the item price input is 0 or less display a message and exit the program
	if(price <= 0){
		printf("\n");
		printf("\tThis is not a valid item price.\n");
		printf("\tPlease run the program again\n");
		printf("\n");
		printf("Thank you for using \"Temple Store\"\n");
		printf("\n");
		exit(0);
	}

	//Get the user input for Quantity
	printf("\tEnter quantity: ");
	scanf("%d", &quantity);

	//If the Quantity input is 0 or less display a message and exit the program
	if(quantity <= 0){
		printf("\n");
		printf("\tThis is not a valid quantity order.\n");
		printf("\tPlease run the program again\n");
		printf("\n");
		printf("Thank you for using \"Temple Store\"\n");
		printf("\n");
		exit(0);
	}

	//Set the discount dependant on quanity entered
	if(quantity < 50){
		discount = 0;
	} else if(quantity < 99 && quantity >= 50){
		discount = 10;
	} else if(quantity < 149 && quantity > 99){
		discount = 15;
	} else {
		discount = 25;
	}

	//print the output and calculate discount and prices
	printf("\n");
	printf("\tThe item price is: $%.1f\n", price);
	printf("\tThe order is: %d item(s)\n", quantity);
	printf("\tThe cost is: $%.1f\n", (price * quantity));
	printf("\tThe discount is: %.1f%%\n", discount);
	printf("\tThe discount amount is: $%.1f\n", ((price * quantity) / (discount)));
	printf("\tThe total is: $%.1f\n", ((price * quantity) - ((price * quantity) / discount)));
	printf("\n");
	printf("Thank you for using \"Temple\" Store\n");
	printf("\n");

}
