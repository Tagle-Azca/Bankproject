# Description

BancoApp is a terminal application developed in C for managing banking operations. This project simulates a banking platform that allows users to perform various transactions and inquiries related to their accounts. It is designed to run in a command-line environment.

```
Features

•	Account Management: Create, update, and query bank accounts.
•	Bank Transactions: Perform deposits, withdrawals, and transfers between accounts.
•	Account Status Inquiries: Check account status and get transaction details.
•	Card Management: Handle information for primary and secondary cards, as well as credit cards.
•	Ticket Generation: Issue tickets with the details of completed transactions.
•	Yield Calculation: Calculate financial yields based on the account balance.
•	Expense Control: Record and query expenses made with the cards.
```

```
## Project Structure

BancoApp/
├── BancoMain.c
├── Account/
│ ├── Account.c
│ └── Account.h
├── withdrawals/
│ ├── withdrawals.c
│ └── withdrawals.h
├── Expenses/
│ ├── Expenses.c
│ └── Expenses.h
├── Deposits/
│ ├── Deposits.c
│ └── Deposits.h
├── withdrawals/
│ ├── withdrawals.c
│ └── withdrawals.h
├── Consultas/
│ ├── Consultas.c
│ └── Consultas.h
├── Tickets/
│ ├── Tickets.c
│ └── Tickets.h
├── Transfers/
│ ├── TransferenciaAccount.c
│ ├── TransfersBanco.c
│ └── Transfers.h
└── StatusAccount/
├── StatusAccount.c
└── StatusAccount.h
```

## This project utilizes a Makefile for automating the compilation process. To compile the project, simply run make in your terminal. Ensure you have all necessary dependencies installed beforehand,to compile use the following command:

make

Clean generated files:

make clean

## Usage

To run the application, simply use the following command:

./bin/BankProject

## Contributions

I will love any help so, any contributions are welcome. if you wish to contibute please open an issue or create a pull request with you changes.

# Creator

## Andres Gomez Tagle Azcarraga
