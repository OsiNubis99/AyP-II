#include "Cuenta.h"

int verificarC(Cuenta *c, char *CI) {
	Cuenta *d = c;

	while (d != NULL)
		if (strcmp(CI, d->CI) == 0)
			return 1;
		else
			d = d->prox;
	return (0);
}

int verificarT(Cuenta *c, char *NumberAccount, char *CI) {
	Cuenta *d = c;

	while (d != NULL)
		if ((strcmp(CI, d->CI) == 0) && ((strcmp(NumberAccount, d->AccountNumber) == 0)))
			return 1;
		else
			d = d->prox;
	return (0);
}

int VerificarCodeT(Transaccion *T, long int *number){
	Transaccion *d = T;

	while (d != NULL)
		if (d->OperationCode == *number)
			return 1;
		else
			d = d->prox;
	return (0);
}

void encuentra(Cuenta **C, Transaccion *t){
	Cuenta *d = *C;
	while ((strcmp(t->CIE, d->CI) != 0) && (strcmp(t->NCuentE, d->AccountNumber) != 0)) 
		d = d->prox;

	if((strcmp(d->TipoT, "01") == 0)){
		d->Saldo = d->Saldo + t->monto;
	}
	else{
		d->Saldo = d->Saldo - t->monto;
	}
}

void encuentraR(Cuenta **C, Transaccion *t){
	Cuenta *d = *C;
	while ((strcmp(t->CIR, d->CI) != 0) && (strcmp(t->NCuentR, d->AccountNumber) != 0)) 
		d = d->prox;

	if((strcmp(d->TipoT, "01") == 0)){
		d->Saldo = d->Saldo + t->monto;
	}
	else{
		d->Saldo = d->Saldo - t->monto;
	}
}

void EliminarTransac(Cuenta **C, Transaccion **T, long int *number){
	Transaccion *k = *T;
	Transaccion*g = k;

	while (k->OperationCode == *number) 
		k = k->prox;

	if(k->OperationCode == *number){
		encuentra(C,k);
		encuentraR(C,k);
		if (g == k) {
			*T = (*T)->prox;
			delete(k);
			printf_s("\n\n Su cuenta se ha eliminado con exito\n\n");
		}
		else {
			if (k->prox != NULL) {
				g = k;
				k = k->prox;
				delete (g);
				printf_s("\n\n Su cuenta se ha eliminado con exito\n\n");
			}
		}
	}
}

void MostrarTran(Transaccion *T){
	Transaccion *m = T;

	printf_s("------------------------TRANSACCIONES------------------------\n ");
	while (m != NULL) {
		printf_s("Codigo de transaccion: ");
		printf_s("%li\n", m->OperationCode);
		printf_s("Fecha: ");
		printf_s("%i/%i/%i\n", m->Dia,m->mes,m->year);
		printf_s("Hora: ");
		printf_s("%i:%i\n", m->hora,m->minuto);
		printf_s("Descripcion: ");
		printf_s("%s\n", m->Description);
		printf_s("Saldo: ");
		printf_s("%li\n", m->monto);
		printf_s("Cuenta Emisor: ");
		printf_s("%s\n", m->NCuentE);
		printf_s("Cuenta Receptor: ");
		printf_s("%s\n", m->NCuentR);
		printf_s("Cedula del emisor: ");
		printf_s("%s\n", m->CIE);
		printf_s("Cedula del receptor: ");
		printf_s("%s\n", m->CIR);
		printf_s("-----------------------------------------------------\n\n");
		m = m->prox;
	}
	printf_s("\n");
}

void Pago(Cuenta **C, long int *amount, char*CuentE, char*CIE){
	Cuenta *C1 = *C;

	while ((strcmp(CuentE, C1->AccountNumber) != 0) && (strcmp(CIE, C1->CI) != 0))
		C1 = C1->prox;

	C1->Saldo = C1->Saldo - *amount;
	strcpy_s(C1->TipoT, "01");

}

void Cobro( Cuenta **C, long int *amount, char*CuentR, char*CIR){
	Cuenta *C1 = *C;

	while ((strcmp(CuentR, C1->AccountNumber) != 0) && (strcmp(CIR, C1->CI) != 0))
		C1 = C1->prox;


	C1->Saldo = C1->Saldo + *amount;
	strcpy_s(C1->TipoT, "02");

}

void AsignarC(Transaccion **T, Cliente **CL, Cuenta **C, char *CI, char *Cuen){
	Cuenta *C1 = *C;
	Cliente *CLient = *CL;

	while ((strcmp(Cuen, C1->AccountNumber) != 0) && (strcmp(CI, C1->CI) != 0)){
		C1 = C1->prox;
	}

	while((strcmp(CLient->CI, CI) != 0)){
		CLient = CLient->prox;
	}

	while ((strcmp(CLient->cuen->AccountNumber, C1->AccountNumber) != 0)){
		CLient->cuen = CLient->cuen->prox;
	}

	(*T)->prox = C1->trans;
	C1->trans = *T;
	CLient->cuen->trans = *T;
}

void AsignarCA(Transaccion **T, Cliente **CL, Cuenta **C, char *CI, char *Cuen){
	Cuenta *C1 = *C;
	Cliente *CLient = *CL;

	while ((strcmp(Cuen, C1->AccountNumber) != 0) && (strcmp(CI, C1->CI) != 0))
		C1 = C1->prox;

	while((strcmp(CLient->CI, CI) != 0))
		CLient = CLient->prox;

	while ((strcmp(CLient->cuen->AccountNumber, C1->AccountNumber) != 0))
		CLient->cuen = CLient->cuen->prox;

	(*T)->prox = C1->trans;
	C1->trans = *T;
	CLient->cuen->trans = *T;
}

void Tranferencia(Cliente **CL, Cuenta **C, Transaccion **T, char *CIE, char *CIR, char *CuentE, char *CuentR, long int *Amount, char *description, int *dia, int *mes, int *year, int *hora, int  *minuto, long int *Codigo) {
	Cuenta *CAux = *C;
	Transaccion *TR = new Transaccion;
	Transaccion *Aux = *T;

	while ((strcmp(CuentE, CAux->AccountNumber) != 0) && (strcmp(CIE, CAux->CI) != 0))
		CAux = CAux->prox;

	if (CAux->Saldo >= *Amount) {
		Pago(C,Amount,CuentE,CIE);
		Cobro(C,Amount,CuentR,CIR);
		strcpy_s(TR->CIE, CIE);
		strcpy_s(TR->CIR, CIR);
		strcpy_s(TR->NCuentE, CuentE);
		strcpy_s(TR->NCuentR, CuentR);
		strcpy_s(TR->Description, description);
		TR->Dia = *dia;
		TR->mes = *mes;
		TR->year = *year;
		TR->hora = *hora;
		TR->minuto = *minuto;
		TR->monto = *Amount;
		TR->OperationCode = *Codigo;
		AsignarC(&TR,CL,C,CIE,CuentE);
		AsignarCA(&TR,CL,C,CIR,CuentR);

		TR->prox = Aux;
		*T = TR;
	}
	else
		printf_s("No tiene saldo suficiente.\n\n");
}