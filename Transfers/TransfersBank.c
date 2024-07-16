// TransferenciaBanco.c

#include "Transfers.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Variables globales para los almacenes de datos
char AccountdestinationTicket[17];
char NameBancoTicket[15];
char DestinationTicketName[40];


void liBuffer() {
  int c;
  while ((c = getchar()) != '\n' &&
         c != EOF) { /* descarta caracteres hasta el final de la línea */
  }
}

int InputDestinationBank();

const char *Banks[] = {"BBVA",     "BaNamex",    "Santander", "HSBC",
                        "Banorte",  "Scotiabank", "Inbursa",   "Banco Azteca",
                        "Banregio", "NU"};
int BankNumber = sizeof(Banks) / sizeof(Banks[0]);

// Aqui pedimos el numero de la Account y el amount a transferir

int ItsNumersAccount(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i])) {
      return 0;
    }
  }
  return 1;
}

void RequestExternalAccount() {
  char buffer[30];
  int Valid;

  do {
    printf("Input the destination account (16 digits): \n");
    liBuffer();
    if (!fgets(buffer, sizeof(buffer), stdin)) {
      continue;
    }

    buffer[strcspn(buffer, "\n")] = 0;

    if (strlen(buffer) == 0) {
      printf("Error: There was no number on the input. Try again\n");
      continue;
    }

    if (sscanf(buffer, "%16s", AccountdestinationTicket) == 1 &&
        strlen(AccountdestinationTicket) == 16 &&
        ItsNumersAccount(AccountdestinationTicket)) {
      Valid = 1;
    } else {
      printf("Invalid account number, It must be a 16 digit number.\n");
      Valid = 0;
    }
  } while (!Valid);

  if (InputDestinationBank() == 0) {
    printf("The bank was succesfully selected \n");
  }
}

int InputDestinationBank() {
  char input[20];
  int ValidBank = 0;

  printf("Enter the destination bank: \n");
  for (int i = 0; i < BankNumber; i++) {
    printf("- %s\n", Banks[i]);
  }
  while (!ValidBank) {
    printf("Enter the destination Bank name: \n");
    if (fgets(input, sizeof(input), stdin) == NULL) {
      fprintf(stderr,
              "Error: name bank is incorrect, try again\n");
      continue;
    }
    // Eliminar el salto de línea al final del string
    input[strcspn(input, "\n")] = '\0';

    for (int i = 0; i < BankNumber; i++) {
      if (strcmp(Banks[i], input) == 0) {
        stpcpy(NameBancoTicket, input);
        ValidBank = 1;
        break;
      }
    }
    if (!ValidBank) {
      printf("Bank is not on the list. try again\n");
    }
  }
  return ValidBank;
}

int DestinationName() {
  char Name[35];
  int intentos = 0;
  while (intentos < 3) { // Limita el número de intentos
    printf("Ingrese el Name del destinatario: ");
    if (!fgets(Name, sizeof(Name), stdin)) {
      fprintf(stderr, "Error into reading the input. try again\n");
      continue;
    }
    Name[strcspn(Name, "\n")] = 0; // Elimina el salto de línea

    int longitud = strlen(Name);
    if (longitud < 2 || longitud > 30) {
      printf("The name must be a 2 to 30 caracters.\n");
    } else {
      int Valid = 1;
      for (int i = 0; i < longitud; i++) {
        if (!isalpha(Name[i]) && Name[i] != ' ' && Name[i] != '-') {
          printf("The name can only contain letters, spaces and hyphens\n");
          Valid = 0;
          break;
        }
      }
      if (Valid) {
        strcpy(DestinationTicketName, Name);
        return 1;
      }
    }
    intentos++;
  }
  printf("Maximum atemps reached.\n");
  return 0;
}

int ValidateTransfer() {
  char responses[5];
  do {
    printf("Do you wish to confirm the tranfer?: (yes|no)");
    if (fgets(responses, sizeof(responses), stdin) == NULL) {
      fprintf(stderr, "Error into reading the input please try again.\n");
      continue;
    }
    responses[strcspn(responses, "\n")] =
        0; // Elimina el salto de línea al final del string

    for (int i = 0; responses[i]; i++) {
      responses[i] = tolower((unsigned char)responses[i]);
    }
    if (strcmp(responses, "yes") == 0) {
      return 1;
    } else if (strcmp(responses, "no") == 0) {
      return 0;
    } else {
      printf("responses invalid,  Try again. \n");
    }
  } while (1);
}

void TransferExternalBank(Card *origin, const char *DestinationName,
                            double amount) {
  if (ValidateTransfer()) {
    if (origin->Balance >= amount) {
      origin->Balance -= amount;
      printf("Transfer of %.2f to Account %s in %s Was successful.\n",
             amount, AccountdestinationTicket, NameBancoTicket);
      // Aquí podrías añadir un log de la transacción
    } else {
      printf("Insufucient balance to performe the transfer.\n");
    }
  } else {
    printf("User cancel the transfer.\n");
  }
}


