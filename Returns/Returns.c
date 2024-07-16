#include "Returns.h"

//investment returns
double CalculateReturns(double balance, int Months) {
    double Balance = Balance;
    double InterestRate = 0.035 / 12.0; // Tasa de interés mensual del 3.5% anual

    for (int i = 0; i < Months; i++) {
        Balance += Balance * InterestRate;
    }

    return Balance;
}