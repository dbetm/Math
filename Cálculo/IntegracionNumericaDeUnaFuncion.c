#include <stdio.h>
#include <stdlib.h>

// NOTA: Reemplazar <<system("clear");>>  por <<system("cls");>> para que funcione en Windows

float datos[5]; //aquí guardo las aproximaciones obtenidas

void message();
int pide_datos(int opc);
float obtenerAproximaciones(int n, int a, int b, int op);
int errores();

int main(int argc, char **argv) {
	int n, a, b, aux = 0, opc = 0, cont = 0; // indicador = 0;
	message();
	do {
		n = pide_datos(0); //pido el número de particiones
		a = pide_datos(1); //pido el límite inferior
		b = pide_datos(2); //pido el límite superior
		if(a > b) {
			//indicador = 1;
			aux = b;
			b = a;
			a = aux;
		}
		printf("\nLos valores de las aproximaciones son:\n");
		datos[0] = obtenerAproximaciones(n, a, b, 0); //para R
		//if(indicador == 1) datos[0] = datos[0] * -1;
		printf("---> Tomando los extremos de la DERECHA es: %f\n", datos[0]);
		datos[1] = obtenerAproximaciones(n, a, b, 1); //para L
		//f(indicador == 1) datos[1] = datos[1] * -1;
		printf("---> Tomando los extremos de la IZQUIERDA es: %f\n", datos[1]);
		datos[2] = obtenerAproximaciones(n, a, b, 2); 
		printf("---> Con la regla del TRAPECIO: %f\n", datos[2]);
		datos[3] = obtenerAproximaciones(n, a, b, 3); 
		printf("---> Con la regla del PUNTO MEDIO: %f\n", datos[3]);
		do {
			if(cont == 0) {
				printf("\nElija qué hacer\n");
				printf("1. Calcular errores (si tiene el valor obtenido con TFC)\n");
				printf("2. Comenzar de nuevo\n");
				printf("3. Salir\n");
				printf("--> ");
			}
			else printf("Intentalo de nuevo: ");
			scanf("%d", &opc);
			if(opc < 1 || opc > 3) cont++;
		} while(opc < 1 || opc > 3);
		if(opc == 1) {
			opc = errores();
		}
		if(opc == 2) {
			system("clear"); 
			continue;
		} 
		if(opc == 3) {
			system("clear");
			printf("¡Adiós!");
			break;
		} 
	} while(opc == 2);
	return 0;
}
void message() {
	printf("\tUPIIZ - INSTITUTO POLITÉCNICO NACIONAL\n");
	printf("\tUA: Cálculo\n");
	printf("\tDocente: Margarito Hernández Venegas\n");
	printf("\tAlumno: David Betancourt Montellano\n\n");
	printf("Objetivo del programa: Realizar integración numérica a la función 1/x,");
	printf("\na partir de la regla del punto medio, del trapecio, y tomando los extremos\n");
	printf("de la izquierda y derecha para sumar rectángulos.\n");
	printf("\nPresione enter para continuar ---> ");
	getchar();
	fflush(stdin);
	system("clear");
}
int pide_datos(int opc) {
	int valor = 0;
	if(opc == 0 )printf("\nNOTA: 'n' representa la cantidad de particiones");
	if(opc == 0 )printf("\nDame n: ");
	if(opc == 1 )printf("Ingresa el límite inferior: ");
	if(opc == 2 )printf("Ingresa el límite superior: ");
	scanf("%d", &valor);
	fflush(stdin);
	return valor;
} 
float obtenerAproximaciones(int n, int a, int b, int op) {
	//Para R op = 0
	//Para L op = 1
	//Para regla del trapecio op = 2
	//Para regla del punto medio op = 3
	int i;
	float anchoRect = 0, suma = 0, adder = 0, intervalo = 0, aux = 0;
	anchoRect = (float)(b-a)/n;
	if(op == 0)intervalo = (float) anchoRect + a; //para R
	if(op == 1)intervalo = (float) a; //para L
	if(op == 2) {
		intervalo = (float) a;
		anchoRect = anchoRect/2;
		aux = (float)1/b;
		suma += anchoRect*aux;
	}
	if(op == 3) {
		intervalo = (float) a + a + anchoRect;
		intervalo = intervalo / 2;
	}
	for(i = 0; i < n; i++) {
		if(op == 2) {
			if(i == 0) adder = (anchoRect)*(1/intervalo);
			else adder = (anchoRect)*(2/intervalo);
		}
		else adder = (anchoRect)*(1/intervalo);
		suma += adder;
		if(op == 2) intervalo += anchoRect*2;
		else intervalo += anchoRect;
	}
	return suma;
}
int errores() {
	int i, opc = 0, cont = 0;
	float error = 0, tfc = 0;
	
	printf("Por favor ingrese el valor obtenido con TFC: ");
	scanf("%f",&tfc);
	
	printf("Los errores son:\n");
	for(i = 0; i < 4; i++) {
		error = tfc - datos[i];
		if(i == 0) printf("E_R = %f\n", error);
		if(i == 1) printf("E_L = %f\n", error);
		if(i == 2) printf("E_T = %f\n", error);
		if(i == 3) printf("E_M = %f\n", error);
	}
	do {
		if(cont == 0) {
			printf("\nElija qué hacer\n");
			printf("1. Comenzar de nuevo\n");
			printf("2. Salir\n");
			printf("--> ");
		}
		else printf("Intentalo de nuevo: ");
		scanf("%d", &opc);
		if(opc < 1 || opc > 2) cont++;
	} while(opc < 1 || opc > 2);
	
	if(opc == 1) return 2;
	if(opc == 2) return 3;
	
	return 0;
}
