// Tickets.c
#include "Tickets.h"
#include "../Account/Account.h"

// Inclusion of libraries
#include <stdio.h>
#include <string.h>
#include <time.h> // For obtaining the current date

// Function to print a ticket
void PrintTicket(char OperationType, Account *Account, double amount) {
  static int numSerie = 0; // Static variable for the serial number

  // Increment the serial number for each operation
  numSerie++;

  // Get the current date and time
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  printf("\n");
  printf("==================Ticket==================\n");
  printf("Serial number: %c-%06d\n", OperationType, numSerie);

  printf("Type of operation: %s\n",
         OperationType == 'D'
             ? "Deposit"
             : (OperationType == 'R' ? "Withdrawal" : "Transfer"));

  printf("Account number 1: %s\n", Account->AccountID);

  
  printf("Amount: %.2f\n", amount);
  printf(
      "Date and time: %02d/%02d/%d %02d:%02d:%02d\n", tm->tm_mday,
      tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour + 6, tm->tm_min,
      tm->tm_sec); // Add 1 to "tm->tm_mon + 1" because months start at 0 for January
                   // ending at 11 for December, so it is corrected to make 1 January
                   // and end at 12 for December; Add 1900 to "tm->tm_year + 1900"
                   // to show the year from 1900 (0) onwards, as this is where the library
                   // starts counting the years elapsed; Add 6 to "tm->tm_hour + 6" 
                   // to show the time in the GMT-6 time zone
  printf("==========================================\n");
  printf("\n");
}