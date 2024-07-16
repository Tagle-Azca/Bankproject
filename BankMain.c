// BancoMain.c

#include "Account/Account.h"
#include "Deposits/Deposits.h"
#include "Expenses/Expenses.h"
#include "Returns/Returns.h"
#include "Tickets/Tickets.h"
#include "Transfers/Transfers.h"
#include "StatusAccount/StatusAccount.h"

#include <stdio.h>
#include <string.h>
#include <time.h> 

void RequestExternalAccount();

void CleanBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { /* discard characters until end of line */
  }
}

// Main code structure
int main() {

  Account account;
  // Initialize the Account
  StartAccount(&account);
  int option;
  double amount;           // Variable to store the amount
  char CardNumber[17]; // Variable to store the card number
  //double amount;
  int TransferType;
  int Months;
  const char *AccountdestinationTicket;
  double MainCardBalance = account.MainCard.Balance;
  

  do {
    printf("\n**** Banking System ****\n");
    printf("1. Status of the Account\n");
    printf("2. Deposit\n");
    printf("3. Withdrawal\n");
    printf("4. Transfer\n");
    printf("5. Returns\n");
    printf("6. Expenses\n");
    printf("7. Exit\n");
    printf("Enter an option: \n");
    if (scanf("%d", &option) != 1) {
      fprintf(stderr, "Invalid input. Please enter a number.\n");
      while (getchar() != '\n')
        ;
      continue;
    }

    switch (option) {
    case 1:
        StatusAccount(&account);
      break;

    case 2:
      // Deposit
      printf("Enter the card number (16 digits): ");
      if (scanf("%s", CardNumber) != 1) {
        fprintf(stderr, "Input error. Please try again.\n");
        CleanBuffer();
        continue;
      }
      printf("Enter the amount to deposit: ");
      if (scanf("%lf", &amount) != 1) {
        fprintf(stderr, "Input error. Please try again.\n");
        CleanBuffer();
        continue;
      }
      Depositar(&account, CardNumber, amount);
      break;

    case 3:
      // Transfers
      printf("Select the type of transfer:\n");
      printf("1. SPEI Transfer\n");
      printf("2. Transfer between cards\n");
      printf("Enter option: ");
      if (scanf("%d", &TransferType) != 1) {
        fprintf(stderr, "Input error. Please try again.\n");
        CleanBuffer();
        continue;
      }
      switch (TransferType) {
      case 1:
        // SPEI Transfer
        printf("Enter the amount to transfer: ");
        if (scanf("%lf", &amount) != 1) {
          fprintf(stderr, "Input error. Please try again.\n");
          CleanBuffer();
          break; 
        }
        RequestExternalAccount();
        TransferExternalBank(&account.MainCard, AccountdestinationTicket, amount);
        break;
      case 2:

        // Transfers between accounts
        printf("Enter the amount to transfer to secondary card: ");
        if (scanf("%lf", &amount) != 1) {
          fprintf(stderr, "Input error. Please try again.\n");
          break; 
        }
        TransfersAccount(&account.MainCard, &account.SecondaryCard, amount);
        break;
      default:
        printf("Invalid option\n");
        break;
      }
      break; // This break ensures to exit case 4 and return to the main menu

    case 4:
      // Returns
      Months = 12;
      double returns = CalculateReturns(account.MainCard.Balance, Months);
                printf("Calculation of 3.5 annual returns\n");
                printf("\nBalance after 1 month: %.2f\n", CalculateReturns(MainCardBalance, 1));
                printf("Balance after 6 months: %.2f\n", CalculateReturns(MainCardBalance, 6));
                printf("Balance after 1 year: %.2f\n", CalculateReturns(MainCardBalance, 12));
                printf("Balance after 5 years: %.2f\n", CalculateReturns(MainCardBalance, 60));
                printf("Balance after 10 years: %.2f\n", CalculateReturns(MainCardBalance, 120));
                break;
    case 5:
      StartExpenses();
      showReportsOfExpenses();
      break;

    case 6:
      printf("Thank you :) Come back soon\n");
      break;

    default:
      printf("Invalid option, please try again. \n");
      break;
    }
  } while (option != 7);
  return 0;
}