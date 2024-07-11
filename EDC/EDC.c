#include <stdio.h>
#include "../Cuenta/Cuenta.h"

void EstadoCuenta(Cuenta *cuenta){
    printf("*******Estado de cuenta *******\n");
    printf("nombre de cuenta: %s\n", cuenta->CuentaN);
    printf("ID de cuenta: %s\n", cuenta->CuentaID);
    printf("Saldo: %.2f\n", cuenta->TarjetaPrincipal.Saldo);
    printf("Cuenta principal: %s\n", cuenta->TarjetaPrincipal.ID);
}