# Description

BancoApp is a terminal application developed in C for managing banking operations. This project simulates a banking platform that allows users to perform various transactions and inquiries related to their accounts. It is designed to run in a command-line environment.

Features

    •	Account Management: Create, update, and query bank accounts.
    •	Bank Transactions: Perform deposits, withdrawals, and transfers between accounts.
    •	Account Status Inquiries: Check account status and get transaction details.
    •	Card Management: Handle information for primary and secondary cards, as well as credit cards.
    •	Ticket Generation: Issue tickets with the details of completed transactions.
    •	Yield Calculation: Calculate financial yields based on the account balance.
    •	Expense Control: Record and query expenses made with the cards.



   ```
### Project Structure

BancoApp/
├── BancoMain.c
├── Cuenta/
│ ├── Cuenta.c
│ └── Cuenta.h
├── Rendimientos/
│ ├── Rendimientos.c
│ └── Rendimientos.h
├── Gastos/
│ ├── Gastos.c
│ └── Gastos.h
├── Depositos/
│ ├── Depositos.c
│ └── Depositos.h
├── Retiros/
│ ├── Retiros.c
│ └── Retiros.h
├── Consultas/
│ ├── Consultas.c
│ └── Consultas.h
├── Tickets/
│ ├── Tickets.c
│ └── Tickets.h
├── Transferencias/
│ ├── Transferenciacuenta.c
│ ├── TransferenciasBanco.c
│ └── Transferencias.h
└── EDC/
├── EDC.c
└── EDC.h

    # To compile this code, use the following command:

    gcc BancoMain.c Rendimientos/Rendimientos.c Gastos/Gastos.c Cuenta/Cuenta.c Depositos/Depositos.c Retiros/Retiros.c Consultas/Consultas.c Tickets/Tickets.c Transferencias/Transferenciacuenta.c Transferencias/TransferenciasBanco.c EDC/EDC.c -o BancoApp

    # Usage
    To run the application, simply use the following command:

    ./BancoApp
    
    Contributions

    I will love any help so, any contributions are welcome. if you wish to contibute please open an issue or create a pull request with you changes.

    # Creator
    ## Andres GOMEZ TAGLE AZCARRAGA
