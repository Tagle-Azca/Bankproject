#include "Rendimientos.h"

double CalcularRendimiento(double saldoInicial, int meses) {
    double saldo = saldoInicial;
    double tasaInteresMensual = 0.035 / 12.0; // Tasa de interés mensual del 3.5% anual

    for (int i = 0; i < meses; i++) {
        saldo += saldo * tasaInteresMensual;
    }

    return saldo;
}