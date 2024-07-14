#include  "./Consultas.h"
#include <stdio.h>

void ConsultarAhorro(){
  printf("aqui van las consultas de las Accounts de ahorro\n");
  //aqui registraremos el dinero guardadoe en las Cards
}

void ConsultarCards(){
  printf("aqui van las consultas de las Cards si hay mas de una\n");

  //aqui pondremos las ds Cards de nuestra Account
}

void ConsultarInversiones(){
  printf("aqui van a ir las inversiones\n");

  //aqui pondre estimaciones de returns de un returns promedio de 3.5% y hacer los calculos dependiendo el tiempo seleccionado
}


void realizarConsulta(int tipoConsulta){
  switch(tipoConsulta){
    case 1:
      ConsultarAhorro(
        
      );
    break;

    case 2:
      ConsultarCards();
    break;

    case 3:
      ConsultarInversiones();
    break;

    default:
    printf("seleccion no valida\n");
  }
}