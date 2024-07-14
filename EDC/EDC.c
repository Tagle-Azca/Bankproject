#include <stdio.h>
#include "../Account/Account.h"

void StatusAccount(Account *Account){
    printf("*******Status of the Account *******\n");
    printf("Name de Account: %s\n", Account->AccountN);
    printf("ID de Account: %s\n", Account->AccountID);
    printf("balance: %.2f\n", Account->MainCard.Balance);
    printf("Account principal: %s\n", Account->MainCard.ID);
}