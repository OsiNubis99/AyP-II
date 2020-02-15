#include "List.h"

int VerifyAdressB(Cliente *Bank, char *AdressB) {
	Cliente *pointBank = Bank;

	while ((strcmp(pointBank->Direction, AdressB) != 0))
		pointBank = pointBank->prox;

	if (pointBank)
		return 0;

	return 1;
}

int verifyNumber(char *CI){
	for(int i = 0; i < strlen(CI); i++){
		if(CI[i] < '0' || CI[i] > '9'){
			return 1;
		}
	}
	return 0;
}

int verificarCl(Cliente *CL, char *CI) {
	Cliente *c= CL;

	while (c){
		if ((strcmp(c->CI, CI) == 0))
			return 1;
		else
			c = c->prox;
	}

	return 0;
}

int verificarTelefono(Cliente *CL, char *Telefono) {
	Cliente *c= CL;

	while (c){
		if ((strcmp(c->TelephoneNumber, Telefono) == 0))
			return 1;
		else
			c = c->prox;
	}

	return 0;
}

void AgregarCliente(Cliente **CL, char *FirstName, char *LastName, char *CI, char *pAdress, char *Telehpone) {
	Cliente *cl = new Cliente;
	Cliente *aux = *CL;

	strcpy_s(cl->FirstNames, FirstName);
	strcpy_s(cl->LastNames, LastName);
	strcpy_s(cl->CI, CI);
	strcpy_s(cl->Direction, pAdress);
	strcpy_s(cl->TelephoneNumber, Telehpone);
	cl->cuen=NULL;

	cl->prox = aux;
	*CL = cl;
}

void eliminarCuentas(Cuenta **c, char *CI){
	Cuenta *d = *c;
	Cuenta *v = d;

	while (d) {
		if (strcmp(d->CI, CI) == 0) {
			if (v == d) {
				*c=(*c)->prox;
				delete( d);
				printf_s("\n\n Su cuenta se ha eliminado con exito\n\n");
			}
			else {
				v = d;
				d = d->prox;
				delete v;
				printf_s("\n\n Su cuenta se ha eliminado con exito\n\n");
			}
		}
		else{
			d = d->prox;
		}
	}
}

void eliminarTranferencias(Transaccion **T, char *CI){
	Transaccion *d = *T;
	Transaccion *v = d;

	while (d) {
		if ((strcmp(d->CIE, CI) == 0) || (strcmp(d->CIR, CI) == 0)) {
			if (v == d) {
				*T = (*T)->prox;
				delete(d);
				printf_s("\n\n Su transaccion se ha eliminado con exito\n\n");
			}
			else {
				v = d;
				d = d->prox;
				delete (v);
				printf_s("\n\n Su transaccion se ha eliminado con exito\n\n");
			}
		}
		else{
			d = d->prox;
		}
	}
}

void EliminarCliente(Cliente **CL, Cuenta **c, Transaccion **T, char *CI) {
	Cliente *pCI= *CL;
	Cliente *pAux = pCI;

	while (strcmp(pCI->CI, CI) != 0) {
		pCI = pCI->prox;
	}

	if(pCI){
		eliminarCuentas(c, CI);
		eliminarTranferencias(T,CI);

		if (pCI == pAux) {
			*CL = (*CL)->prox;
			delete (pCI);
			printf_s("\n\n Su cliente se ha eliminado con exito\n\n");
		}
		else {
			pAux = pCI;
			pCI = pCI->prox;
			delete pAux;
			printf_s("\n\n Su cliente se ha eliminado con exito\n\n");
		}
	}
}

void MostrarClientes(Cliente *b) {
	Cliente *t = b;

	printf_s("------------------------CLIENTES------------------------\n ");
	while (t) {
		printf_s("Nombre Completo: ");
		printf_s("%s %s\n", t->FirstNames, t->LastNames);
		printf_s("Cedula: ");
		printf_s("%s\n", t->CI);
		printf_s("Telefono: ");
		printf_s("%s\n", t->TelephoneNumber);
		printf_s("Direccion: ");
		printf_s("%s\n", t->Direction);
		printf_s("-----------------------------------------------------\n\n");
		t = t->prox;
	}
	printf_s("\n");
};

void ModificarCliente(Cliente **b, char *CodeN, char *firstName, char *lastName, char *AdressB, char *Telephone, char *l1, char *l2, char *l3) {
	if (strcmp(l1, "1") == 0) {
		Cliente *pCL = *b;

		while ((pCL) && (strcmp(pCL->CI, CodeN) != 0))
			pCL = pCL->prox;

		strcpy_s(pCL->FirstNames, firstName);
		strcpy_s(pCL->LastNames, lastName);
	}

	if (strcmp(l2, "1") == 0) {
		Cliente *pCL = *b;
		if ((VerifyAdressB(pCL, AdressB)) == 0) {
			while ((pCL) && (strcmp(pCL->CI, CodeN) != 0))
				pCL = pCL->prox;

			strcpy_s(pCL->Direction, AdressB);
		}
		else printf_s("La direccion ya ha sido usado por otro Cliente.\n");
	}

	if (strcmp(l3, "1") == 0) {
		Cliente *pCL = *b;

		if ((verificarTelefono(pCL, Telephone)) == 0) {

			while ((pCL) && (strcmp(pCL->CI, CodeN) != 0))
				pCL = pCL->prox;

			strcpy_s(pCL->TelephoneNumber, Telephone);
		}
		else printf_s("El numero telefonico ya ha sido usado por otro Cliente.\n");
	}
}