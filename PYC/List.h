#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>


struct Banco {
	char BankCode[5];
	char Nombre[40];

	Banco  *prox;
};

struct Transaccion {
	long int OperationCode;
	int Dia;
	int mes;
	int year;
	int hora;
	int minuto;
	char Description[40];
	char CIE[9];
	char CIR[9];
	char NCuentR[15];
	char NCuentE[15];

	long int monto;
	Transaccion *prox;
};

struct Cuenta {
	char BankCode[5];
	char TipoC[3];
	char AccountNumber[15];
	char CI[9];
	char TipoT[3];

	long int Saldo;

	Banco  *Banks;
	Cuenta *prox;
	Transaccion *trans;
};

struct Cliente {
	char CI[9];
	char FirstNames[50];
	char LastNames[50];
	char Direction[100];
	char TelephoneNumber[13];

	Cuenta *cuen;
	Cliente *prox;
};