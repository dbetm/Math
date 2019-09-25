#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Autor: David Betancourt Montellano
// Grupo: 1CM1

//declaración de funciones genéricas...
void bienv();
void menu();
int des();
void expansion_base(int x);
void division(int y);

//funciones para algoritmo de la división
	//functions for binary
	void binario(int n);
	int pide_num();
	void llenar(int n);
	// functions for octal
	void octal(int n); //se reutiliza pide_num() 
	void llenar_octal(int n);
	// functions for hexa
	void hexa(int n);
	void llenar_hexa(int n);
	
//funciones para algoritmo expansión en base
	// function for from binary
	void desde_binario();
	int validar_binario(char num[21]);
	//functions for from octal
	void desde_octal();
	void sumaAcum(int n, int aux2);
	int validarOctal(char num[16]);
		//variables
		int suma1 = 0;
	//function for from hexa
	void desde_hexa();
	void suma_acum(int n, int aux2);
	int validar(char num[16]);
		//variables
		int suma = 0;

//Begins 'Main'
int main(int argc, char **argv) {
	int es = 1, estado = 0, aux = 0, tryagain = 0;
	
	while (es == 1) {
		if (aux == 1) break;
		else  {
			estado = des();
			if (estado == 1) {
				printf("\nDesea continuar?\nEscriba '1' para indicar que si, cualquier otra tecla para salir\n");
				scanf("%d",&tryagain);
				fflush(stdin);
				if(tryagain == 1) {
					//system(clear);
					 system("cls");
				 }
				else {
					aux = 1; 
				}
			} 
		}
	}
	return 0;
}
//A partir de aqui se definen las funciones
void bienv() {
	printf("\t\tBIENVENIDO\n\tPROGRAMA CONVERSOR DE BASES\n");
	printf("\tUA: MATEMATICAS DISCRETAS\n");
	printf("\n");
	}

int des() {
	int x = 0, num = 0, control = 0;
	char vali[6], opc;
	do {
		bienv();
		printf("\t      MENU\n");
		printf("1. Convertir de base n a base 10\n"); 
		printf("2. Convertir de base 10 a base n\n");
		printf("Si escribe mas de un caracter lo ignora\n");
		scanf("%c",&opc);
		fflush(stdin);
			
			switch(opc){
			case '1': 
				do {
					system("cls");
					printf("\nUsted ha elegido convertir de base n a base 10\n");
					printf("\nElija una opcion.  Si escribe mas de un caracter lo ignora.\n");
					printf("1. De binario a decimal\n");
					printf("2. De octal a decimal\n");
					printf("3. De hexadecimal a decimal\n");
					scanf("%s",vali);
					fflush(stdin);
					num = atoi(vali);
					if(num != 0) {
						if (num >= 1 && num <= 3) opc = 2;
						else opc = 4;
						} 
					else opc = 4;
				} while(opc < 1 || opc > 3); 
				expansion_base(num);
				return x = 1;
			case '2': 
				do {
					system("cls");
					printf("\nUsted ha elegido convertir de base 10 a base n\n");
					printf("\nElija una opcion.  Si escribe mas de un caracter lo ignora.\n");
					printf("1. Binario\n");
					printf("2. Octal\n");
					printf("3. Hexadecimal\n");
					scanf("%s",vali);
					fflush(stdin);
					num = atoi(vali);
					if(num != 0) {
						if (num >= 1 && num <= 3) opc = 2;
						else opc = 4;
						} 
					else opc = 4;
				} while(opc < 1 || opc > 3); 
				division(num);
				return x = 1;
			default:
				system("cls");
				control = 1;
			}
		} while (control == 1);
		return x;
}
void expansion_base(int x) {
	if(x==1) desde_binario();
	if(x==2) desde_octal();
	if(x==3) desde_hexa();
}
void division(int y) {
	if(y==1) binario(2);
	if(y==2) octal(8);
	if(y==3) hexa(16);
}
//funciones algoritmo de la división
	//binario
void binario(int n) {
		printf("\nHa elegido convertir a binario\n");
		llenar(pide_num());
	}
int pide_num() {
	int n = 0;
	printf("Si escribes un caracter primero te retornara 0, si combinas con numeros ignora los caracteres \n");
	do {
		printf("Dame un numero positivo: ");
		scanf("%i",&n);
		fflush(stdin);
		printf("\n");
	}while(n<0);
	return n;
}
void llenar(int n) {
	
	int arreglo[21];
	int res = 0, i = 0, a = 0;
	
	for(i = 0; i <= 21; i++) {
		res = n % 2;
		arreglo[i] = res;
		n = n / 2;
	}
	for (i = 21; i >= 0; i-- ) {
			if (arreglo[i] == 0) a++;
			else break;
		}
		
	if(a == 22) a = 21;
	
	for (i = 21-a; i >= 0; i-- ) {
			printf("%i",arreglo[i]);
		}
	printf(" <------ Binario ^_^\n");
	
}
	//octal
void octal(int n) {
	printf("\nHa elegido convertir a octal\n");
	llenar_octal(pide_num());
}
void llenar_octal(int n) {
	
	int arreglo[10];
	int res = 0, i = 0, a = 0;
	
	for(i = 0; i <= 10; i++) {
		res = n % 8;
		arreglo[i] = res;
		n = n / 8;
	}
	for (i = 10; i >= 0; i-- ) {
			if (arreglo[i] == 0) a++;
			else break;
		}
	if(a == 11) a = 10;
	
	for (i = 10-a; i >= 0; i-- ) {
			printf("%i",arreglo[i]);
		}
	printf(" <------ Octal ^_^\n");
}
	//hexa
void hexa(int n) {
	printf("\nHa elegido convertir a hexadecimal\n");
	llenar_hexa(pide_num());
}
void llenar_hexa(int n) {
	
	int arreglo[10];
	int res = 0, i = 0, a = 0;
	
	for(i = 0; i <= 10; i++) {
		res = n % 16;
		arreglo[i] = res;
		n = n / 16;
	}
	
	for (i = 10; i >= 0; i-- ) {
			if (arreglo[i] == 0) a++;
			else break;
		}
		
	if(a == 11) a = 10;
	
	for (i = 10-a; i >= 0; i-- ) {
			if(arreglo[i] == 10) printf("A");
			if(arreglo[i] == 11) printf("B");
			if(arreglo[i] == 12) printf("C");
			if(arreglo[i] == 13) printf("D");
			if(arreglo[i] == 14) printf("E");
			if(arreglo[i] == 15) printf("F");
			if(arreglo[i] < 10 || arreglo[i] > 15) printf("%i",arreglo[i]);
		}
	printf(" <------ Hexadecimal ^_^\n");
}
//funciones para expansión en base
	//binario
void desde_binario() {
	
	char alice[21];
	int i = 0, suma = 0, exp = 0, aux = 0, leng = 0, cont = 0;
	printf("\nHa elegido convertir de binario a decimal\n");
		do {
			for(i=0 ; i < 21 ; i++) alice[i]='\0'; //vaciar arreglo
			for(i = 0; i < 21; i++) alice[i] = '/'; //inicializar para poder validar
			printf("Teclea el numero: ");
			scanf("%s",alice);
			fflush(stdin);
			aux = validar_binario(alice);
		} while(aux == 1);
		
		leng = sizeof(alice)/sizeof(char);

		for(i = 0; i < leng; i++) {
			if(alice[i] == '1' || alice[i] == '0') cont++;
		}
	aux = 0; //para lograr reutilizarla
	for(i = cont-1; i >= 0; i--){
			if(alice[i] == '1'){
				aux = pow(2,exp); //hace la tarea de elevar el dos a la n potencia
				suma+= aux;
				exp++;
			}
			else exp++;
	}
		printf("%d",suma);
		printf(" <------ Decimal ^_^\n");
}
int validar_binario(char num[21]) {
	int i, x  = 0;
	for(i = 0; i < 21; i++) {
			if ((int)num[i] > 0 && (int)num[i] <=46) x = 1;
			if ((int)num[i] >= 50 && (int)num[i] <=126) x = 1;
	}
		return x;
}
	//octal
void desde_octal() {
	
	char zent[16] = " ";
	int exp = 0;
	int i = 0, leng = 0, cont = 0, error = 0;
	suma1 = 0;
	printf("\nHa elegido convertir de octal a decimal\n");
	leng = sizeof(zent)/sizeof(char);
	
	do {
		for(i=0 ; i < 16 ; i++) zent[i]='\0'; //vaciar arreglo
		for(i = 0; i < 16; i++) zent[i] = '/'; //inicializar para poder validar
		printf("Teclea el numero: ");
		scanf("%s",zent);
		fflush(stdin);
		error = validarOctal(zent);
	} while(error == 1);
		
		leng = sizeof(zent)/sizeof(char);
		
		for(i = 0; i < leng; i++) {
			if ((int)zent[i]>=48 && (int)zent[i]<=57) cont++;
			else continue;
		}
		
		for(i = cont-1; i >= 0; i--) {
			if(zent[i] == '0') {
				sumaAcum(0,exp);
				exp++;
			}
			else if(zent[i] == '1') {
				sumaAcum(1,exp);
				exp++;
			}
			else if(zent[i] == '2') {
				sumaAcum(2,exp);
				exp++;
			}
			else if(zent[i] == '3') {
				sumaAcum(3,exp);
				exp++;
			}
			else if(zent[i] == '4') {
				sumaAcum(4,exp);
				exp++;
			}
			else if(zent[i] == '5') {
				sumaAcum(5,exp);
				exp++;
			}
			else if(zent[i] == '6') {
				sumaAcum(6,exp);
				exp++;
			}
			else if(zent[i] == '7') {
				sumaAcum(7,exp);
				exp++;
			}
		}
		printf("%d",suma1);
		printf(" <------Decimal ^_^\n");
}
void sumaAcum(int n, int exp) {
	int aux2;
	aux2 = pow(8,exp);
	suma1 += aux2 * n;
}
int validarOctal(char num[16]) {
		int i, error = 0;
		
		for(i = 0; i < 16; i++) {
			if ((int)num[i] > 0 && (int)num[i] <= 46) error = 1;
			if ((int)num[i] == 47) continue;
			if ((int)num[i] >= 56 && (int)num[i] <= 126) error = 1;
		}
		return error;
}
	//hexa
void desde_hexa() {
	
	char meli[16] ;
	int exp = 0;
	int i = 0, leng = 0, cont = 0, error = 0;
	suma  = 0;
	
	printf("\nHa elegido convertir de hexadecimal a decimal\n");
	do {
		for(i=0 ; i < 16 ; i++) meli[i]='\0'; //vaciar arreglo
		for(i = 0; i < 16; i++) meli[i] = '/'; //inicializar para poder validar
		printf("Teclea el numero: ");
		scanf("%s",meli);
		fflush(stdin);
		error = validar(meli);
	} while(error == 1);
		
		leng = sizeof(meli)/sizeof(char);
		
		for(i = 0; i < leng; i++) {
			if ((int)meli[i]>=65 && (int)meli[i]<=70) cont++;
			else if ((int)meli[i]>=48 && (int)meli[i]<=57) cont++;
			else continue;
		}
		
		for(i = cont-1; i >= 0; i--) {
			if(meli[i] == 'A') {
				suma_acum(10, exp);
				exp++; 
			}
			else if(meli[i] == 'B') {
				suma_acum(11, exp);
				exp++; 
			}
			else if(meli[i] == 'C') {
				suma_acum(12, exp);
				exp++; 
			}
			else if(meli[i] == 'D') {
				suma_acum(13, exp);
				exp++; 
			}
			else if(meli[i] == 'E') {
				suma_acum(14, exp);
				exp++; 
			}
			else if(meli[i] == 'F') {
				suma_acum(15, exp);
				exp++; 
			} 
			else if(meli[i] == '0') {
				suma_acum(0,exp);
				exp++;
			}
			else if(meli[i] == '1') {
				suma_acum(1,exp);
				exp++;
			}
			else if(meli[i] == '2') {
				suma_acum(2,exp);
				exp++;
			}
			else if(meli[i] == '3') {
				suma_acum(3,exp);
				exp++;
			}
			else if(meli[i] == '4') {
				suma_acum(4,exp);
				exp++;
			}
			else if(meli[i] == '5') {
				suma_acum(5,exp);
				exp++;
			}
			else if(meli[i] == '6') {
				suma_acum(6,exp);
				exp++;
			}
			else if(meli[i] == '7') {
				suma_acum(7,exp);
				exp++;
			}
			else if(meli[i] == '8') {
				suma_acum(8,exp);
				exp++;
			}
			else if(meli[i] == '9') {
				suma_acum(9,exp);
				exp++;
			}
		}
printf("%d",suma);
printf(" <------ Decimal^_^\n");
}
void suma_acum(int n, int exp) {
	int aux2;
	aux2 = pow(16,exp);
	suma += aux2 * n;
}
int validar(char num[16]) {
		int i, error = 0;
		
		for(i = 15; i >= 0; i--) {
			if ((int)num[i] == 47) continue;
			if ((int)num[i]>0 && (int)num[i]<48) error = 1;
			if ((int)num[i]>57 && (int)num[i]<=64) error = 1;
			if ((int)num[i]>70) error = 1;
		}
		return error;
}
