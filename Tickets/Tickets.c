//Tickets.c
#include "Tickets.h"
#include "../Account/Account.h"

// Inclucion de librerias
#include <stdio.h>
#include <string.h>
#include <time.h> // Para obtener la fecha actual

// Funcion para imprimir un ticket
void imprimeTicket(char tipoOperacion, Account *Account, double amount) {
  static int numSerie = 0; // Variable esaica para el numero de serie

  // Incrementa el número de serie para cada operacion
  numSerie++;

  // obtener la fecha y hora actual
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  printf("\n");
  printf("==================Ticket==================\n");
  printf("Numero de serie: %c-%06d\n", tipoOperacion, numSerie);

  printf("Tipo de operación: %s\n",
         tipoOperacion == 'D'
             ? "Depósito"
             : (tipoOperacion == 'R' ? "Retiro" : "Transferencia"));

  printf("Numero de Account 1: %s\n", Account->AccountID);
  
  //Modificar para Transferencia
  /*if (tipoOperacion == 'T') {
    printf("Numero de Account 2: %s\n", Account->AccountIDdestination);
  }*/
  
  printf("Importe: %.2f\n", amount);
  // printf("balance: %.2f\n", encuentraAccount(numeroAccount1) -> balance);
  // Imprime la fecha y hora en el huso horario GMT-6 (hora estándar central de
  // América Central)
  printf(
      "Fecha y hora: %02d/%02d/%d %02d:%02d:%02d\n", tm->tm_mday,
      tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour + 6, tm->tm_min,
      tm->tm_sec); // se suma 1 en "tm->tm_mon + 1" debido a que los Months
                   // comienzan en 0 para enero terminando en 11 para diciembre,
                   // entonces se corrigue para que 1 sea enero y termine en 12
                   // para diciembre;  Se suman 1900 en "tm->tm_year + 1900"
                   // para que se muestre el año desde 1900 (0) en adelante que
                   // es de donde inicia la libreria a contar los años
                   // transcurridos; Se suman 6 en "tm->tm_hour +6" para que se
                   // muestre la hora en el huso horario GMT-6
  printf("==========================================\n");
  printf("\n");
}