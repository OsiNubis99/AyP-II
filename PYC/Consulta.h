#include "Transaccion.h"
void mostrar_clientes(Cliente *a){
	Cliente *c=a;char nom[50];
	do{
	printf_s("\n\n\t El nombre a consultar:");
	scanf_s("%s",nom,50);
	if(strcmp(nom,"0")==0) break;
		c=a;
		while (c){
			if (strcmp(c->FirstNames,nom)==0)break;
			c=c->prox;
		}
		if(!(c)) printf("\n\t\t Numero no reconocido o encontrado\n\t\tPulsa 0 para abandonar");
	}while(!(c));
	while(a){
		if(strcmp(nom,a->FirstNames)==0){
			printf_s("\n\n----------------------------------");
			printf_s("\n\n-------------- %s %s --------------",nom,a->LastNames);
			printf_s("\n\t\tCI:%s ",a->CI);
			printf_s("\n\t\tDireccion:%s ",a->Direction);
			printf_s("\n\t\tTelefono:%s ",a->TelephoneNumber);
			Cuenta *cuentas=a->cuen;
			int cont1=0, cont2=0;
			while(cuentas){
				cont1++;
				printf_s("\n\n\t\tNumero de cuenta:%s ",cuentas->AccountNumber);
				Banco *ban=a->cuen->Banks;
				while(ban){
					if(ban->BankCode==cuentas->BankCode) break;
					ban=ban->prox;
				}
				if(ban) printf_s("\n\t\tNombre del banco:%s ",ban->Nombre);
				printf_s("\n\t\tSaldo para esta cuenta:%i ",cuentas->Saldo);
				cont2+=cuentas->Saldo;
				cuentas=cuentas->prox;
			}
			printf_s("\n\n\t\tTotal de cuentas:%i ",cont1);
			printf_s("\n\t\tSaldo total:%i ",cont2);
			printf_s("\n\n----------------------------------");
		}
		a=a->prox;
	}
}

void ordenarmonto(Transaccion *t, Cliente *a,int x,char numer[15]){
	int z=1;Transaccion *tran=t;
	while(z){z=0;tran=t;
	while((tran)&&(tran->prox)){
		if (tran->monto < tran->prox->monto){ 
			Transaccion *y=tran->prox;
			tran->prox=tran->prox->prox;
			y->prox=tran;
			tran=y;
			z++;
		}
		tran=tran->prox;
	}
	}// ordenar
	Cliente *person;
	int cont1=0;
	while(t){ // imprimir
		person=a;
		if(strcmp(numer,t->NCuentE)==x){// se para en t que sea lo que busca (pago, cobro)
			printf("------------------------------------");
			printf("");
			while(person){
				Cuenta *cuent=person->cuen;
				if (x){//busca emisor si t era cobro
					while(cuent){
						if(strcmp(cuent->AccountNumber,t->NCuentE)==0)
						{printf("\n\tNombre del Emisor: %s %s",person->FirstNames,person->LastNames);
						break;
						}
						cuent=cuent->prox;
					}
				}
				else{
					while(cuent){
						if(strcmp(cuent->AccountNumber,t->NCuentR)==0)
						{printf("\n\tNombre del Receptor: %s %s",person->FirstNames,person->LastNames);
						break;
						}
						cuent=cuent->prox;			
					}			
				}
				if (cuent) break;
				person=person->prox;
			}
		
		if (x)
			printf("\n\tCedula de identidad: %s",t->CIE);
		else
			printf("\n\tCedula de identidad: %s",t->CIR);
		printf("\n\tMonto: %d",t->monto);
		cont1+=t->monto;
		printf("\n\tFecha(AAAA/MM/DD/HH/MM): %i/%i/%i/%i/%i ",t->year,t->mes,t->Dia,t->hora,t->minuto);
		printf("\n\tDescripcion: %s\n",t->Description);
		}
		t=t->prox;
	}


}
// pasar 0 si sse quiere que imprima recetor 
void ordenarfecha(Transaccion *t, Cliente *a,int x,char numer[15]){
	int z=1;Transaccion *tran=t;
	while(z){z=0;tran=t;
	while((tran)&&(tran->prox)){
		if (tran->year <= tran->prox->year)
			if (tran->mes <= tran->prox->mes)
				if (tran->Dia <= tran->prox->Dia)
					if (tran->minuto < tran->prox->minuto)
							{
								Transaccion *y=tran->prox;
								tran->prox=tran->prox->prox;
								y->prox=tran;
								tran=y;
								z++;
							}
		tran=tran->prox;
	}
	}// ordenar
	Cliente *person;
	int cont1=0;
	while(t){ // imprimir
		person=a;
		if(strcmp(numer,t->NCuentE)==x){// se para en t que sea lo que busca (pago, cobro)
			printf("\n\n\t------------------------------------");
			while(person){
				Cuenta *cuent=person->cuen;
				if (x){//busca emisor si t era cobro
					while(cuent){
						if(strcmp(cuent->AccountNumber,t->NCuentE)==0)
						{printf("\n\tNombre del Emisor: %s %s",person->FirstNames,person->LastNames);
						break;
						}
						cuent=cuent->prox;
					}
				}
				else{
					while(cuent){
						if(strcmp(cuent->AccountNumber,t->NCuentR)==0)
						{printf("\n\tNombre del Receptor: %s %s",person->FirstNames,person->LastNames);
						break;
						}
						cuent=cuent->prox;			
					}			
				}
				if(cuent)break;
				person=person->prox;
			}
		
		if (x)
			printf("\n\tCedula de identidad: %s",t->CIE);
		else
			printf("\n\tCedula de identidad: %s",t->CIR);
		printf("\n\tMonto: %d",t->monto);
		cont1+=t->monto;
		printf("\n\tFecha(AAAA/MM/DD/HH/MM): %i/%i/%i/%i/%i ",t->year,t->mes,t->Dia,t->hora,t->minuto);
		printf("\n\tDescripcion: %s\n",t->Description);

		}
		t=t->prox;
	}


}
// pasar 0 si sse quiere que imprima recetor 
void mostrar_todo_fecha(Cliente *a){
	Cuenta *cuen=a->cuen;int x=0,y=0;
	while(cuen){
		int z=1;Transaccion *tran=cuen->trans;
		while(z){z=0;tran=cuen->trans;
		while((tran)&&(tran->prox)){
		if (tran->year <= tran->prox->year)
			if (tran->mes <= tran->prox->mes)
				if (tran->Dia <= tran->prox->Dia)
					if (tran->minuto < tran->prox->minuto)
							{
								Transaccion *y=tran->prox;
								tran->prox=tran->prox->prox;
								y->prox=tran;
								tran=y;
								z++;
							}
		tran=tran->prox;
	}
	}// ordenar
		tran=cuen->trans;
		z=2;system("cls");
				printf("\n\n\t-------------------------------------------------------------------------------");
		while(z){
			tran=cuen->trans;
		while(tran){
			if(z==2){
			if(tran->NCuentE!=cuen->AccountNumber){
				printf("\n\t\tNumero de operacion: %d ",tran->OperationCode);
				printf("\n\t\tFecha(AAAA/MM/DD/HH/MM): %i/%i/%i/%i/%i ",tran->year,tran->mes,tran->Dia,tran->hora,tran->minuto);
				printf("\n\t\tNumero de CI Emisor: %s ",tran->CIE);
				printf("\n\t\tDescripcion: %s ",tran->Description);
				x++;
			}}
			else
				if(tran->NCuentE==cuen->AccountNumber){
						printf("\n\t\tNumero de operacion: %d ",tran->OperationCode);
				printf("\n\t\tFecha(AAAA/MM/DD/HH/MM): %i/%i/%i/%i/%i ",tran->year,tran->mes,tran->Dia,tran->hora,tran->minuto);
				printf("\n\t\tNumero de CI Receptor: %s ",tran->CIR);
				printf("\n\t\tDescripcion: %s ",tran->Description);	
				y++;
				}
			tran=tran->prox;
		}
		z--;
		}
		printf("\n\t\tTotal de pagos: %i ",x);
		printf("\n\t\tTotal de cobros: %i \n",y);
	cuen=cuen->prox;x=0;y=0;
	}
}

void c_2_1(Cliente *a){
	system("cls");
	char ci[9];
	Cliente *c=a;
	do{ 
		c=a;
		printf("\n\n\tCedula a verificar: ");
		scanf("%s",ci);
		if(c==0)break;
		while (c){
			if(strcmp(c->CI,ci)==0)break;
			c=c->prox;
		}
		if(!(c)) printf("\n\t\t Numero no reconocido o encontrado\n\t\tPulsa 0 para abandonar");
	}while(!(c));
	if(c){
	printf_s("\n\n----------------------------------");
	printf_s("\n-----------  %s  -----------------",ci);
	printf_s("\n\t Nombre: %s \n\t Apellido: %s\n",c->FirstNames,c->LastNames);
	Cuenta *cuentas=c->cuen;
	Transaccion *tran;
	int cont1=0,cont2=0;
	while (cuentas){
		printf_s("\n\t\t Numero de cuenta: %s \n\t\t Saldo para esta cuenta: %d",cuentas->AccountNumber,cuentas->Saldo);
		tran=cuentas->trans;
		
		while (tran){
			if(strcmp(cuentas->AccountNumber,tran->NCuentR)==0)
				cont1++;
			else cont2++;
			tran = tran->prox;
		}
		printf_s("\n\t Transacciones de cobro : %d\n\t transacciones de pago: %d",cont1,cont2);
		cont1=0;cont2=0;
		cuentas=cuentas->prox;
	}
	printf_s("\n----------------------------------");
	}

}
void c_2_2(Cliente *c){
	system("cls");
	char ci[9];
	Cliente *a=NULL;
	while(!a){
	printf("\n\n\tCedula a verificar: ");
	scanf("%s",ci);
	if(c==0)break; 
	a=c;
	while(a){
		if(strcmp(a->CI,ci)==0)break;
		a=a->prox;
	}
	if(!a)printf("\n\t\t Numero no reconocido o encontrado\n\t\tPulsa 0 para abandonar");
    }
	Cuenta *cuen=a->cuen;
	while(cuen){
	ordenarfecha(cuen->trans,c,0,a->cuen->AccountNumber);
	cuen=cuen->prox;
	}
}
void c_2_3(Cliente *c){
	system("cls");
	char ci[9];
	Cliente *a=NULL;
	while(!a){
	printf("\n\n\tCedula a verificar: ");
	scanf("%s",ci);
	if(c==0)break; 
	a=c;
	while(a){
			if(strcmp(a->CI,ci)==0)break;
		a=a->prox;
	}
	if(!a)printf("\n\t\t Numero no reconocido o encontrado\n\t\tPulsa 0 para abandonar");
    }
	Cuenta *cuen=a->cuen;
	while(cuen){
	ordenarmonto(cuen->trans,c,0,a->cuen->AccountNumber);
	cuen=cuen->prox;
	}
}
void c_2_4(Cliente *c){
	system("cls");
	char ci[9];
	Cliente *a=NULL;
	while(!a){
	printf("\n\n\tCedula a verificar: ");
	scanf("%s",ci);
	if(c==0)break; 
	a=c;
	while(a){
		if(strcmp(a->CI,ci)==0)break;
		a=a->prox;
	}
	if(!a)printf("\n\t\t Numero no reconocido o encontrado\n\t\tPulsa 0 para abandonar");
    }
	Cuenta *cuen=a->cuen;
	while(cuen){
	ordenarfecha(cuen->trans,c,1,a->cuen->AccountNumber);
	cuen=cuen->prox;
	}
}
void c_2_5(Cliente *c){
	system("cls");
	char ci[9];
	Cliente *a=NULL;
	while(!a){
	printf("\n\n\tCedula a verificar: ");
	scanf("%s",ci);
	if(c==0)break; 
	a=c;
	while(a){
		if(strcmp(a->CI,ci)==0)break;
		a=a->prox;
	}
	if(!a)printf("\n\t\t Numero no reconocido o encontrado\n\t\tPulsa 0 para abandonar");
    }
	Cuenta *cuen=a->cuen;
	while(cuen){
	ordenarmonto(cuen->trans,c,1,a->cuen->AccountNumber);
	cuen=cuen->prox;
	}
}
void c_2_6(Cliente *c){
	system("cls");
	char ci[9];
	Cliente *a=NULL;
	while(!a){
	printf("\n\n\tCedula a verificar: ");
	scanf("%s",ci);
	if(c==0)break; 
	a=c;
	while(a){
		if(strcmp(a->CI,ci)==0)break;
		a=a->prox;
	}
	if(!a)printf("\n\t\t Numero no reconocido o encontrado\n\t\tPulsa 0 para abandonar");
    }
	mostrar_todo_fecha(a);
}

void rangomonto(Cliente *c){
	int cont=0;
	Transaccion *t;
	Transaccion *todas=NULL;
	int min=0,max=0;
	do{
	printf("\n\n\t indica el limite inferior de la busqueda: (n>0) ");
	scanf("%i",&min);
	}while(min==0);
	do{
	printf("\n\n\t indica el limite superior de la busqueda: (n>0)");
	scanf("%i",&max);}while(max==0);
	while(c){
		Cuenta *cuen=c->cuen;
		while(cuen){
			Transaccion *tran=cuen->trans;
			while(tran){
				if((tran->monto >= min)&&(tran->monto <= max)){
					t=new Transaccion;
					strcpy(t->CIE,tran->CIE);
					strcpy(t->CIR,tran->CIR);
					t->monto=tran->monto;
					strcpy(t->NCuentE,tran->NCuentE);
					strcpy(t->NCuentR,tran->NCuentR);
					t->year=tran->year;
					t->mes=tran->mes;
					t->Dia=tran->Dia;
					t->hora=tran->hora;
					t->minuto=tran->minuto;
					t->prox=todas;
					todas=t;
				}
				tran=tran->prox;
			}
			cuen=cuen->prox;
		}
		c=c->prox;
	}
	int i=1;
	while(i){i=0;
		t=todas;
		while((t)&&(t->prox)){
		if (t->monto > t->prox->monto){ 
			Transaccion *y=t->prox;
			t->prox=t->prox->prox;
			y->prox=t;
			t=y;
			i++;
		}
		t=t->prox;
	}
	}
	while(todas){
				printf("\n\t\tMonto: %i",todas->monto);
					printf("\n\tFecha(AAAA/MM/DD/HH/MM): %i %i %i %i %i",todas->year,todas->mes,todas->Dia,todas->hora,todas->minuto);
					printf("\n\tCi del receptor: %s",todas->CIR);
					printf("\n\tNumero de cuenta del receptor: %s",todas->NCuentR);
					printf("\n\tCI del emisor: %s",todas->CIE);
					printf("\n\tNumero de cuenta del emisor: %s\n",todas->NCuentE);
					cont++;
					todas=todas->prox;
	}
	if(cont)printf("\n\tPara este rango hay %i operaciones.\n",cont);
	else printf("\n\tNo hay ninguna operacion dentro de este rango de monto\n");
}

void consultas( Cliente *c) {
	char CI[20] = "", CodeA[5] = "", Account[21] = "", CodeN[5] = "";
	int op = -1;

	while (op != 0) {
		system("cls");
		printf_s("\t\t<-<- Menu de Consultas ->->\n");
		printf_s("\n\t1. Consultar por nombre de clientes");
		printf_s("\n\t2. Consultar por CI de cliente");
		printf_s("\n\t3. Consultar por rango de montos");
		printf_s("\n\t0. Volver al Menu Principal");
		printf_s("\n\n\t\tOpcion: ");
		scanf_s("%d", &op);
		switch (op) {
		case 1:
			mostrar_clientes(c);
			printf_s("\n");
			break;

		case 2: 
			while(op){
			system("cls");
			printf_s("\t\t\t<-<- Opciones ->->\n");
			printf_s("\n\t1. Nombre, codigo, numeros de cuenta, saldos y operaciones");
			printf_s("\n\t2. Transacciones de pago orden de fecha/hora");
			printf_s("\n\t3. Transacciones de pago orden de monto");
			printf_s("\n\t4. Transacciones de cobro orden de fecha/hora");
			printf_s("\n\t5. Transacciones de cobro orden de monto");
			printf_s("\n\t6. Todas las transacciones");
			printf_s("\n\tCualquier otro N. Volver al Menu consulta");
			printf_s("\n\t0. Volver al Menu Principal");
			printf_s("\n\n\t\tOpcion: ");
			scanf_s("%d", &op);
			switch (op){
			case 1:c_2_1(c);
				break;
			case 2:c_2_2(c);
				break;
			case 3:c_2_3(c);
				break;
			case 4:c_2_4(c);
				break;
			case 5:c_2_5(c);
				break;
			case 6:c_2_6(c);
				break;
			}
			system("pause");
			}
			break;
		case 3: 
			rangomonto(c);
			break;
		}
		system("pause");
	}
}