#include "Client.h"

int verificar(Cliente *b, char *h) {
	Cliente *p = b;

	while (p != NULL){
		if (strcmp(h, p->CI) == 0)
			return 1;
		else
			p = p->prox;
	}

	return 0;
}

int verificarBanco(Banco *b, char *v){
	Banco *p = b;

	while(p != NULL){
	
		if (strcmp(v, p->BankCode) == 0)
			return 1;
		else
			p = p->prox;
	}

	return 0;
}

int verificarb(Cuenta *b, char *nume) {
	Cuenta *d = b;

	while (d)
		if ((strcmp(d->AccountNumber, nume) == 0))
			return 1;
		else
			d = d->prox;

	return 0;
}

int verificarNc(Cuenta *c, char *Account) {
	Cuenta *p = c;

	while (p != NULL){
		if ((strcmp(Account, p->AccountNumber) == 0))
			return 1;
		else
			p = p->prox;
	}

	return 0;
}