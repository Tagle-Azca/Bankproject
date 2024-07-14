// BancoMain.c

#include "Account/Account.h"
#include "Deposits/Deposits.h"
#include "Expenses/Expenses.h"
#include "Returns/Returns.h"
#include "Retiros/Retiros.h"
#include "Tickets/Tickets.h"
#include "Transfers/Transfers.h"
#include "EDC/EDC.h" 

// Inclucion de librerias
#include <stdio.h>
#include <string.h>
#include <time.h> // Para obtener la fecha actual


// Declaración de la función RequestExternalAccount
void RequestExternalAccount();



void CleanBuffer() {
  int c;
  while ((c = getchar()) != '\n' &&
         c != EOF) { /* descarta caracteres hasta el final de la línea */
  }
}

// Estructuras principal del codigo
int main() {

  Account account;
  // Inicializar la Account
  StartAccount(&account);
  int option;
  double amount;           // Variable para almacenar el amount
  char CardNumber[17]; // Variable para almacenar el número de Card
  //double amount;
  int TransferType;
  int Months;
  const char *AccountdestinationTicket;
  double MainCardBalance = account.MainCard.Balance;
  

  do {
    printf("\n**** Sistema Bancario ****\n");
    printf("1. Status of the Account\n");
    printf("2. Deposito\n");
    printf("3. Retiro\n");
    printf("4. Transferencia\n");
    printf("5. Retiros\n");
    printf("6. Expenses\n");
    printf("7. Salir\n");
    printf("Ingrese una opción: \n");
    if (scanf("%d", &option) != 1) {
      fprintf(stderr, "Entrada inválida. Por favor, introduzca un número.\n");
      while (getchar() != '\n')
        ;
      continue;
    }

    switch (option) {
    case 1:
        StatusAccount(&account);
      break;

    case 2:
      // Deposito
      printf("Ingrese el numero de Card (16 digitos): ");
      if (scanf("%s", CardNumber) != 1) {
        fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
        CleanBuffer();
        continue;
      }
      printf("Ingrese el amount a depositar: ");
      if (scanf("%lf", &amount) != 1) {
        fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
        CleanBuffer();
        continue;
      }
      Depositar(&account, CardNumber, amount);
      break;

    case 3:
      // Retiro
      printf("Ingrese el numero de Account (16 digitos): ");
      if (scanf("%16s", CardNumber) != 1) {
        fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
        continue;
      }
      printf("Ingrese el amount a retirar: ");
      if (scanf("%lf", &amount) != 1) {
        fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
        continue;
      }
      retiro(&account, CardNumber, amount);
      break;
    case 4:
      // Transfers
      printf("Seleccione el tipo de transferencia:\n");
      printf("1. Transferencia SPEI\n");
      printf("2. Transferencia entre Cards\n");
      printf("Ingrese opción: ");
      if (scanf("%d", &TransferType) != 1) {
        fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
        CleanBuffer();
        continue;
      }
      switch (TransferType) {
      case 1:
        // Transferencia SPEI
        printf("Ingrese el amount a transferir: ");
        if (scanf("%lf", &amount) != 1) {
          fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
          CleanBuffer();
          break; 
        }
        RequestExternalAccount();
        TransferExternalBank(&account.MainCard, AccountdestinationTicket,
                               amount);
        break;
      case 2:

        //Transfers between accounts
        printf("Ingrese el amount a transferir a Card secundaria: ");
        if (scanf("%lf", &amount) != 1) {
          fprintf(stderr, "Error en la entrada. Intente nuevamente.\n");
          break; 
        }
        TransfersAccount(&account.MainCard,
                               &account.SecondaryCard, amount);
        break;
      default:
        printf("Invalid option\n");
        break;
      }
      break; // Este break asegura salir del caso 4 y regresar al menú principal

    case 5:
      // Retiros
      Months = 12;
      double Returns = CalculateReturns(account.MainCard.Balance, Months);
                printf("Calculo de returns del 3.5 anual\n");
                printf("\nbalance después de 1 mes: %.2f\n", CalculateReturns(MainCardBalance, 1));
                printf("balance después de 6 Months: %.2f\n", CalculateReturns(MainCardBalance, 6));
                printf("balance después de 1 año: %.2f\n", CalculateReturns(MainCardBalance, 12));
                printf("balance después de 5 años: %.2f\n", CalculateReturns(MainCardBalance, 60));
                printf("balance después de 10 años: %.2f\n", CalculateReturns(MainCardBalance, 120));
                break;
    case 6:
      StartExpenses();
      showReportsOfExpenses();
      break;

    case 7:
      printf("Gracias :) regrese pronto\n");
      break;

    default:
      printf("option no valida, intente nuevamente. \n");
      break;
    }
  } while (option != 7);
  return 0;
}