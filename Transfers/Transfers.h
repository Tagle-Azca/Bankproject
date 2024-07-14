// Transfers.h
#ifndef Transfers_H
#define Transfers_H
#include  "../Account/Account.h"

void TransfersAccount(Card *origin, Card *destination, double amount);

void TransferExternalBank(Card *origin, const char *DestinationName, double amount);

#endif