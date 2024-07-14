//Account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H


typedef struct{
  char ID[21];
  double Balance;
  char ExpDate[6];
  char cvv[4];
} Card;

typedef struct{
  char AccountID[21];
  Card MainCard;
  Card SecondaryCard;
  Card creditCard;  
  char AccountN[30];
} Account;

void StartAccount(Account *account);
#endif