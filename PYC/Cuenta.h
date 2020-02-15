#include "Primitiva.h"

int vacio(Cuenta *c) {
	return(c == NULL);
}

void AgregarC(Cliente **CL, char *BankCode, char *CI, char *TypeAcc, char *Account, long int *AmountValue, char *NumertoT) {
	Cliente *p = *CL;
	Cuenta *e = new Cuenta;

	while (strcmp(CI, p->CI) != 0)
		p = p->prox;

	if (strcmp(TypeAcc, "03") == 0) {
		strcpy_s(e->AccountNumber, NumertoT);
		strcpy_s(e->CI, CI);
		strcpy_s(e->BankCode, BankCode);
		strcpy_s(e->TipoC, TypeAcc);
		e->Saldo = *AmountValue;
	}

	if (strcmp(TypeAcc, "02") == 0) {
		strcpy_s(e->CI, CI);
		strcpy_s(e->BankCode, BankCode);
		strcpy_s(e->TipoC, TypeAcc);
		strcpy_s(e->AccountNumber, Account);
		e->Saldo = *AmountValue;
	}
	if (strcmp(TypeAcc, "01") == 0) {
		strcpy_s(e->CI, CI);
		strcpy_s(e->BankCode, BankCode);
		strcpy_s(e->TipoC, TypeAcc);
		strcpy_s(e->AccountNumber, Account);
		e->Saldo = *AmountValue;
	}
	e->prox = p->cuen;
	p->cuen = e;
}
void eliminar(Cliente **h, Transaccion ** t,char ci[9]){
	Cliente *a;
	while(*t){a=*h;
	while(a){
		if(strcmp(a->CI,ci)){
		Cuenta *c=a->cuen;
		while(c){
			if(strcmp(c->AccountNumber,(*t)->NCuentE)
		}
		}
		a=a->prox;
	}
	Transaccion *d=*t;
	*t=(*t)->prox;
	delete(&d);
	}
}// no arreglado aun
void EliminarCuenta( Cliente **h, char *account) {
	Cliente *t = *h;
	Cuenta *v;
	while(t){v=t->cuen;
	if((v)&&(v->AccountNumber==account)){
		eliminar(h,&(v->trans),v->CI);
		t->cuen=t->cuen->prox;
		delete(&v);
	}
	while((v)&&(v->prox)&&(v->prox->AccountNumber!=account))
		v=v->prox;
	if(v)break;
	t=t->prox;
	}
	if(v){
		eliminar(h,&v->prox->trans,v->prox->CI);
		Cuenta *d=v->prox;
		v->prox=v->prox->prox;
		delete(&d);
	}
		printf_s("\n\n Su cuenta se ha eliminado con exito\n\n");
	}//no arreglado aun
void MostrarCuenta(Cuenta *c) {
	Cuenta *t = c;

	printf_s("------------------------CUENTAS------------------------\n ");
	while (!(vacio(t))) {
		printf_s("Tipo de cuenta: ");
		if (strcmp(t->TipoC, "02") == 0)
			printf_s("Ahorro\n");
		else if (strcmp(t->TipoC, "01") == 0)
			printf_s("Corriente\n");
		else if (strcmp(t->TipoC, "03") == 0)
			printf_s("tarjeta de credito\n");

		if (strcmp(t->TipoC, "03") == 0) {
			printf_s("Codigo de banco: ");
			printf_s("%s\n", t->BankCode);
			printf_s("tarjeta de credito: ");
			printf_s("%s\n", t->AccountNumber);
			printf_s("Cedula de identidad: ");
			printf_s("%s\n", t->CI);
			printf_s("Saldo: ");
			printf_s("%d\n", t->Saldo);
		}

		if (strcmp(t->TipoC, "02") == 0) {
			printf_s("Codigo de banco: ");
			printf_s("%s\n", t->BankCode);
			printf_s("Numero de cuenta: ");
			printf_s("%s\n", t->AccountNumber);
			printf_s("Cedula de identidad: ");
			printf_s("%s\n", t->CI);
			printf_s("Saldo: ");
			printf_s("%d\n", t->Saldo);
		}
		if (strcmp(t->TipoC, "01") == 0) {
			printf_s("Codigo de banco: ");
			printf_s("%s\n", t->BankCode);
			printf_s("Numero de cuenta: ");
			printf_s("%s\n", t->AccountNumber);
			printf_s("Cedula de identidad: ");
			printf_s("%s\n", t->CI);
			printf_s("Saldo: ");
			printf_s("%d\n", t->Saldo);
		}
		printf_s("-----------------------------------------------------\n\n");
		t = t->prox;
	}
	printf_s("\n");
}

void modAccount(Cuenta **C, Cliente **b, char *Account, char *Digits, char *digits2, long int *amount, char *l1, char *l2, char *l3) {
	if (strcmp(l1, "1") == 0) {
		Cuenta *Cuen = *C;
		Cliente *d = *b;
		char CardNumber[15];


		if (strcmp(Digits, "03") == 0) {
			printf_s("Agregue su tarjeta de credito\n");
			scanf_s("%s", CardNumber, 15);
			strcpy_s(Cuen->AccountNumber, CardNumber);
		}

		while ((strcmp(Cuen->AccountNumber, Account) != 0)) {
			Cuen = Cuen->prox;
		}

		while ((strcmp(Cuen->CI, d->CI) != 0)) {
			d = d->prox;
		}

		while ((strcmp(Cuen->AccountNumber, d->cuen->AccountNumber) != 0)) {
			d->cuen = d->cuen->prox;
		}

		strcpy_s(Cuen->TipoC, Digits);
		d->cuen = Cuen;
	}


	if (strcmp(l2, "1") == 0) {
		Cuenta *c = *C;
		Cliente *d = *b;

		while ((strcmp(c->AccountNumber, Account) != 0)) {
			c = c->prox;
		}

		while ((strcmp(c->CI, d->CI) != 0)) {
			d = d->prox;
		}

		while ((strcmp(c->AccountNumber, d->cuen->AccountNumber) != 0)) {
			d->cuen = d->cuen->prox;
		}
		c->Saldo = *amount;
		d->cuen = c;
	}


	if (strcmp(l3, "1") == 0) {
		Cuenta *c = *C;
		Cliente *d = *b;

		while ((strcmp(c->AccountNumber, Account) != 0)) {
			c = c->prox;
		}

		while ((strcmp(c->CI, d->CI) != 0)) {
			d = d->prox;
		}

		while ((strcmp(c->AccountNumber, d->cuen->AccountNumber) != 0)) {
			d->cuen = d->cuen->prox;
		}

		strcpy_s(c->BankCode, digits2);
		d->cuen = c;
	}
}