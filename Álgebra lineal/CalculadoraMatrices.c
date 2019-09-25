#include <stdio.h>
#include <stdlib.h>

//Global
float A[20][20] = {{0}};
float B[10][10] = {0};
int datos[20] = {0};

//Funciones genéricas
void msj();
void mostrar_matriz(int n, int m, int opt, int opc);
int mainMenu();
int validarEnteros(); //para menús, # de filas, columnas...
float validarFlotantes(int i, int j, int opc); //para valores 
void inicializa(int n, int m);

int menuOp();
void tutorial();

//Para det
void determinante();
void pedir_datosDet(int n, int m);
float calcularDet();
//Para transpuesta
void transpuesta();
void pedir_datosTrans(int n, int m);
void suma_resta(int opc);
int pedirDatosSR(int numero);
int comprobarSR(int num);
void SR(int num, int n, int m, int opc);
//Para multiplica por un escalar
void multiplicacion_escalar();
void multiplicar_escalar(int n, int m, float alfa);
//Para producto punto
void producto_punto();
int datosPunto(int numero);
int comprobarPunto(int num);
void calculoPunto(int num, int dim);
//Para multiplicación de matrices
void multiplicacion_matrices();
int datosMMatriz(int n);
void valoresMatrices(int opc);
void multiplicarMatrices();
float multiplicarMatricesX2(int i, int j);

int main(int argc, char **argv) {
	
	mainMenu();
	
	return 0;
}
void msj() {
	printf("\tUPIIZ - INSTITUTO POLITÉCNICO NACIONAL\n");
	printf("\tUA: Álgebra lineal\n");
	printf("\tTema del proyecto: Matrices\n");
	printf("\tDocente: Mbe Koua Christophe N'djatchi\n");
	printf("\tAlumno: David Betancourt Montellano\n\n");
}
int mainMenu() {
	int opt = 0, continuar = 0;
		do {
			do {
				system("clear");
				msj();
				printf("<-------------Menú principal------------->\n\n");
				printf("1. Obtener determinante para matriz de 3x3.\n");
				printf("2. Operaciones con matrices.\n");
				printf("3. Transponer matriz\n");
				printf("4. ¿Cómo ingresar datos? (Tutorial)\n");
				printf("5. Salir\n");
				printf("--> ");
				opt = validarEnteros(0, 0);
			} while(opt < 1 || opt > 5);
			switch(opt) {
				case 1: 
					determinante();
					break;
				case 2: 
					menuOp();
					break;
				case 3: 
					transpuesta();
					break;
				case 4: 
					tutorial();
					break;
				case 5: 
					printf("!Adiós!");
					return 0;
			}
		system("clear");
		inicializa(20, 20);
	/*	printf("¿Desea quedarse en el menú principal?\nPresione 1 para indicar que sí, y cualquier otro número para salir.\n");
		continuar = validarEnteros(0, 0);
		*/
		//if(continuar != 1) printf("!Adiós!");
	} while(continuar == 0);
	return 0;
}
int validarEnteros() {
	int valor = 0, ok = 0, ch = 0;
	do {
		fflush(stdout);
		if ((ok = scanf("%d", &valor)) == EOF)
		return EXIT_FAILURE;
					  
		if ((ch = getchar()) != '\n') {
		ok = 0;
		printf("Vuelva a intentarlo: ");
		while ((ch = getchar()) != EOF && ch != '\n');
		}
	} while (!ok);
	return valor;
}
float validarFlotantes(int i, int j, int opc) {
	int alert = 0;
	float ok = 0, ch, num = 0;
	do {
		if(alert == 0 && opc == 0)printf("Valor de posición (%d,%d): ", i, j);
		if(alert == 0 && opc == 1)printf("Valor de posición %d: ", j);
		if(alert == 0 && opc == 2)printf("Valor de posición (%d,%d): ", i-10, j-10);
		fflush(stdout);
		if ((ok = scanf("%f", &num)) == EOF)
			return EXIT_FAILURE;
				  
		if ((ch = getchar()) != '\n'){
			ok = 0;
			alert = 1;
			printf("Vuelve a intentarlo: ");
		while ((ch = getchar()) != EOF && ch != '\n');
		}
	} while (!ok);
			
	return num;
}
void tutorial() {
	int i, j;
	system("clear");
	printf("TUTORIAL\n");
	printf("1. Cuando se tiene una matriz de 3 filas por 2 columnas (dimensiones)\n se dice que es una matriz de mxn.\n\n");
	printf("2. Las posiciones en una matriz se ven de la siguiente manera: \n\n");
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 2; j++) {
			printf(" (%d,%d) ", i, j);
		}
		printf("\n");
	}
	printf("\nA continuación deberá llenar una matriz de 3x2\n");
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 2; j++) {
			B[i][j] = validarFlotantes(i, j, 0);
		}
		printf("\n");
	}
	printf("\nEl resultado es el siguiente:\n");
	mostrar_matriz(3, 2, 2, 0);
	printf("\nBien hecho, presione una tecla para continuar --> ");
	getchar();
	fflush(stdin);
}
void mostrar_matriz(int n, int m, int opt, int opc) {
	int i, j, aux = 0, aux2 = 0;
	if(opc == 1) { //para la transpuesta
		aux2 = m;
		m = n;
		n = aux2;
	}
	if(opt == 1) aux = 10;
		for(i = aux; i < n+aux; i++)  {
			for(j = aux; j < m+aux; j++) {
				if(opt == 2) {
					if(B[i][j] < 10) {
						if(B[i][j] < 0) printf("  %.1f", B[i][j]);
						else printf("   %.1f", B[i][j]);
					}
					else if(B[i][j] >= 10 && B[i][j] < 100) printf("  %.1f", B[i][j]);
					else printf(" %.1f", B[i][j]);
				}
				else {
					if(A[i][j] < 10) {
						if(A[i][j] < 0) printf("  %.1f", A[i][j]);
						else printf("   %.1f", A[i][j]);
					}
					else if(A[i][j] >= 10 && A[i][j] < 100) printf("  %.1f", A[i][j]);
					else printf(" %.1f", A[i][j]);
				}
			}
			printf("\n");
		}
}
//PARA EL DETERMINANTE DE UNA MATRIZ DE 3X3
void determinante() {
	int n = 3, m = 3, opc = 0;
	float suma = 0;
	do {
		system("clear");
		printf("DETERMINANTE PARA MATRIZ DE ORDEN 3\n");
		printf("Estimado usuari@ a continuación se le pedirán los valores de matriz.\n\n");
		pedir_datosDet(n, m);
		suma = calcularDet(n, m);
		system("clear");
		printf("\nEl determinante de la matriz es: %.2f\n", suma);
		mostrar_matriz(n, m, 0, 0);
		printf("\n¿Quiere obtener otro determinante?\nPresione 1 para indicar que sí, cualquier otro número para continuar\n");
		opc = validarEnteros();
	} while(opc == 1);
}
void pedir_datosDet(int n, int m) {
	int i, j, cont = 0;
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			A[i][j] = validarFlotantes(i, j, 0);
			if(j < 2) { //agregar las dos columnas 
				A[i][j+3] = A[i][j];
			}
		cont++;
		}
	}
}
float calcularDet() { 
	int i, j, k; //índices
	float suma = 1, suma_total = 0;
	//para sumar  valores positivos
	for(k = 0; k < 3; k++) {
		j = k;
		for(i = 0; i < 3; i++) {
			suma *= A[i][j];
			j++;
		}
		suma_total += suma;
		suma = 1;
	}
	//para sumar  valores negativos
	for(k = 0; k < 3; k++) {
		j = k;
		for(i = 2; i >= 0; i--) {
			suma *= A[i][j];
			j++;
		}
		suma_total += suma*-1;
		suma = 1;
	}
	return suma_total;
}
//PARA TRANSPOSICIÓN DE UNA MATRIZ DE MxN
void transpuesta() {
	int opc = 0, n = 0, m = 0;
	do {
		system("clear");
		printf("TRANSPOSICIÓN DE UNA MATRIZ\n");
		do {
			printf("Ingrese el número de filas de la matriz: ");
			n = validarEnteros();
		} while(n < 1 || n > 10);
		do {
			printf("Ingrese el número de columnas de la matriz: ");
			m = validarEnteros();
		} while(m < 1 || m > 10);
		printf("\n");
		
		pedir_datosTrans(n, m);
		printf("\nLa matriz transpuesta es la siguiente: \n\n");
		mostrar_matriz(n, m, -2, 0);
		
		printf("\n¿Quiere hacerlo otra vez?\nPresione 1 para indicar que sí, cualquier otro número para continuar\n");
		opc = validarEnteros();
		
	} while(opc == 1);
}
void pedir_datosTrans(int n, int m) {
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			A[j][i] = validarFlotantes(i, j, 0); //se lee y transpone
		}
	}
	
}
//PARA OPERACIONES CON MATRICES
int menuOp() {
	int opt = 0, continuar = 0;
		do {
			do {
				system("clear");
				printf("OPERACIONES CON MATRICES\n");
				printf("Elija una opción\n");
				printf("1. Multiplicar matriz por un escalar (constante).\n");
				printf("2. Producto punto (interior o escalar).\n");
				printf("3. Multiplicación de 2 matrices.\n");
				printf("4. Sumar.\n");
				printf("5. Restar.\n");
				printf("6. Volver al menú principal.\n");
				printf("--> ");
				opt = validarEnteros();
			} while(opt < 1 || opt > 6);
			switch(opt) {
				case 1: 
					system("clear");
					multiplicacion_escalar();
					break;
				case 2: 
					system("clear");
					producto_punto();
					break;
				case 3: 
					multiplicacion_matrices();
					break;
				case 4:
					suma_resta(1);
					break;
				case 5: 
					suma_resta(2);
					break;
				case 6: 
					return 0;
					break;
			}
		system("clear");
	} while(continuar == 0);
	return EXIT_SUCCESS;
}
// --------------------> SUMA/RESTA
void suma_resta(int opc) {
	int numero = 0, aux = 1;
	do {
		system("clear");
		
		do {
			if(opc == 1) printf("SUMA DE MATRICES\n");
			if(opc == 2) printf("RESTA DE MATRICES\n");
			if(opc == 1)printf("¿Cuántas matrices desea sumar? ");
			if(opc == 2)printf("¿Cuántas matrices desea restar? ");
			numero = validarEnteros();
			system("clear");
			if(opc == 1) printf("SUMA DE MATRICES\n");
			if(opc == 2) printf("RESTA DE MATRICES\n");
			if(numero < 2 || numero > 10) {
				system("clear");
				printf("Estimado usuario debe ingresar un número mayor o igual a 2 y menor a 10\n");
			} 
		} while(numero < 2 || numero > 10);
		aux = pedirDatosSR(numero);
		if(aux == 1) {
			SR(numero, datos[0], datos[1], opc); //parámetros: número de matrices, #filas, #columnas
			printf("\n\tResultado\n\n");
			mostrar_matriz(datos[0], datos[1], 0, 0);
			printf("\n\n");
			printf("¿Desea intentar otra vez?\nPresione 0 para indicar que sí. Otro para continuar-->  ");
			aux = validarEnteros();
		}
		if(aux == 2) break;
		if(aux == 0) system("clear");
	} while (aux == 0);
}
int pedirDatosSR(int numero) {
	int i = 0, valido = 1, a = 0;
		for(i = 0; i < numero; i++) {
			do {
				printf("Para matriz %d.\n", i+1);
				printf("Ingrese el número de filas: ");
				datos[a] = validarEnteros();
			} while(datos[a] < 0 || datos[a] > 10);
			a++;
			do {
				printf("Ingrese el número de columnas: ");
				datos[a] = validarEnteros();
			} while(datos[a] < 0 || datos[a] > 10);
			a++;
			printf("\n");
		}
		valido = comprobarSR(numero); //para validar opc = 0
		if(valido == 0) {
			printf("No es posible sumar las matrices, pues las dimensiones son diferentes\n");
			printf("Presione 0 para volver a intentar y cualquier otro número para continuar -->  ");
			valido = validarEnteros();
			if(valido == 0) return 0;
			else return 2;
		}
	return 1;
}
int comprobarSR(int num) {
	int i = 0;
	
		for(i = 0; i < num; i++) {
			if(datos[i] != datos[i+2]) return 0;
		}
	return 1;
}
void SR(int num, int n, int m, int opc) { 
	int i, j, k = 0;
	float aux = 0;
	system("clear");
	if(opc == 2) printf("RESTA DE MATRICES\nLas dimensiones de sus matrices a restar son: %dx%d\n", n, m);
	if(opc == 1) printf("SUMA DE MATRICES\nLas dimensiones de sus matrices a sumar son: %dx%d\n", n, m);
	inicializa(n, m);
	while(k < num) {
		printf("\nValores para matriz %d.\n", k+1);
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				aux = validarFlotantes(i, j, 0);
				if(opc == 1) A[i][j] += aux; //<--suma
				//resta
				if(opc == 2 && k%2 == 0) A[i][j] = aux;
				if(opc == 2 && k%2 != 0) A[i][j] = A[i][j] - aux;
			}
		}
		k++;
	}//ciclo para sumar/restar las n matrices
}
void inicializa(int n, int m) {
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			A[i][j] = 0;
		}
	}
}
//MULTIPLICACIONES
// -----------> Multiplicación por un escalar.
void multiplicacion_escalar() {
	int n = 0, m = 0;
	float alfa = 0;
	printf("MULTIPLICACIÓN POR UN ESCALAR\n");
	do {
		printf("Ingrese el número de filas de la matriz: ");
		n = validarEnteros();
		fflush(stdin);
		if(n <= 0 || n  > 10) printf("El número debe ser mayor a 0 y menor a 10\n");
	} while(n <= 0 || n  > 10);
	printf("\n");
	do {
		printf("Ingrese el numero de columnas de la matriz: ");
		m = validarEnteros();
		fflush(stdin);
		if(m <= 0 || m  > 10) printf("El número debe ser mayor a 0 y menor a 10\n");
	} while(m <= 0 || m  > 10);
	
	printf("Ahora la constante: ");
	alfa = validarFlotantes(0, 0, -1);
	fflush(stdin);
	
	multiplicar_escalar(n, m, alfa);
	printf("\El resultado es: \n");
	mostrar_matriz(n, m, 0, 0);
	printf("\nPresione una tecla para continuar -->");
	getchar();
	
}
void multiplicar_escalar(int n, int m, float alfa) {
	int i, j;
	system("clear");
	printf("MULTIPLICACIÓN POR UN ESCALAR\n");
	printf("Se multiplicara una matriz  de %d x %d por una constante = %.2f\n", n, m, alfa);
	printf("\nIngrese los valores de la matriz\n");
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				A[i][j] = validarFlotantes(i, j, 0);
				A[i][j] *= alfa;
			}
			printf("\n");
		}
}
// -----------> Producto punto
void producto_punto() {
	int numero = 0, aux = 0;
	printf("PRODUCTO PUNTO\n");
	do {
		printf("¿Cuántos vectores desea multiplicar? ");
		do {
			numero = validarEnteros();
			if(numero <= 1 || numero >= 20) printf("Vuelva a intentarlo: ");
		} while(numero <= 1 || numero >= 20);
		aux = datosPunto(numero);
		if(aux == 2) break;
		if(aux == 1) {
			 calculoPunto(numero, datos[0]);
		}
	} while(aux == 0);
}
int datosPunto(int numero) {
	int i = 0, valido = 1;
		for(i = 0; i < numero; i++) {
			do {
				printf("Para vector %d.\n", i+1);
				printf("Ingrese el número de elementos: ");
				datos[i] = validarEnteros();
				if(datos[i] <= 0 || datos[i] > 10) printf("Debe ser mayor a 0 y menor 10\n");
			} while(datos[i] <= 0 || datos[i] > 10);
			printf("\n");
		}
		valido = comprobarPunto(numero); //para validar es opc = 0
		if(valido == 0) {
			printf("No es posible realizar el producto punto, pues las dimensiones son diferentes\n");
			printf("Presione 0 para volver a intentar y cualquier otro número para salir: ");
			valido = validarEnteros();
			if(valido == 0) return 0;
			else return 2;
		}
	return 1;
}
int comprobarPunto(int num) {
	int i = 0;
	num = num -1;
		for(i = 0; i < num; i++) {
			if(datos[i] != datos[i+1]) return 0;
		}
	return 1;
}
void calculoPunto(int num, int dim) {
	
	int i = 0, j = 0;
	float suma = 0, aux = 0;
	system("clear");
	printf("PRODUCTO PUNTO\n");
	//printf("El número de elementos del vector es %d\n", dim);
	while(i < num) {
		printf("\nValores para vector %d.\n", i+1);
		for(j = 0; j < dim; j++) {
			A[i][j] = validarFlotantes(0, j, 1);
		}
		i++;
	}
	for(j = 0; j < dim; j++) {
		aux = 1;
		for(i = 0; i < num; i++) {
			aux = aux * A[i][j];
		}
		suma += aux;
	}
	printf("\nEl resultado del producto punto es: %.f\n", suma);
	printf("\nPresione una tecla para continuar -->");
	getchar();
}
// -----------> Multiplicación de matrices
void multiplicacion_matrices() {
	int n = 2, condicion = 0;
	system("clear");
	printf("MULTIPLICACIÓN DE MATRICES\n");
	condicion = datosMMatriz(n);
	
	if(condicion == 1) {
		valoresMatrices(0);
		valoresMatrices(1);
		multiplicarMatrices();
		system("clear");
		printf("MULTIPLICACIÓN DE MATRICES\n");
		printf("\n-------Matriz A------------------------------------\n");
		mostrar_matriz(datos[0], datos[1], 0, 0);
		printf("\n-------Matriz B------------------------------------\n");
		mostrar_matriz(datos[2], datos[3], 1, 0); //1 para que sea imprima los valores de la segunda matriz
		printf("\nLa multiplicación de las matrices de arriba es: \n");
		mostrar_matriz(datos[0], datos[3], 2, 0); //mostrar resultado de la multiplicación
		printf("\nPresione una tecla para continuar -->");
		getchar();
	}
	else {
		printf("Presione una tecla para continuar --->  ");
		getchar();
		fflush(stdout);
	}
}
int datosMMatriz(int n) {
	int i = 0, a = 0;
		for(i = 0; i < 2; i++) { //para las 2 matrices
			printf("Para matriz %d.\n", i+1);
			do {
				printf("Ingrese el número de filas: ");
				datos[a] = validarEnteros();
			} while(datos[a] <= 0 || datos[a] > 10);
			a++;
			do {
				printf("Ingrese el número de columnas: ");
				datos[a] = validarEnteros();
			} while(datos[a] <= 0 || datos[a] > 10);
			a++;
			printf("\n");
		}
		if(datos[1] == datos[2]) {
			printf("Se pueden multiplicar\n");
			return 1;
		}
		else {
			printf("No es posible multiplicar. Por definción el producto de A y B sólo está definido\n");
			printf("cuando el número de filas de B es exactamente igual al número de columnas de A.\n\n");
			return 0;
		} 
	return EXIT_SUCCESS;
}
void valoresMatrices(int opc) {
	int i, j, m = 0, n = 0, aux = 0;
	if(opc == 0) {
		n = datos[0];
		m = datos[1];
	}
	else {
		n = datos[2];
		m = datos[3];
		aux = 10;
	}
	
	if(opc == 0) {
		printf("\nIngrese los valores de la matriz A\n");
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				A[i][j] = validarFlotantes(i, j, 0);
			}
		} 
	}
	else {
		printf("\nIngrese los valores de la matriz B\n");
		for(i = aux; i < n+aux; i++) {
			for(j = aux; j < m+aux; j++) {
				A[i][j] = validarFlotantes(i, j, 2);
			}
		} 
	}	
}
void multiplicarMatrices() {
	int i, j, n = datos[0], m = datos[3];
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {	
			B[i][j] = multiplicarMatricesX2(i, j);
		}
	}
}
float multiplicarMatricesX2(int i, int j) {
	int k, n = datos[1];
	float valor = 0;
	for(k = 0; k < n; k++) {
		//printf("elemento de A %d, de B%d\n", A[i][k], A[k+10][j+10]);
		valor += A[i][k] * A[k+10][j+10];
	}
	//printf("valor es %d\n", valor);
	return valor;
}
