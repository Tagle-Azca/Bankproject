#include "../Account/Account.h" 
#include "../Tickets/Tickets.h"
#include <ctype.h> 
#include <stdio.h>
#include <string.h> 

void lBuffer() {
  int c;
  while ((c = getchar()) != '\n' &&
        c != EOF) { 
  }
}

void trim(char *str) {
  char *p = str;
  int l = strlen(p);

  while (isspace(p[l - 1]))
    p[--l] = 0; 
  while (*p && isspace(*p))
    ++p, --l; 

  memmove(str, p, l + 1); 
}

void Depositar(Account *Account, char *CardNumber, double amount) {
  printf("Store main card: '%s'\n", Account->MainCard.ID);
  printf("Store Secondary Card: '%s'\n", Account->SecondaryCard.ID);
  printf("Card ingresada: '%s'\n", CardNumber);

  if (strcmp(Account->MainCard.ID, CardNumber) == 0) {
    Account->MainCard.Balance += amount;
    PrintTicket('D', Account, amount);
    printf("Deposit was succesfull on the principal Card.\n");
  } else if (strcmp(Account->SecondaryCard.ID, CardNumber) == 0) {
    Account->SecondaryCard.Balance += amount;
    PrintTicket('D', Account, amount);
    printf("Deposit was succesfull on the secondary Card.\n");
  } else {
    printf("The card number does not match any card associated with this account.\n");
  }
}

