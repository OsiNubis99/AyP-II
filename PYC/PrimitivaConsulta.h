#include "Transaccion.h"

void MostrarClient(Cliente *CL, Banco *B, Cuenta *C, char *FirstName) {
	Cliente *Aux = CL;
	int SaldoTotal = 0;

	while(Aux){		
		Cuenta *AuxC = C;
		if(strcmp(Aux->FirstNames, FirstName) == 0){
			printf_s("------------------------CLIENTE------------------------\n ");
			printf_s("Nombre Completo: ");
			printf_s("%s %s\n", Aux->FirstNames, Aux->LastNames);
			printf_s("Cedula: ");
			printf_s("%s\n", Aux->CI);
			printf_s("Telefono: ");
			printf_s("%s\n", Aux->TelephoneNumber);
			printf_s("Direccion: ");
			printf_s("%s\n", Aux->Direction);
			while(AuxC){
				if(strcmp(Aux->CI, AuxC->CI) == 0){
					Banco *AuxB = B;
					printf_s("------------------------CUENTA------------------------\n ");
					while(strcmp(AuxC->BankCode, AuxB->BankCode) != 0)
						AuxB = AuxB->prox;
					printf_s("Nombre de Banco: ");
					printf_s("%s\n", AuxB->Nombre);

					printf_s("Numero de cuenta: ");
					printf_s("%s\n", AuxC->AccountNumber);
					printf_s("Saldo: ");
					printf_s("%d\n", AuxC->Saldo);
					SaldoTotal = AuxC->Saldo + SaldoTotal;
				}
				AuxC = AuxC->prox;
			}
		}
		Aux = Aux->prox;
	}
	printf_s("\n Saldo Total: ");
	printf_s("%d BS\n", SaldoTotal);
	system("pause");
}

void mostrarPersona(Cliente *CL, Cuenta *C, Transaccion *T, char *CI) {
	Cliente *Aux = CL;
	Cuenta *AuxC = C;
	while (strcmp(CI, Aux->CI) != 0)
		Aux = Aux->prox;

	if(Aux){
		printf_s("Nombre Completo: ");
		printf_s("%s %s\n", Aux->FirstNames, Aux->LastNames);
		while(AuxC){
			int cobro = 0, pago = 0;
			Transaccion *AuxT = T;
			if(strcmp(CI, AuxC->CI) == 0){
				printf_s("------------------------CUENTA------------------------\n ");
				printf_s("Numero de cuenta: ");
				printf_s("%s\n", AuxC->AccountNumber);
				printf_s("Saldo: ");
				printf_s("%d\n", AuxC->Saldo);
				while(AuxT){
					if(strcmp(CI, AuxT->CIE) == 0){
						pago ++;
						AuxT = AuxT->prox;
					}
					else if(strcmp(CI, AuxT->CIR) == 0){
						cobro ++;
						AuxT = AuxT->prox;
					}
					else{
						AuxT = AuxT->prox;
					}
				}
				printf_s("Total de pagos: ");
				printf_s("%d\n", pago);
				printf_s("Total de cobros: ");
				printf_s("%d\n", cobro);
				AuxC = AuxC->prox;
			}
		}
	}
	system("pause");
}

Transaccion Ordenar(Transaccion *T, char *CI, long int *monto) {
	Transaccion *TR = T;
	Transaccion *TR2 = T;
	Transaccion *TR3 = T;
	long int max = 0;
	int max2 =0;
	while(TR){
		TR2 = TR->prox;
		max = *monto;
		while(TR2){
			if((max > TR2->monto) || (strcmp(CI, TR->CIR) != 0)){
				if(TR->monto > max){
					if(max2 < max){
						TR3 = TR;
						max = max;}
				}
			}
			else if((max < TR2->monto) || (strcmp(CI, TR->CIR) != 0)){
				if(max2 < max){
					TR3 = TR;
					max = max;}
			}
			max2 = max;
			TR2 = TR2->prox;
		}
		TR = TR->prox;
	}
	return *TR3;
}

Transaccion OrdenarP(Transaccion *T, char *CI) {
	Transaccion *TR = T;
	Transaccion *TR2 = T;
	Transaccion *TR3 = T;
	int max = 0, max2 =0;
	while(TR){
		TR2 = TR->prox;
		max = TR->monto;
		while(TR2){
			if((max > TR2->monto) || (strcmp(CI, TR->CIR) != 0)){
				if(max2 < max){
					TR3 = TR;
					max = max;}
			}
			else if((max < TR2->monto) || (strcmp(CI, TR->CIR) != 0)){
				if(max2 < max){
					TR3 = TR;
					max = max;}
			}
			max2 = max;
			TR2 = TR2->prox;
		}
		TR = TR->prox;
	}
	return *TR3;
}

void mostrarPersonaPagoF(Cliente *CL, Cuenta *T, Transaccion *c, char *CI) {
	Cliente *Aux = CL;
	Cliente *Aux2 = CL;
	int SaldoTotal = 0;
	Cuenta *Auxc = T;
	while (strcmp(CI, Aux->CI) != 0)
		Aux = Aux->prox;

	if(Aux){
		while(Auxc){
			if(strcmp(Auxc->CI,Aux->CI) == 0){
				Transaccion *Auxt = c; 
				while(Auxt){
					Transaccion *TR = &Ordenar(Auxt, CI, &Auxt->monto);
					while(strcmp(Aux2->CI, TR->CIR) != 0)
						Aux2 = Aux2->prox;

					printf_s("Nombre Completo: ");
					printf_s("%s %s\n", Aux2->FirstNames, Aux2->LastNames);
					printf_s("Cedula: ");
					printf_s("%s\n", Aux2->CI);
					printf_s("Telefono: ");
					printf_s("%s\n", Aux2->TelephoneNumber);
					printf_s("Direccion: ");
					printf_s("%s\n", Aux2->Direction);
					printf_s("Codigo de transaccion: ");
					printf_s("%li\n", TR->OperationCode);
					printf_s("Fecha: ");
					printf_s("%i/%i/%i\n",TR->Dia,TR->mes,TR->year);
					printf_s("Hora: ");
					printf_s("%i:%i\n", TR->hora,TR->minuto);
					printf_s("Descripcion: ");
					printf_s("%s\n", TR->Description);
					printf_s("Saldo: ");
					printf_s("%d\n", TR->monto);
					printf_s("Tipo de Transaccion: PAGO");
					SaldoTotal = TR->monto + SaldoTotal;
					Cliente *Aux2 = CL;
					Aux->cuen->trans = Aux->cuen->trans->prox;
				}
				Auxt = Auxt->prox;
			}
			Auxc = Auxc->prox;
		}
		printf_s("Monto Total: ");
		printf_s("%d BS\n", SaldoTotal);
	}
}

void mostrarPersonaCobro(Cliente *CL, char *CI) {
	Cliente *Aux = CL;
	Cliente *Aux2 = CL;
	int SaldoTotal = 0;

	while (strcmp(CI, Aux->CI) != 0)
		Aux = Aux->prox;

	if(Aux){
		while(Aux->cuen){
			while(Aux->cuen->trans){
				if(strcmp(CI, Aux->cuen->trans->CIR) == 0){
					Transaccion *TRT = &OrdenarP(Aux->cuen->trans, CI);

					while(strcmp(Aux2->CI, TRT->CIE) != 0)
						Aux2 = Aux2->prox;

					printf_s("Nombre Completo: ");
					printf_s("%s %s\n", Aux2->FirstNames, Aux2->LastNames);
					printf_s("Cedula: ");
					printf_s("%s\n", Aux2->CI);
					printf_s("Telefono: ");
					printf_s("%s\n", Aux2->TelephoneNumber);
					printf_s("Direccion: ");
					printf_s("%s\n", Aux2->Direction);
					printf_s("Codigo de transaccion: ");
					printf_s("%li\n", TRT->OperationCode);
					printf_s("Fecha: ");
					printf_s("%i/%i/%i\n", TRT->Dia,TRT->mes,TRT->year);
					printf_s("Hora: ");
					printf_s("%i:%i\n", TRT->hora,TRT->minuto);
					printf_s("Descripcion: ");
					printf_s("%s\n", TRT->Description);
					printf_s("Saldo: ");
					printf_s("%d\n", TRT->monto);
					printf_s("Tipo de Transaccion: COBRO");
					SaldoTotal = TRT->monto + SaldoTotal;
					Cliente *Aux2 = CL;
					Aux->cuen->trans = Aux->cuen->trans->prox;
				}
			}
			Aux->cuen = Aux->cuen->prox;
		}
		printf_s("Monto Total: ");
		printf_s("%d BS\n", SaldoTotal);
	}
}

void MPagos(Transaccion *T, char *CI){
	Transaccion *Aux = T;
	int cont =0 ;
	while(Aux){
		if(strcmp(CI, Aux->CIE) == 0){
			printf_s("Codigo de transaccion: ");
			printf_s("%li\n", Aux->OperationCode);
			printf_s("Fecha: ");
			printf_s("%i/%i/%i\n", Aux->Dia,Aux->mes,Aux->year);
			printf_s("Hora: ");
			printf_s("%i:%i\n", Aux->hora,Aux->minuto);
			printf_s("Descripcion: ");
			printf_s("%s\n", Aux->Description);
			printf_s("Saldo: ");
			printf_s("%d\n", Aux->monto);
			printf_s("Cedula del receptor: ");
			printf_s("%s\n", Aux->CIR);
			printf_s("Tipo de Transaccion: PAGO");
			cont = cont+1;
			Aux = Aux->prox;
		}
	}
	printf_s("Total de pagos: ");
	printf_s("%d\n", cont);
}

void MpagosR(Transaccion *T, char *CI) {
	int cont =0;
	Transaccion *Aux = T;
	while(Aux){
		if(strcmp(CI, Aux->CIR) == 0){
			printf_s("Codigo de transaccion: ");
			printf_s("%li\n", Aux->OperationCode);
			printf_s("Fecha: ");
			printf_s("%i/%i/%i\n", Aux->Dia,Aux->mes,Aux->year);
			printf_s("Hora: ");
			printf_s("%i:%i\n", Aux->hora,Aux->minuto);
			printf_s("Descripcion: ");
			printf_s("%s\n", Aux->Description);
			printf_s("Saldo: ");
			printf_s("%d\n", Aux->monto);
			printf_s("Cedula del emisor: ");
			printf_s("%s\n", Aux->CIE);
			printf_s("Tipo de Transaccion: COBRO");
			cont = cont +1;
			Aux = Aux->prox;
		}
	}
	printf_s("Total de cobros: ");
	printf_s("%d\n", cont);
}

void mostrarTransacciones(Cliente *CL, char *CI){
	Cliente *Aux = CL;
	int cobro = 0, pago = 0;
	while (strcmp(CI, Aux->CI) != 0)
		Aux = Aux->prox;

	if(Aux){
		while(Aux->cuen){
			printf_s("------------------------CUENTA------------------------\n ");
			printf_s("Numero de cuenta: ");
			printf_s("%s\n", Aux->cuen->AccountNumber);
			MPagos(Aux->cuen->trans, CI);
			MpagosR(Aux->cuen->trans, CI);
		}
		Aux->cuen = Aux->cuen->prox;
	}
}
