// TransferenciaAccount.c

#include "./Transfers.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void TransfersAccount(Card *origin, Card *destination, double amount) {
    if (origin == NULL || destination == NULL) {
        printf("Error: los datos de la Card no son válidos.\n");
        return;
    }
    if (amount <= 0) {
        printf("Error: el amount a transferir debe ser positivo.\n");
        return;
    }
    if (origin->Balance >= amount) {
        origin->Balance -= amount;
        destination->Balance += amount;
        printf("Transferencia exitosa de $%.2f de la Card %s a la Card %s.\n", amount, origin->ID, destination->ID);
    } else {
        printf("Balance insuficiente en la Card %s. Balance disponible: $%.2f, amount requerido: $%.2f.\n", origin->ID, origin->Balance, amount);
    }

}
