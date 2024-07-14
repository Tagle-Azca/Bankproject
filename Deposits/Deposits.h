// Deposits.h

#ifndef Deposits_H
#define Deposits_H

//Inclucion de librerias
#include<stdio.h>
#include <string.h>

//Se incluyen los archivosde funciones 
#include "../Account/Account.h"

// Función para realizar un depósito en una Card
void Depositar(Account *Account, char *CardNumber, double amount);

#endif