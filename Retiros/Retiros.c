#include "Retiros.h"
#include <string.h>
#include <stdio.h>

void retiro(Account *account, const char *CardNumber, double amount) {
    if (strcmp(account->MainCard.ID, CardNumber) == 0) {
        if (account->MainCard.Balance >= amount) {
            account->MainCard.Balance -= amount;
            printf("Withdrawal successful. New main card balance: %.2f\n", account->MainCard.Balance);
        } else {
            printf("Insufficient funds on the main card.\n");
        }
    } else if (strcmp(account->SecondaryCard.ID, CardNumber) == 0) {
        if (account->SecondaryCard.Balance >= amount) {
            account->SecondaryCard.Balance -= amount;
            printf("Withdrawal successful. New secondary card balance: %.2f\n", account->SecondaryCard.Balance);
        } else {
            printf("Insufficient funds on the secondary card.\n");
        }
    } else {
        printf("Card number not found.\n");
    }
}