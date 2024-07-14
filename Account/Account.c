// Account.c
#include "Account.h"
#include <string.h>

void StartAccount(Account *account) {
    // ID de la Account
    strcpy(account->AccountID, "739678");
    strcpy(account->AccountN, "Andres Gomez Tagle Azcarraga");

    // Estructura de la Card principal
    // Banco Santander
    strcpy(account->MainCard.ID, "5579 0990 1212 0506");
    account->MainCard.Balance = 165689.09;  // Ajusta este valor según sea necesario
    strcpy(account->MainCard.ExpDate, "03/27");
    strcpy(account->MainCard.cvv, "056");

    // Estructura de la Card secundaria
    strcpy(account->SecondaryCard.ID, "5579 0990 2121 0605");
    account->SecondaryCard.Balance = 0.00;
    strcpy(account->SecondaryCard.ExpDate, "05/30");
    strcpy(account->SecondaryCard.cvv, "192");

    strcpy(account->creditCard.ID, "5665 1009 7843 2525");
    account->creditCard.Balance = 0.00;
    strcpy(account->creditCard.ExpDate, "11/26");
    strcpy(account->creditCard.cvv, "010");
}