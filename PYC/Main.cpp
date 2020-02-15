#include "Consulta.h"
#include "Archivos.h"

void main()
{
	system("color 0A");
	Cuenta * C = NULL;
	Cliente * CL = NULL; 
	Transaccion *T = NULL;
	Banco *B = NULL;
	printf("\n\t _______    _______    _______   __      __   _______    _______    _______    _______   ");
	printf("\n\t|   _   |  |   _   |  |  ___  |  \\ \\    / /  |  _____|  |  _____|  |__   __|  |  ___  |");
	printf("\n\t|  |_|  |  |  |_|  |  | |   | |   \\ \\  / /   | |___     | |           | |     | |   | |");
	printf("\n\t|   ____|  |      _|  | |   | |    \\ \\/ /    |  ___|    | |           | |     | |   | |");   
	printf("\n\t|  |       |  |\\  \\   | |___| |     |  |     | |_____   | |_____      | |     | |___| |");
	printf("\n\t|__|       |__| \\__\\  |_______|     |__|     |_______|  |_______|     |_|     |_______|");
	printf("\n\t           ");
	printf("\n\t                                             CARGANDO          ");
	printf("\n\t           ");
	int ias=64;
	while(ias!=0){Sleep(100);printf("|");ias--;}
		printf_s("\n\n");
	LeerBancos(&B);
	LeerCliente(&CL);
	LeerCuentas(&CL,B);
	LeerTrans(&CL);
	char Digits[5] = "", Digit4[9] = "", Digit3[5] = "", Digit2[3] = "", TelephoneNumber[13] = "", FirstName[50] = "", SecondName[50] = "", LastName[50] = "", LastName2[50] = "", Description[100] = "", NumeroT[15] = "",
		NameB[30] = "", CodeN[9] = "", newCodeN[5] = "", AdressB[100] = "", Account[11] = "", AccountN[11] = "",  l1[3] = " ", l2[3] = "", l3[3] = " ";
	system("pause");
	int i = 0, g = 1;
	int Dia = 0,mes = 0,year = 0,hora = 0, minuto = 0;
	long int Amount = 0,CodeT = 0;
	int o = -1, o2 = -1, o3 = -1, o4 = -1, o5 = -1;
	while (o != 0)
	{system("cls");
		o2 = -1;
		printf_s("\t\t <-< Sistema de Control >-> \n\n");
		printf_s("\t\t1.Mantenimiento\n\n");
		printf_s("\t\t2.Tranferencia\n\n");
		printf_s("\t\t3.Consultas\n\n");
		printf_s("\t\t0.Salir\n\n");
		scanf_s("%d", &o);
		int  cont = 0;
		system("cls");
		switch (o)
		{
		case 1: while (o2 != 0)
				{
					o3 = -1;
					printf_s("\t\t <-| Menu de Mantenimiento |->\n\n");
					printf_s("\t\t1.Agregar\n\n");
					printf_s("\t\t2.Eliminar\n\n");
					printf_s("\t\t3.Mostrar\n\n");
					printf_s("\t\t4.Modificar\n\n");
					printf_s("\t\t0.Regresar\n\n");
					scanf_s("%d", &o2);
					system("cls");
					switch (o2)
					{
					case 1: while (o3 != 0)
							{
								o4 = -1;
								printf_s("\t\t -- Opcion 1: Agregar. -- \n\n");
								printf_s("\t\t1.Agregar Cliente\n\n");
								printf_s("\t\t2.Agregar Cuenta\n\n");
								printf_s("\t\t0.Regresar\n\n");
								scanf_s("%d", &o3);
								system("cls");
								switch (o3)
								{

								case 1:
									printf_s("\t\tRegistro de Clientes\n");
									printf_s("\nNumero de Cedula: ");
									fflush(stdin);
									scanf_s("%s", &Digit4, 9);
									while ((strcmp (Digit4,"\n") == 0) ||(verificarCl(CL, Digit4) != 0) || ((verifyNumber(Digit4) != 0))) {
										printf_s("\n\nLa cedula no es valida o ya existe. Coloque una que si lo sea\n");
										printf_s("Numero de Cedula: ");
										cont = cont +1;
										if(cont == 5){
											break;
										}
										fflush(stdin);
										scanf_s("%s", &Digit4, 9);
									}

									if(cont != 5){
										printf_s("Nombres: ");
										fflush(stdin);
										scanf_s("%s", &FirstName, 50);

										printf_s("Apellidos: ");
										fflush(stdin);
										scanf_s("%s", &LastName, 50);

										printf_s("Direccion: ");
										fflush(stdin);
										scanf_s("%s", &AdressB, 100);

										printf_s("Telefono: ");
										fflush(stdin);
										scanf_s("%s", &TelephoneNumber, 13);

										while ((strcmp (TelephoneNumber,"\n") == 0) || (verifyNumber(TelephoneNumber) != 0) || (verificarTelefono(CL,TelephoneNumber) != 0)) {
											printf_s("\n\nEl numero de Telefono no es valido o ya existe. coloque uno distinto.\n");
											printf_s("Telefono: ");
											cont = cont +1;
											if(cont == 5){
												break;
											}
											fflush(stdin);
											scanf_s("%s", &TelephoneNumber, 13);
										}

										if(cont != 5){
											AgregarCliente(&CL, FirstName, LastName, Digit4, AdressB, TelephoneNumber);
											ArchivoCliente(CL);
										}
										else{
											printf_s("\nHa intentado muchas veces.\n");
											system("pause");
											cont = 0;
										}
									}
									else{
										printf_s("\nHa intentado muchas veces.\n");
										system("pause");
										cont = 0;
									}
									break;

								case 2:
									printf_s("Agregar Cuenta\n\n");
									printf_s("Numero de cedula: ");
									fflush(stdin);
									scanf_s("%s", &Digit4, 9);

									while((verifyNumber(Digit4) != 0)){
										printf_s("\n\nLa cedula no es valida. Coloque una que si lo sea\n");
										printf_s("Numero de Cedula: ");
										cont = cont +1;
										if(cont == 5){
											break;
										}
										fflush(stdin);
										scanf_s("%s", &Digit4, 9);
									}

									if(cont != 5){
										if (verificar(CL, Digit4)) {
											printf_s("Codigo de banco: ");
											fflush(stdin);
											scanf_s("%s", &Digit3, 5);

											while ((strcmp (Digit3,"\n") == 0) || (verifyNumber(Digit3) != 0) || (verificarBanco(B, Digit3) == 0)) {
												printf_s("El Codigo de banco no es valido, por favor coloque uno que si lo sea.");
												printf_s("Codigo de banco:  ");
												cont = cont +1;
												if(cont == 5){
													break;
												}
												fflush(stdin);
												scanf_s("%s", &Digit3, 5);
											}

											if(cont != 5){
												printf_s("Tipo de cuenta (01)Corriente (02)Ahorro (03)Tarjeta de credito:  ");
												fflush(stdin);
												scanf_s("%s", &Digit2, 3);
												while ((strlen(Digit2) != 2) && ((strcmp (Digit2,"01") == 0) || (strcmp (Digit2,"02") == 0) || (strcmp (Digit2,"03") == 0))) {
													printf_s("El Tipo de Cuenta no es valido, por favor coloque uno que si lo sea.\n");
													printf_s("Tipo de cuenta (01)Corriente (02)Ahorro (03)Tarjeta de credito:  ");
													cont = cont +1;
													if(cont == 5){
														break;
													}
													fflush(stdin);
													scanf_s("%s", &Digit2, 3);
												}
												if(cont != 5){
													if (strcmp(Digit2, "03") == 0) {
														printf_s("Indique el Numero de Tarjeta: ");
														fflush(stdin);
														scanf_s("%s", &NumeroT, 15);

														while ((verificarb(C,NumeroT) != 0) || (verifyNumber(NumeroT) != 0)) {
															printf_s("El Numero de Tarjeta no es valido, por favor coloque uno que si lo sea.");
															printf_s("Numero de Tarjeta:  ");
															cont = cont +1;
															if(cont == 5){
																break;
															}
															fflush(stdin);
															scanf_s("%s", &NumeroT, 15);
														}
														if(cont == 5){
															printf_s("\nHa intentado muchas veces.\n");
															cont = 0;
															break;
														}
													}
													else {
														printf_s("Numero de cuenta:");
														fflush(stdin);
														scanf_s("%s", &AccountN, 11);

														while ((verificarb(C,AccountN) != 0) || ((verifyNumber(AccountN) != 0))) {
															printf_s("El Numero de Cuenta no es valido, por favor coloque uno que si lo sea.");
															printf_s("Numero de Cuenta:  ");
															cont = cont +1;
															if(cont == 5){
																break;
															}
															fflush(stdin);
															scanf_s("%s", &AccountN, 11);
														}
														if(cont == 5){
															printf_s("\nHa intentado muchas veces.\n");
															cont = 0;
															break;
														}
													}

													printf_s("Saldo: ");
													fflush(stdin);
													scanf_s("%d", &Amount);

													AgregarC(&CL, &C, Digit3, Digit4, Digit2, AccountN, &Amount, NumeroT);
													ArchivoCuenta(CL, C);
												}
												else{
													printf_s("\nHa intentado muchas veces.\n");
													system("pause");
													cont = 0;
												}
											}
											else{
												printf_s("\nHa intentado muchas veces.\n");
												system("pause");
												cont = 0;
											}
										}
										else {
											printf_s("\n La cedula al que quieres agregarle la cuenta, no existe\n");
											system("pause");
										}
									}
									else{
										printf_s("\nHa intentado muchas veces.\n");
										system("pause");
										cont = 0;
									}
									break;

									printf_s("\n\n");
									system("cls");
									if ((o3 < 0) || (o3 > 2)) printf_s("\tEL NUMERO DEBE SER ENTRE 0 Y 2\n\n");
								}

								o3 = -1;
								break;

					case 2: while (o3 != 0)
							{
								printf_s("\t\t -- Opcion 2: Eliminar. --\n\n");
								printf_s("\t\t1.Eliminar Cliente\n\n");
								printf_s("\t\t2.Eliminar Cuenta\n\n");
								printf_s("\t\t3.Eliminar Transaccion\n\n");
								printf_s("\t\t0.Regresar\n\n");
								scanf_s("%d", &o3);
								system("cls");
								switch (o3)
								{
								case 1:
									printf_s("Introduzca la cedula del cliente a eliminar:\n");
									fflush(stdin);
									scanf_s("%s", &Digit4, 9);
									if ((verificar(CL, Digit4) != 0) || (verifyNumber(Digit4) != 0))
									{
										EliminarCliente(&CL, &C, &T, Digit4);
										ArchivoCliente(CL);
										printf_s("\nEl cliente ha sido eliminado exitosamente.");
										system("pause");
									}
									else
									{
										printf_s("\n El cliente no existe o tiene que eliminar las cuentas primero. \n");
										system("pause");
									}
									system("cls");

									break;

								case 2:
									printf_s("\n\n\tEliminar Cuentas\n\n\t\t");
									printf_s("Coloque el numero de cuenta a Eliminar: ");
									scanf_s("%s", &Account, 11);
									if ((verificarNc(C, Account) != 0) || (verifyNumber(Account) != 0))
									{
										printf_s("Esta seguro que quiere eliminar esta Cuenta? (1)Si (0)No: ");
										scanf_s("%s", l1, 2);
										if (strcmp(l1, "1") == 0)
										{
											EliminarCuenta(&C, &CL, &T, Account);
											ArchivoCuenta(CL, C);
										}
										else
										{
											printf_s("La cuenta no se ha Eliminado");
											system("pause");
										}
									}
									else
									{
										printf_s("\n La cuenta no existe. \n");
										system("pause");
									}

									break;

								case 3:
									printf_s("\n\nEliminar transacciones \n\n\t\t");
									printf_s("Coloque el Codigo de Transaccion: ");
									scanf_s("%li\n", CodeT);
									if (VerificarCodeT(T, &CodeT) == 0)
									{
										EliminarTransac(&C, &T, &CodeT);
										ArchivoTrans(CL,C,T);
									}
									else
									{
										system("cls");
										printf_s("El codigo de transaccion no existe. \n\n");
										system("pause");
									}

									break;
								}
								printf_s("\n\n");
								system("cls");
								if ((o3 < 0) || (o3 > 3)) printf_s("\tEL NUMERO DEBE SER ENTRE 0 Y 3\n\n");
							}
							o3 = -1;
							system("cls");
							break;

					case 3: while (o4 != 0)
							{
								printf_s("\t\t -- Opcion 3: Consultar. -- \n\n");
								printf_s("\t\t1.Consultar Cliente\n\n");
								printf_s("\t\t2.Consultar Cuenta\n\n");
								printf_s("\t\t3.Consultar Transaccion\n\n");
								printf_s("\t\t0.Regresar\n\n");
								scanf_s("%d", &o4);
								system("cls");
								switch (o4)
								{
								case 1:
									printf_s("\n\n\tMostrar Clientes\n\n");
									MostrarClientes(CL);
									printf_s("NULL\n\n");
									if (CL == NULL) {
										printf_s("No tiene Entidades registradas.");
									};
									break;

								case 2:printf_s("\n\n\tMostrar Cuentas\n\n");
									MostrarCuenta(C);
									printf_s("NULL\n\n");
									if (C == NULL) {
										printf_s("No tiene cuentas registradas.");
									};
									break;

								case 3:
									printf_s("\t\tConsulta de Transacciones\n\n");
									MostrarTran(T);
									printf_s("\nNULL\n\n");

									break;
								}
								printf_s("\n\n");
								if (o) system("pause");
								system("cls");
								if ((o4 < 0) || (o4 > 3)) printf_s("\tEL NUMERO DEBE SER ENTRE 0 Y 3\n\n");
							}
							o4 = -1;
							system("cls");
							break;

					case 4: while (o5 != 0)
							{
								printf_s("\t\t -- Opcion 4: Modificar. -- \n\n");
								printf_s("\t\t1.Modificar Cliente\n\n");
								printf_s("\t\t2.Modificar Cuenta\n\n");
								printf_s("\t\t0.Regresar\n\n");
								scanf_s("%d", &o5);
								system("cls");
								switch (o5)
								{
								case 1:
									printf_s("\n\nIndique la cedula del cliente al que desea modificar:\n");
									fflush(stdin);
									scanf_s("%s", &CodeN, 9);

									if ((verificar(CL, CodeN)) || (verifyNumber(CodeN) != 0))
									{
										printf_s("\n\nQuieres Cambiar el nombre? (1) = Si, (0)= No\n");
										fflush(stdin);
										scanf_s("%s", &l1, 2);

										if (strcmp(l1, "1") == 0)
										{
											printf_s("\n\nIndique el nuevo nombre\n");
											fflush(stdin);
											scanf_s("%s", &FirstName, 50);

											while (strlen(FirstName) < 5)
											{
												printf_s("\n\nNo ha colocado ningun nombre valido, por favor, hagalo: \n");
												fflush(stdin);
												cont = cont + 1;
												if(cont == 5)
													break;
												scanf_s("%s", &FirstName, 50);
											}

											if(cont != 5){
												printf_s("\n\nIndique el nuevo apellido\n");
												fflush(stdin);
												scanf_s("%s", &LastName, 50);

												while (strlen(LastName) < 5)
												{
													printf_s("\n\nNo ha colocado ningun apellido valido, por favor, hagalo: \n");
													fflush(stdin);
													cont = cont +1;
													if(cont == 5)
														break;
													scanf_s("%s", &LastName, 50);
												}
												if(cont == 5){
													printf_s("\nHa intentado muchas veces.\n");
													system("pause");
													cont = 0;
													break;
												}
											}
											else{
												printf_s("\nHa intentado muchas veces.\n");
												system("pause");
												cont = 0;
												break;
											}
										}
										else if (strcmp(l1, "0") != 0) {
											printf_s("\nUsted a seleccionado una respuesta invalida");
										}

										printf_s("\n\nQuieres Cambiar la direccion? (1) = si, (0)= no\n");
										fflush(stdin);
										scanf_s("%s", &l2, 2);
										if (strcmp(l2, "1") == 0)
										{

											printf_s("\n\nIndique la nueva Direccion del cliente\n");
											fflush(stdin);
											scanf_s("%s", &AdressB, 100);

											while (strlen(AdressB) < 5)
											{
												printf_s("\n\nNo ha colocado ninguna Direccion, por favor, hagalo: \n");
												fflush(stdin);
												cont = cont +1;
												if(cont == 5)
													break;
												scanf_s("%s", &AdressB, 100);
											}
											if(cont == 5){
												printf_s("\nHa intentado muchas veces.\n");
												system("pause");
												cont = 0;
												break;
											}
										}
										else if (strcmp(l2, "0") != 0)
											printf_s("\nUsted a seleccionado una respuesta invalida");

										printf_s("\n\nQuieres Cambiar el telefono? (1) = si, (0)= no\n");
										fflush(stdin);
										scanf_s("%s", &l3, 2);
										if (strcmp(l3, "1") == 0)
										{

											printf_s("\n\nIndique el nuevo telefono del cliente\n");
											fflush(stdin);
											scanf_s("%s", &TelephoneNumber, 13);

											while ((verificarTelefono(CL,TelephoneNumber) != 0)|| (verifyNumber(TelephoneNumber) != 0))
											{
												printf_s("\n\nNo ha colocado ningun telefono valido, por favor, hagalo: \n");
												fflush(stdin);
												cont = cont +1;
												if(cont == 5)
													break;
												scanf_s("%s", &TelephoneNumber, 13);
											}
											if(cont == 5){
												printf_s("\nHa intentado muchas veces.\n");
												system("pause");
												cont = 0;
												break;
											}
										}
										else if (strcmp(l3, "0") != 0)
											printf_s("\nUsted a seleccionado una respuesta invalida");


									}
									if((l1 != "1") || (l2 != "1") || (l3 != "1")){
										ModificarCliente(&CL, CodeN, FirstName, LastName, TelephoneNumber, AdressB, l1, l2, l3);
										ArchivoCliente(CL);
									}
									else{
										printf_s("\nNo ha hecho ningun cambio");
										system("pause");
										break;
									}

								case 2:
									printf_s("Indique el numero de cuenta afiliada a la cuenta que desea cambiar");
									scanf_s("%s", &AccountN, 11); //Uitlizado para ubicar la Cuenta;

									if ((verificarNc(C, AccountN) != 0) || (verifyNumber(AccountN) != 0))
									{
										printf_s("Quieres cambiar el tipo de Cuenta? (1) si, (0) No\n");
										scanf_s("%s", &l1, 3);
										if (strcmp(l1, "1") == 0)
										{
											printf_s("Nuevo Tipo de cuenta\n");
											scanf_s("%s", &Digit2, 3);

											while ((strlen(Digit2) != 2) || (Digit2 != "01") || (Digit2 != "02") || (Digit2 != "03") )
											{
												printf_s("su Tipo de cuenta no es valido.\n");
												printf_s("Tipo de cuenta (01)Corriente (02)Ahorro (03)Tarjeta de credito:  ");
												fflush(stdin);
												scanf_s("%s", &Digit2, 3);
											}
										}

										printf_s("Quieres cambiar el Saldo? (1) Si, (0) No\n");
										scanf_s("%s", &l2, 2);
										if (strcmp(l2, "1") == 0)
										{
											printf_s("Nuevo monto: \n");
											scanf_s("%li", &Amount);
										}

										printf_s("Quieres cambiar el codigo del banco? (1) Si, (0) No\n");
										scanf_s("%s", &l3, 2);
										if (strcmp(l3, "1") == 0)
										{
											printf_s("Nuevo codigo de banco: \n");
											scanf_s("%li", &Digit3, 5);
											while ((verifyNumber(Digit3) != 0) || verificarBanco(B,Digit3) != 0) {
												printf_s("El Codigo de banco no es valido, por favor coloque uno que si lo sea.");
												printf_s("Codigo de banco:  ");
												cont = cont +1;
												if(cont == 5){
													break;
												}
												fflush(stdin);
												scanf_s("%s", &Digit3, 5);
											}
											if(cont == 5){
												printf_s("\nHa intentado muchas veces.\n");
												system("pause");
												cont = 0;
												break;
											}
										}

										if((l1 != "1") || (l2 != "1") || (l3 != "1")){
											modAccount(&C, &CL, AccountN, Digit2, Digit3, &Amount, l1, l2, l3);
											ArchivoCuenta(CL, C);
										}
										else{
											printf_s("\nNo ha hecho ningun cambio");
											system("pause");
											break;
										}
									}
									else
									{
										printf_s("El numero de cuenta no existe");
										system("pause");
									}

									break;

								}
								printf_s("\n\n");
								if (o) system("pause");
								system("cls");
								if ((o5 < 0) || (o3 > 5)) printf_s("\tEL NUMERO DEBE SER ENTRE 0 Y 3\n\n");
								o5 = -1;
							}
							break;
							}
							printf_s("\n\n");
							if (o) system("pause");

							system("cls");
							if ((o2 < 0) || (o2 > 4)) printf_s("\tEL NUMERO DEBE SER ENTRE 0 Y 4\n\n");
					}
					break;

		case 2: printf_s("Tranferencia\n\n");
			printf_s("Numero de cedula del emisor: ");
			fflush(stdin);
			scanf_s("%s",&Digit4, 9);
			if ((verificarC(C, Digit4) == 1) || ((verifyNumber(Digit4) != 0))) {
				printf_s("Numero de cuenta del emisor: ");
				fflush(stdin);
				scanf_s("%s", &AccountN, 15);
				if ((verificarT(C, AccountN, Digit4) == 1) || ((verifyNumber(AccountN) != 0))) {
					printf_s("Colocar monto de la tranferencia: ");
					fflush(stdin);
					scanf_s("%li", &Amount);
					printf_s("Numero de cedula del receptor: ");
					fflush(stdin);
					scanf_s("%s",&CodeN, 9);
					if((verificarC(C, CodeN) == 1) || ((verifyNumber(CodeN) != 0))){
						printf_s("Numero de cuenta del receptor: ");
						fflush(stdin);
						scanf_s("%s", &Account, 15);
						if ((verificarT(C, Account, CodeN) == 1) || ((verifyNumber(Account) != 0))) {
							printf_s("Ano: ");
							fflush(stdin);
							scanf_s("%i", &year);
							printf_s("mes: ");
							fflush(stdin);
							scanf_s("%i", &mes);
							printf_s("Dia: ");
							fflush(stdin);
							scanf_s("%i", &Dia);
							printf_s("hora: ");
							fflush(stdin);
							scanf_s("%i", &hora);
							printf_s("Minuto: ");
							fflush(stdin);
							scanf_s("%i", &minuto);
							printf_s("Codigo de transaccion: ");
							fflush(stdin);
							scanf_s("%li", &CodeT);
							if (VerificarCodeT(T, &CodeT) == 0) {
								printf_s("Descripcion de la transferencia: ");
								scanf_s("%s\n", &Description, 100);
								printf_s("Verificacion de datos: \n");
								printf_s("Cedula del emisor: %s\n", Digit4);
								printf_s("Cuenta del emisor: %s\n", AccountN);
								printf_s("Cedula del receptor: %s\n", CodeN);
								printf_s("Cuenta del receptor: %s\n", Account);
								printf_s("Monto: %li\n", Amount);
								printf_s("Description: %s\n\n", Description);
								printf_s("Hoy es: %i/%i/%i\n", Dia,mes,year);
								printf_s("Hora: %i:%i\n", hora,minuto);
								printf_s("Codigo de transaccion: %i\n", CodeT);
								printf_s("Los datos son correctos? (01)Si, (02)No: ");
								fflush(stdin);
								scanf_s("%s\n", &l1, 3);
								if(strcmp(l1, "01") == 0){
									Tranferencia(&CL,&C,&T,Digit4,CodeN,AccountN,Account,&Amount,Description,&Dia,&mes,&year,&hora,&minuto,&CodeT);
								}

								else{
									printf_s("Se ha cancelado la transaccion.");
									system("pause");}
							}
							else{
								printf_s("Se ha cancelado la transaccion.");
								system("pause");}
						}
						else{
							printf_s("Ese numero de cuenta no pertenece a esa cedula o no existe.");
							system("pause");}
					}
					else{
						printf_s("Numero de cedula, no existe por favor agregar cedula.");
						system("pause");}
				}
				else{
					printf_s("Ese numero de cuenta no pertenece a esa cedula o no existe.");
					system("pause");}
			}
			else{
				printf_s("Numero de cedula, no existe por favor agregar cedula.");
				system("pause");}
			ArchivoTrans(CL,C,T);
			break;

		case 3:	consultas(CL);

			break;

				}
				if ((o<0) || (o>3)) printf_s("\tEL NUMERO DEBE SER ENTRE 0 Y 3\n\n");
		}

		printf_s("\n\n");
		system("cls");
	}
}