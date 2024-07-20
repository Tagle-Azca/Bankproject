// Expenses.c
#include "Expenses.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MONTH_DAYS 30
#define NUMBER_OF_CARDS 2

double Expenses[NUMBER_OF_CARDS][MONTH_DAYS];

void StartExpenses() {
    srand(time(NULL));
    for (int i = 0; i < NUMBER_OF_CARDS; i++) {
        for (int j = 0; j < MONTH_DAYS; j++) {
            Expenses[i][j] = (double)(rand() % 1000);
        }
    }
}

void ShowReportsOfExpenses() {
    printf("Monthly Expenses Report:\n");
    for (int i = 0; i < NUMBER_OF_CARDS; i++) {
        double MonthTotal = 0;
        printf("Card %d:\n", i + 1);
        for (int j = 0; j < MONTH_DAYS; j++) {
            printf("Dia %02d: $%.2f\n", j + 1, Expenses[i][j]);
            MonthTotal += Expenses[i][j];
        }
        printf("monthly total expenses %d: $%.2f\n\n", i + 1, MonthTotal);
    }
}
