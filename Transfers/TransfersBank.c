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
    printf("Ingrese el número de Account destination (16 dígitos): \n");
    liBuffer();
    if (!fgets(buffer, sizeof(buffer), stdin)) {
      // Manejar posible error de lectura
      continue;
    }
    // Eliminar el salto de línea al final del string
    buffer[strcspn(buffer, "\n")] = 0;

    if (strlen(buffer) == 0) {
      printf("No se ingresó ningún número. Intente de nuevo.\n");
      continue;
    }

    if (sscanf(buffer, "%16s", AccountdestinationTicket) == 1 &&
        strlen(AccountdestinationTicket) == 16 &&
        ItsNumersAccount(AccountdestinationTicket)) {
      Valid = 1;
    } else {
      printf("Número de Account inválido, debe ser de 16 números.\n");
      Valid = 0;
    }
  } while (!Valid);

  if (InputDestinationBank() == 0) {
    printf("Banco seleccionado correctamente\n");
  }
}

int InputDestinationBank() {
  char input[20];
  int ValidBank = 0;

  printf("Ingresar el banco del destination\n");
  for (int i = 0; i < BankNumber; i++) {
    printf("- %s\n", Banks[i]);
  }
  while (!ValidBank) {
    printf("Ingrese el Name del banco: \n");
    if (fgets(input, sizeof(input), stdin) == NULL) {
      fprintf(stderr,
              "Error al leer el Name del banco. Intente nuevamente.\n");
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
      printf("Banco no reconocido. por favor intentar de nuevo");
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
      fprintf(stderr, "Error al leer la entrada. Intente de nuevo.\n");
      continue;
    }
    Name[strcspn(Name, "\n")] = 0; // Elimina el salto de línea

    int longitud = strlen(Name);
    if (longitud < 2 || longitud > 30) {
      printf("El Name debe tener entre 2 y 30 caracteres.\n");
    } else {
      int Valid = 1;
      for (int i = 0; i < longitud; i++) {
        if (!isalpha(Name[i]) && Name[i] != ' ' && Name[i] != '-') {
          printf("El Name solo puede contener letras, espacios o guiones.\n");
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
  printf("Se han superado los intentos máximos.\n");
  return 0;
}

int ValidateTransfer() {
  char responses[5];
  do {
    printf("Desea Confirmar Transferencia (si/no): ");
    if (fgets(responses, sizeof(responses), stdin) == NULL) {
      fprintf(stderr, "Error al leer la entrada. Intente de nuevo.\n");
      continue;
    }
    responses[strcspn(responses, "\n")] =
        0; // Elimina el salto de línea al final del string

    for (int i = 0; responses[i]; i++) {
      responses[i] = tolower((unsigned char)responses[i]);
    }
    if (strcmp(responses, "si") == 0) {
      return 1;
    } else if (strcmp(responses, "no") == 0) {
      return 0;
    } else {
      printf("responses inválida, intente nuevamente. \n");
    }
  } while (1);
}

void TransferExternalBank(Card *origin, const char *DestinationName,
                            double amount) {
  if (ValidateTransfer()) {
    if (origin->Balance >= amount) {
      origin->Balance -= amount;
      printf("Transferencia de %.2f a Account %s en %s realizada con éxito.\n",
             amount, AccountdestinationTicket, NameBancoTicket);
      // Aquí podrías añadir un log de la transacción
    } else {
      printf("Balance insuficiente para realizar la transferencia.\n");
    }
  } else {
    printf("Transferencia cancelada por el usuario.\n");
  }
}


