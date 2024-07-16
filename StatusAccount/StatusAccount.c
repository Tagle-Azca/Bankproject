#include <stdio.h>
#include "../Account/Account.h"

//Structure of the ticket
void StatusAccount(Account *Account){
    printf("*******Status of the Account *******\n");
    printf("\nOwner of the Account: \n%s\n", Account->AccountN);
    printf("\nID of the Account: \n%s\n", Account->AccountID);
    printf("\nbalance: \n%.2f\n", Account->MainCard.Balance);
    printf("\nPrincipal Account: \n%s\n", Account->MainCard.ID);
}