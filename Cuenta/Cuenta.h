//Cuenta.h
#ifndef CUENTA_H
#define CUENTA_H


typedef struct{
  char ID[21];
  double Saldo;
  char FVencimiento[6];
  char cvv[4];
} Tarjeta;

typedef struct{
  char CuentaID[21];
  Tarjeta TarjetaPrincipal;
  Tarjeta TarjetaSecundaria;
  Tarjeta TarjetaCredito;  
  char CuentaN[30];
} Cuenta;

void InicializarCuenta(Cuenta *cuenta);
#endif