#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <fstream>

bool archivoVacio(FILE *a) { //Retorna si el archivo esta o no vacio
	long desplazamiento = ftell(a);
	fseek(a, 0, SEEK_END);

	if (ftell(a) == 0)
		return true;

	fseek(a, desplazamiento, SEEK_SET);
	return false;
}

int verificarC(Cliente *CL, char CI[9]) {
	Cliente *D = CL;
	while (D)
		if (strcmp(D->CI, CI) == 0)
			return 1;
		else
			D = D->prox;
	return 0;
}

void AsignarC(Cliente **CL, Cuenta *c) {
	Cliente *v = *CL;
	Cuenta *d = c;

	while (strcmp(v->CI, d->CI) != 0)
		v = v->prox;

	d->prox = v->cuen;
	v->cuen = d;
}

void AsignarCE(Cliente **CL, Cuenta **c, Transaccion **t){
	Cliente *v = *CL;
	Cuenta *d = *c;
	Transaccion *tr = *t;


	while ((strcmp(d->CI, tr->CIE) != 0) && (strcmp(d->AccountNumber, tr->NCuentE) != 0))
		d = d->prox;

	while (strcmp(v->CI, tr->CIE) != 0)
		v = v->prox;

	while (strcmp(v->cuen->AccountNumber, tr->NCuentE) != 0)
		v->cuen = v->cuen->prox;

	tr->prox = d->trans;
	d->trans = tr;
	v->cuen = d;
}

void AsignarCR(Cliente **CL, Cuenta **c, Transaccion **t){
	Cliente *v = *CL;
	Cuenta *d = *c;
	Transaccion *tr = *t;


	while ((strcmp(d->CI, tr->CIR) != 0) && (strcmp(d->AccountNumber, tr->NCuentR) != 0))
		d = d->prox;

	while (strcmp(v->CI, tr->CIR) != 0)
		v = v->prox;

	while (strcmp(v->cuen->AccountNumber, tr->NCuentR) != 0)
		v->cuen = v->cuen->prox;

	tr->prox = d->trans;
	d->trans = tr;
	v->cuen = d;
}

void ArchivoCliente(Cliente *CL) {
	FILE *Clientes;
	Clientes = fopen("Cliente.txt", "w");
	Cliente *Aux = CL;

	while (Aux)	{
		fprintf_s(Clientes, "\n");
		fprintf_s(Clientes, "\n%s", Aux->CI);
		fprintf_s(Clientes, "\n%s", Aux->FirstNames);
		fprintf_s(Clientes, "\n%s", Aux->LastNames);
		fprintf_s(Clientes, "\n%s", Aux->Direction);
		fprintf_s(Clientes, "\n%s", Aux->TelephoneNumber);
		Aux = Aux->prox;
	}
	fclose(Clientes);
}

void ArchivoCuenta(Cliente *CL, Cuenta *C) {
	FILE *Cuentas;
	Cuenta *Aux = C;
	char straux[15] = "", AccountN[11] = "";
	Cuentas = fopen("Cuentas.txt", "w");

	while (Aux)	{
		fprintf_s(Cuentas, "\n");
		fprintf_s(Cuentas, "\n%s", Aux->BankCode);
		fprintf_s(Cuentas, "\n%s", Aux->AccountNumber);
		fprintf_s(Cuentas, "\n%s", Aux->TipoC);
		fprintf_s(Cuentas, "\n%s", Aux->TipoT);
		fprintf_s(Cuentas, "\n%s", Aux->CI);
		fprintf_s(Cuentas, "\n%li", Aux->Saldo);
		Aux = Aux->prox;
	}
	fclose(Cuentas);
}

void ArchivoTrans(Cliente *CL, Cuenta *C, Transaccion *T) {
	FILE *Transac;
	Cliente *AuxE = CL;
	Cuenta *AuxC = C;
	Transaccion *AuxT = T;

	char j[80] = "";
	Transac = fopen("Transac.txt", "w");

	while (AuxT) {
		fprintf_s(Transac, "\n");
		fprintf_s(Transac, "%li\n", AuxT->OperationCode);
		fprintf_s(Transac, "%s\n", AuxT->CIR);
		fprintf_s(Transac, "%s\n", AuxT->NCuentR);
		fprintf_s(Transac, "%s\n", AuxT->CIE);
		fprintf_s(Transac, "%s\n", AuxT->NCuentE);
		fprintf_s(Transac, "%s\n", AuxT->Description);
		fprintf_s(Transac, "%li\n", AuxT->monto);
		fprintf_s(Transac, "%d\n", AuxT->hora);
		fprintf_s(Transac, "%d\n", AuxT->minuto);
		fprintf_s(Transac, "%d\n", AuxT->Dia);
		fprintf_s(Transac, "%d\n", AuxT->mes);
		fprintf_s(Transac, "%d\n", AuxT->year);
		fprintf_s(Transac, "%s\n", j);
		AuxT= AuxT->prox;
	}
	fclose(Transac);
}

void LeerBancos(Banco **B) {
	FILE *Bancos;
	Bancos = fopen("Bancos.txt", "r");
	char k[100] = "";

	if ((Bancos) && (!(archivoVacio(Bancos)))) {
		while (!(feof(Bancos))) {
			if ((*B) == NULL) {
				*B = new Banco;
				fscanf(Bancos, "\n%s", &(*B)->BankCode);
				fscanf(Bancos, "%s", &(*B)->Nombre);
				(*B)->prox = NULL;
			}
			else if ((*B) != NULL) {
				Banco *PAux = new Banco;
				Banco *M = *B;
				while (M->prox != NULL)
					M = M->prox;

				fscanf(Bancos, "\n%s", &PAux->BankCode);
				fscanf(Bancos, "%s", &PAux->Nombre);
				PAux->prox = NULL;
				M->prox = PAux;
			}
		}
		fclose(Bancos);
	}
}

void LeerCliente(Cliente **CL) {
	FILE *Clientes;
	Clientes = fopen("Clientes.txt", "r");

	if ((Clientes) && (!(archivoVacio(Clientes)))) {
		while (!(feof(Clientes))) {
			if ((*CL) == NULL) {
				*CL = new Cliente;
				fscanf(Clientes, "\n%s", &(*CL)->CI);
				fscanf(Clientes, "%s", &(*CL)->FirstNames);
				fscanf(Clientes, "%s", &(*CL)->LastNames);
				fscanf(Clientes, "%s", &(*CL)->Direction);
				fscanf(Clientes, "%s", &(*CL)->TelephoneNumber);
				(*CL)->prox = NULL;
				(*CL)->cuen = NULL;
			}
			else if ((*CL) != NULL) {
				Cliente *PAux = new Cliente;
				Cliente *M = *CL;
				while (M->prox != NULL)
					M = M->prox;

				fscanf(Clientes, "\n%s", &PAux->CI);
				fscanf(Clientes, "%s", &PAux->FirstNames);
				fscanf(Clientes, "%s", &PAux->LastNames);
				fscanf(Clientes, "%s", &PAux->Direction);
				fscanf(Clientes, "%s", &PAux->TelephoneNumber);
				PAux->prox = NULL;
				PAux->cuen = NULL;
				M->prox = PAux;
			}
		}
		fclose(Clientes);
	}
}	  

void LeerCuentas(Cliente **CL,Banco *ban) {
	Cuenta *c;
	FILE *Cuentas;
	Cuentas = fopen("Cuentas.txt", "r");

	if ((Cuentas) && (!(archivoVacio(Cuentas)))) {
		while (!(feof(Cuentas))) {
				c = new Cuenta;
				fscanf(Cuentas, "\n%s", &c->CI);
				fscanf(Cuentas, "%s", &c->BankCode);
				fscanf(Cuentas, "%s", &c->TipoC);
				fscanf(Cuentas, "%s", &c->AccountNumber);
				fscanf(Cuentas, "%li", &c->Saldo);
				if (verificarC(*CL, c->CI) == 1){
					Cliente *v = *CL;
					while (strcmp(v->CI, c->CI))
					v = v->prox;
					c->prox= v->cuen;
					v->cuen = c;
				}
				c->trans = NULL;
				c->Banks = ban;
				}
	}
		fclose(Cuentas);
	}

void LeerTrans(Cliente **CL) {
	Transaccion *t;
	FILE *Transac;
	Transac = fopen("Transac.txt", "r");
	char j[80] = "", day[4] = "", a[2], k[8];
	if ((Transac) && (!(archivoVacio(Transac)))) {
		while (!(feof(Transac))){
				t = new Transaccion;
				fscanf(Transac, "\n%ld", &t->OperationCode);
				fscanf(Transac, "%s", &t->CIE);
				fscanf(Transac, "%s", &t->CIR);
				fscanf(Transac, "%s", &t->NCuentE);
				fscanf(Transac, "%s", &t->NCuentR);
				fscanf(Transac, "%s", &t->Description);
				fscanf(Transac, "%ld", &t->monto);
				fscanf(Transac, "%d", &t->hora);
				fscanf(Transac, "%d", &t->minuto);
				fscanf(Transac, "%d", &t->Dia);
				fscanf(Transac, "%d", &t->mes);
				fscanf(Transac, "%d", &t->year);
				if ((verificar(*CL,t->CIE) == 1) && (verificarC(*CL,t->CIR) == 1)){
					Cliente *a=*CL;
					while(a){
						if(strcmp(a->CI,t->CIE)==0){
							Cuenta *c=a->cuen;
							while(c){
								if(strcmp(c->AccountNumber,t->NCuentE)==0){
									t->prox=c->trans;
									c->trans=t;
									break;
								}
								c=c->prox;
							}
						}
						if(strcmp(a->CI,t->CIR)){
							Cuenta *c=a->cuen;
							while(c){
								if(strcmp(c->AccountNumber,t->NCuentR)==0){
									t->prox=c->trans;
									c->trans=t;
									break;
								}
								c=c->prox;
							}
						}
						a=a->prox;
					}
				}			
		}
		fclose(Transac);
	}
}



