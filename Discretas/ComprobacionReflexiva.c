#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Global variables
int a = 0; 		//# de elementos de A
int r = 0; 		//numero de elementos de la relacion
int num_a = 0; 	//pares iguales
int cont = 0; 	//para hacer la comparación con a
int p1, p2; 	//posiciones para generar matriz
int error = 0;

//Arrays
int A[20];
int R[20][2];
int Aux[20];
int matriz[20][20];

//Functions
void pedir_datos();
void pedir_pares();
int repetidos(int x, int num);
void validacion(int n);
void contar_pares();
void comprobacion();
void inicializa();
void obtener_p();
void mostrar();

int main(int argc, char **argv)
{
	int again;
	printf("Para un correcto funcionamiento del programa NO ingrese caracteres\nSolo numeros enteros, presione una tecla para comenzar\n");
	getch();
	//para preguntar si desea continuar el usuario
	do{
		system("cls");
		pedir_datos();
		pedir_pares();
		if(error == 0) {
			contar_pares();
			comprobacion();
			inicializa();
			obtener_p();
			mostrar();
			printf("Desea intentar otra vez? Presione 1 para indicar que si\n");
			scanf("%d",&again);
			if(again == 1) continue;
			else break;
		}
		else printf("No es posible realizar el calculo, entrada no valida.\nPosiblemente el valor que ingreso no pertenece a A\n");
	}while(again == 1);
	return 0;
}
void pedir_datos() {
	int k, aux = 0, rep;
	
	printf("Programa funcionando...\n");
	printf("Restricciones: el # de elementos de A debe ser mayor a 0, y menor o igual a 20, igual para el numero de relaciones\nPresione una tecla para continuar..."); 
	getch();
	
	do {
		system("cls");
		printf("\nDame el numero de elementos de A: ");
		scanf("%d",&a);
		fflush(stdin);
		if(a <= 0 || a > 20) aux = 1;
		else aux = 0;
		printf("\n");
	}while(aux == 1);
	
	aux = 0;
	for(k = 0; k < a; k++) {
		do {
			printf("Ingresar el elemento a_%d: ",k+1);
			scanf("%d",&A[k]);
			fflush(stdin);
			rep = repetidos(A[k],k);
			if (rep == 1) {
				printf("Por favor, no repita el elemento\n");
				aux = 1;
			} 
			else aux = 0;
		}while(aux == 1);
	}
	aux = 0;
	do {
		printf("\nDame el numero de elementos de la relacion sobre A (R)\n");
		scanf("%d",&r);
		fflush(stdin);
		if(r <= 0 || r > 20) aux = 1;
		else aux = 0;
	}while(aux == 1);
}
int repetidos(int x, int num) {
	int k, adios; 
	for(k = 0; k < num; k++) {
		if(x == A[k]) {
			adios = 1;
			break;
		}
	}
	if(adios == 1) return 1;
	else return 0;
}
void pedir_pares() {
	int i, j = 0;
	printf("Recordatorio: Solo funciona para enteros \n");
	for(i = 0; i < r; i++) {
		printf("Dame par a: ");
		scanf("%d",&R[i][j]);
		fflush(stdin);
		validacion(R[i][j]);
		if(error == 1) { 
			break;
		}
		
		printf("Dame par b: ");
		scanf("%d",&R[i][j+1]);
		fflush(stdin);
		validacion(R[i][j+1]);
		if(error == 1) { 
			break;
		}
		printf("\n");
	}
}
void contar_pares() {
	int i, k;
	
	for(i = 0; i < r; i++) {
		
		if(R[i][0] == R[i][1]) {
			Aux[k]= R[i][0];
			num_a++;
			k++;
		}
	}
}
void comprobacion() {
	
	int k, i;
	
	for(k = 0; k < a; k++) {
		for(i = 0; i < num_a; i++) {
			if(A[k] == Aux[i]) {
				cont++;
				break;
			}
		}
	}
}
void inicializa() {
	int i, j;
	//Para llenarla con ceros
	for(i = 0; i < a; i++) {
		for(j = 0; j < a; j++) {
			matriz[i][j] = 0;
		}
	}
}
void obtener_p() {
	int i, k, opt = 0;
	
	for(i = 0; i < r; i++) {
		for(k = 0; k < a; k++) {
				if(R[i][0] == A[k]) {
					p1 = k;
					opt++;
				}
				if(R[i][1] == A[k]) {
					p2 = k;
					opt++;
				}
				if (opt == 2) {
					opt = 0;
					break;
				} 
		}
		matriz[p2][p1] = 1;
	}
	
}
void mostrar() {
	int i, j;
	system("cls");
	if(a == cont) printf("La relacion es reflexiva\nComo se puede observar en la matriz:\n");
	else printf("La relacion no es reflexiva\nComo se puede observar en la matriz:\n");
	
	for(i = 0; i < a; i++) {
		for(j = 0; j < a; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}
void validacion(int n) {
	int k = 0;
	
	while(k < a) {
		if (n == A[k]) {
			error = 0;
			break;
		 }
		else {
			error = 1;
		}
		k++;
	}
}

