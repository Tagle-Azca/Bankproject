// Cuenta.c
#include "Cuenta.h"
#include <string.h>

void InicializarCuenta(Cuenta *cuenta) {
    // ID de la cuenta
    strcpy(cuenta->CuentaID, "739678");
    strcpy(cuenta->CuentaN, "Andres Gomez Tagle Azcarraga");

    // Estructura de la tarjeta principal
    // Banco Santander
    strcpy(cuenta->TarjetaPrincipal.ID, "5579 0990 1212 0506");
    cuenta->TarjetaPrincipal.Saldo = 165689.09;  // Ajusta este valor según sea necesario
    strcpy(cuenta->TarjetaPrincipal.FVencimiento, "03/27");
    strcpy(cuenta->TarjetaPrincipal.cvv, "056");

    // Estructura de la tarjeta secundaria
    strcpy(cuenta->TarjetaSecundaria.ID, "5579 0990 2121 0605");
    cuenta->TarjetaSecundaria.Saldo = 0.00;
    strcpy(cuenta->TarjetaSecundaria.FVencimiento, "05/30");
    strcpy(cuenta->TarjetaSecundaria.cvv, "192");

    strcpy(cuenta->TarjetaCredito.ID, "5665 1009 7843 2525");
    cuenta->TarjetaCredito.Saldo = 0.00;
    strcpy(cuenta->TarjetaCredito.FVencimiento, "11/26");
    strcpy(cuenta->TarjetaCredito.cvv, "010");
}