/**
 * Name: Brian Luckenbill
 * TUID: 915149546
 * Date: February 16 2017
 * Course: CIS2107
 * Section: 003
 * Homework Number: 3 "ATM"
 *
 * Objective: Write a C Program for an ATM machine by implementing functions
 */

#include<stdio.h>
#include<stdlib.h>

#define WITHDRAWMAX 1000
#define DEPOSITMAX 10000

struct Account {
    int pin; //User login pin
    char *holderName; //Account owner's name
    float balance; //Current account balance
    int transactions; //Number of transactions (withdrawals/deposits) performed
    int requestReceipt; //1 if the user would like to get receipts with each transaction else 0
    struct Limits {
        int withdrawn; //Current daily amount withdrawn from the accouont
        int deposited; //Current daily amount deposited into account
        int withdrawMax; //Max amount that the account can withdraw per day
        int depositMax; //Max amount that the account can deposit per day
        int loginAttempts; //Max amount of login attempts that this account can try before a failed login
    } Daily;
};

/**
 * @fn void MainMenuDisplay()
 *
 * @brief Displays a list of transactions that the ATM can do
 */
void MainMenuDisplay();

/**
 * @fn void ReceiptDisplay(struct Account *const account)
 * @brief Displays the balance of an account as well as the daily limits
 *
 * @param Account account to display
 */
void BalanceDisplay(const struct Account *const account);

/**
 * @fn void ReceiptDisplay(struct Account *const account)
 * @brief Displays a receipt for a transaction, which is just the current account balance
 *
 * @param Account account the account to be shown
 */
void ReceiptDisplay(const struct Account *const account);

/**
 * @fn void Withdrawal(struct Account *const account)
 * @brief Prompts the user for an amount to withdraw from thier account and then
 *        checks it using IsValidWithdrawl
 *
 * @param Account the account to be withdrawn from
 */
void Withdrawal(struct Account *const account);

/**
 * @fn IsValidWithdrawl(float withdrawalInput, const struct Account *const account)
 * @brief Takes a number and an account and checks if the number is a valid amount
 *        that can be withdrawn from the account
 *
 * @param float withdrawalInput amount to withdrawn
 * @param Account account the account to check against
 *
 * @return 1 if the withdrawalInput passes the checks and is a valid amount, else 0
 */
int IsValidWithdrawl(float withdrawalInput, const struct Account *const account);

/**
 * @fn void Deposit(struct Account *const account)
 * @brief Prompts the user for an amount to deposit in to thier account and then
 *        checks it using IsValidDeposit
 *
 * @param Account the account to be deposited to
 */
void Deposit(struct Account *const account);

/**
 * @fn IsValidDeposit(float depositInput, const struct Account *const account)
 * @brief Takes a number and an account and checks if the number is a valid amount
 *        that can be deposited in to the account
 *
 * @param float depositInput amount to deposited
 * @param Account account the account to check against
 *
 * @return 1 if the depositInput passes the checks and is a valid amount, else 0
 */
int IsValidDeposit(float depositInput, const struct Account *const account);


int main() {
  int userInput;
  int userPinAttempts = 0;
  //create testing account for 'Nana'
  struct Account account;

  //Set account default values
  account.pin = 3014;
  account.holderName = "Nana";
  account.balance = 5000.00;
  account.transactions = 0;
  account.requestReceipt = 0;
  account.Daily.withdrawn = 0;
  account.Daily.deposited = 0;
  account.Daily.withdrawMax = WITHDRAWMAX;
  account.Daily.depositMax = DEPOSITMAX;
  account.Daily.loginAttempts = 3;

  printf("\nWelcome to the ATM %s, please enter your PIN.\n", account.holderName);

  //prompt user for thier account PIN, if thier account login attempts is exceeded exit program
  while(1) {
    printf("Please enter your PIN: ");
    scanf("%d", &userInput);

    //Breaks out of the loop if correct account PIN has been entered
    if(userInput == account.pin) {
      printf("\n");
      break;
    }

    userPinAttempts++;

    //Checks if amount of login attempts has been reached
    if(userPinAttempts == account.Daily.loginAttempts) {
      printf("\nAmount of login attempts exceeded. Exiting..\n\n");
      exit(0);
    }

    printf("Wrong PIN entered. %d Attempts remaining.\n", account.Daily.loginAttempts - userPinAttempts);
  }

  //Prompt user with choice if they would like receipts with thier transactions
  while(1) {
    printf("Would you like a receipt for all your transactions?\n");
    printf("\t1. Yes\n");
    printf("\t2. No\n");
    printf("\nSelection: ");
    scanf("%d", &userInput);

    if(userInput == 1) {
      account.requestReceipt = 1;
      break;
    }
    else if(userInput == 2) {
      account.requestReceipt = 0;
      break;
    }

    printf("\n");
  }

  //Displays list of options and then runs apropriate action based on a valid input
  do {
    MainMenuDisplay();
    scanf("%d", &userInput);
    printf("\n");

    if(userInput == 1) {
      BalanceDisplay(&account);
      account.transactions += 1;
    }
    else if(userInput == 2) {
      Withdrawal(&account);
    }
    else if (userInput == 3) {
      Deposit(&account);
    }
  } while(userInput != 4);

  printf("\nThank you for using the ATM");
  printf("\nNumber of transactions: %d", account.transactions);
  printf("\n");

  //If the user wanted transaction receipts, print final receipt
  if(account.requestReceipt) {
      ReceiptDisplay(&account);
  }

  return 0;
}


void MainMenuDisplay() {

  printf("\nThe types of ATM transaction are:\n");
  printf("\t1. Balance.\n");
  printf("\t2. Cash Withdrawal.\n");
  printf("\t3. Cash Deposition.\n");
  printf("\t4. Quit.\n");
  printf("\nSelection: ");

}


void BalanceDisplay(const struct Account *const account) {
  int nameLength = sizeof(account->holderName) / sizeof(char);

  printf("------------------ %s's Account ------------------\n", account->holderName);
  printf("\tAccount Balance: $%.2f\n", account->balance);
  printf("\n");
  printf("\tDaily withdrawal limit used: $%d of $%d\n", account->Daily.withdrawn, account->Daily.withdrawMax);
  printf("\tDaily deposit limit used: $%d of $%d\n", account->Daily.deposited, account->Daily.depositMax);
  printf("----------------------------------------------------\n");

}


void ReceiptDisplay(const struct Account *const account) {

    printf("\n=============== Receipt ===============\n");
    printf("\n");
    printf("\tCurrent Balance: $%.2f\n", account->balance);
    printf("\n");
    printf("=======================================\n");

}


void Withdrawal(struct Account *const account) {
  float withdrawalInput;

  //Checks if the daily withdrawn amount has been reached
  if(account->Daily.withdrawn == account->Daily.withdrawMax) {
    printf("Daily withdrawal limit has been met.\n");
    return;
  }

  //Prompts the user for amount to be withdrawn, only continues if valid amount has been entered
  do {
    printf("How much would you like to withdraw in $20 increments: ");
    scanf("%f", &withdrawalInput);
  } while(!IsValidWithdrawl(withdrawalInput, account));

  printf("You successfully withdrew $%.0f.\n", withdrawalInput);

  account->balance -= withdrawalInput;

  //If the user wanted transaction receipts, print one
  if(account->requestReceipt) {
    ReceiptDisplay(account);
  }

  account->transactions += 1;
  account->Daily.withdrawn += withdrawalInput;

}


int IsValidWithdrawl(const float withdrawalInput, const struct Account *const account) {
  //Starts off as a valid amount and then gets set to 0 if it fails for any reason
  int isValid = 1;

  printf("\n");

  //Checks if number is negative
  if(withdrawalInput < 0) {
    printf("*** Withdrawal amount must be a positive number ***\n");
    isValid = 0;
  }

  //Checks if trying withdraw coins
  if(withdrawalInput > 0 && withdrawalInput < 1) {
    printf("*** Withdrawal amount must be cash only ***\n");
    isValid = 0;
  }

  //checks if there are trailing decimal places (coins) trying to be withdrawn
  if((withdrawalInput - (int) withdrawalInput) > 0 && (withdrawalInput - (int) withdrawalInput) < 1) {
    printf("*** Withdrawal amount must be cash only ***\n");
    isValid = 0;
  }

  //Checks if amount is greater than the amount available in the account
  if(withdrawalInput > account->balance) {
    printf("*** Withdrawal amount exceeds account balance ***\n");
    isValid = 0;
  }

  //Checks if the amount is a denomination of 20
  if(((int)withdrawalInput % 20)) {
    printf("*** Withdrawal amount must be a denomination of $20 ***\n");
    isValid = 0;
  }

  //Checks if the amount to withdraw is greater than the remaining daily limit on the account
  if(withdrawalInput > (account->Daily.withdrawMax - account->Daily.withdrawn)) {
    printf("*** Withdrawal amount exceeds daily withdrawl limit ***\n");
    isValid = 0;
  }

  return isValid;
}


void Deposit(struct Account *const account) {
  float depositInput;

  //Checks if the daily deposit limit has been reached already
  if(account->Daily.deposited == account->Daily.depositMax) {
    printf("Daily deposit limit has been met.\n");
    return;
  }

  //Prompts for user input and only continues if the amount is valid
  do {
    printf("How much would you like to deposit: ");
    scanf("%f", &depositInput);
  } while(!IsValidDeposit(depositInput, account));

  printf("You successfully deposited $%.0f.\n", depositInput);

  account->balance += depositInput;

  //If the user wanted a reciept for the transaction, print it
  if(account->requestReceipt) {
    ReceiptDisplay(account);
  }

  account->transactions += 1;
  account->Daily.deposited += depositInput;

}


int IsValidDeposit(const float depositInput, const struct Account *const account) {
  //Starts off as a valid amount and then gets set to 0 if it fails for any reason
  int isValid = 1;

  printf("\n");

  //Checks for coins
  if(depositInput > 0 && depositInput < 1) {
    printf("*** Cannot deposit coins into account ***\n");
    isValid = 0;
  }

  //Checks for trailing decimal places (coins)
  if((depositInput - (int) depositInput) > 0 && (depositInput - (int) depositInput) < 1) {
    printf("*** Cannot deposit coins into account ***\n");
    isValid = 0;
  }

  //Checks if negative number
  if(depositInput < 0) {
    printf("*** Cannot deposit a negative number ***\n");
    isValid = 0;
  }

  //Checks if amount deposited exceeds remaining daily limit of account
  if(depositInput > (account->Daily.depositMax - account->Daily.deposited)) {
    printf("*** Cannot deposit more than daily limit ***\n");
    isValid = 0;
  }

  return isValid;
}
