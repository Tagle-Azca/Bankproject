#include "../Cuenta/Cuenta.h" 
#include "../Tickets/Tickets.h"
#include <ctype.h> // Para isspace
#include <stdio.h>
#include <string.h> 

void lBuffer() {
  int c;
  while ((c = getchar()) != '\n' &&
        c != EOF) { 
  }
}

void trim(char *str) {
  char *p = str;
  int l = strlen(p);

  while (isspace(p[l - 1]))
    p[--l] = 0; 
  while (*p && isspace(*p))
    ++p, --l; 

  memmove(str, p, l + 1); 
}

void Depositar(Cuenta *cuenta, char *numeroTarjeta, double monto) {
  printf("Tarjeta almacenada Principal: '%s'\n", cuenta->TarjetaPrincipal.ID);
  printf("Tarjeta almacenada Secundaria: '%s'\n", cuenta->TarjetaSecundaria.ID);
  printf("Tarjeta ingresada: '%s'\n", numeroTarjeta);

  if (strcmp(cuenta->TarjetaPrincipal.ID, numeroTarjeta) == 0) {
    cuenta->TarjetaPrincipal.Saldo += monto;
    imprimeTicket('D', cuenta, monto);
    printf("Deposito realizado en la tarjeta Principal.\n");
  } else if (strcmp(cuenta->TarjetaSecundaria.ID, numeroTarjeta) == 0) {
    cuenta->TarjetaSecundaria.Saldo += monto;
    imprimeTicket('D', cuenta, monto);
    printf("Deposito realizado en la tarjeta Secundaria.\n");
  } else {
    printf("El número de tarjeta no coincide con ninguna tarjeta asociada a esta cuenta.\n");
  }
}