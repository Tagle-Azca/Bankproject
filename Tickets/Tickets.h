// Tickets.h
#ifndef TICKETS_H
#define TICKETS_H

// Inclucion de librerias
#include <stdio.h>
#include <string.h>

//Se incluyen los archivosde funciones 
#include "../Account/Account.h"

// Funcion para imprimir el ticket
void imprimeTicket(char tipoOperacion, Account *Account, double amount);

#endif
