// TransferenciaAccount.c

#include "./Transfers.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void TransfersAccount(Card *origin, Card *destination, double amount) {
    if (origin == NULL || destination == NULL) {
        printf("Error: Invalid card numbers.\n");
        return;
    }
    if (amount <= 0) {
        printf("Error: the ammount ned to be a positive number.\n");
        return;
    }
    if (origin->Balance >= amount) {
        origin->Balance -= amount;
        destination->Balance += amount;
        printf("Succesfull tranfer of $%.2f from the card %s to the Card %s.\n", amount, origin->ID, destination->ID);
    } else {
        printf("Insufficient balance on the card %s. Available balance is: $%.2f,required amount: $%.2f.\n", origin->ID, origin->Balance, amount);
    }

}
