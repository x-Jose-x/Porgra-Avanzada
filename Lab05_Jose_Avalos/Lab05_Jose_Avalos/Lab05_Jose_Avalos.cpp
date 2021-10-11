// Lab05_Jose_Avalos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
//#include "funciones.h"
#define MAX 60

typedef struct {
	char paloCarta;
	int color;
	int estado;
	int numeroCarta;
} Carta;

Carta V[MAX]; 

typedef struct {
	Carta c;
	int base; 
	int top;
}Pila;


Pila pilas[14];

void menuPrincipal(Pila pila[]);

void menuJuego(Pila pila[]);

void reglasDelJuego(void);

void comandosDelJuego(void);

void crearCartas(Carta cartas[]);

void repartirPilas(Pila pila[]);

void barajar(Carta aux[]);

void mostrarCarta(Pila pila[], int j);

int jugadaValidaPilasDeJuego(Pila pila[], int o, int d);

int jugadaValidaPilasDeSalida(Pila pila[], int o, int d);

int lecturaEjecutarOrden(Pila pila[], int* contador);

void push(Pila pila[], int i, Carta x);

void pushVariasCartas(Pila pila[], int o, int d, int c);

int identificarCartaNoTop(Pila pila[], int o, int d, int c);

Carta pop(Pila pila[], int i, Carta x);

void crearCotas(Pila pila[]);

void overflowLocal(Pila pila[], int i);

void printStack(Pila pila[], int i);

void mostrarPilas(Pila pila[]);

int pilaLLena(Pila pila[], int i);

int sizePila(Pila pila[], int i);


int pilaVacia(Pila pila[], int i);

int gano(Pila pila[]);


void exchange(Carta cartas[], int i, int j);


void exchangePosicion(Pila pila[], int a, int b);


void reglasDelJuego(void) {

	printf("\nJuego el Solitario\n");
	printf("**********************************\n");
	printf("REGLAS DEL JUEGO\n");
	printf("Hay 7 pilas de juego, en estas solo se pueden colocar cartas\n");
	printf("que formen una secuencia decreciente consecutiva y de colores alternantes\n");
	printf("1 Pila de Reserva, donde las cartas restantes esperan ser descubiertas\n");
	printf("1 Pila de descarte, de la cual podemos tomar una carta de la pila de Reserva\n");
	printf("una por cada vez y moverla a las pilas de juego o a las Pilas de Salida\n");
	printf("4 Pilas de Salida, en estas pilas se iran apilando cada carta de un mismo palo\n");
	printf("Si se logra llenar cada una de las 13 cartas de un mismo palo en cada pila de salida\n");
	printf("se gana el juego, y se pierde cuando no se puede hacer ningun movimiento.\n");

}
void comandosDelJuego(void) {
	printf("+++++++++++++++++++++++\n");
	printf("Descarte: 	0:\n");
	printf("Reserva: 	1:[*]\n");
	printf("+++++++++++++++++++++++\n");
	printf("Pila de Juego 2:\n");
	printf("Pila de Juego 3:\n");
	printf("Pila de Juego 4:\n");
	printf("Pila de Juego 5:\n");
	printf("Pila de Juego 6:\n");
	printf("Pila de Juego 7:\n");
	printf("Pila de Juego 8:\n");
	printf("+++++++++++++++++++++++\n");
	printf("Diamantes  (D)9 :\n");
	printf("Corazones  (C)10:\n");
	printf("Trebol     (T)11:\n");
	printf("Espadas    (E)12:\n");

	printf("[Carta] [Pila origen] [Pila destino]\n");
	printf("Por ejemplo: 2 3, mover de la pila 2 a la pila 3\n");
	printf("Por ejemplo: 4 9, mover de la pila 4 a la pila de diamantes\n");
	printf("Por ejemplo: 0 3, mover de la pila descarte a la pila 4\n");
	printf("Por ejemplo: 0 10, mover de la pila descarte a la pila corazones\n");
	printf("Por ejemplo: 5 3 3, mover de la pila 5, a la pila 3, desde la carta 3\n");
	printf("Por ejemplo: 11 6, error! no se puede mover una carta de las pilas de salida\n");
	printf("Por ejemplo: d, para barajar la carta descarte y poner otra carta\n");
	printf("Por ejemplo: c, para mover mas de una carta\n");
	printf("Por ejemplo: n, empezar un nuevo juego\n");
	printf("Si la jugada es invalida, simplemente la instruccion no se lleva a cabo\n");

}
void mostrarPilas(Pila pila[]) {
	printf("\n+++++++++++++++++++++++\n");
	printf("Descarte:     0:"); printStack(pila, 0);
	printf("Reserva:      1:[*]");
	printf("\n+++++++++++++++++++++++\n\n");
	printf("Pila de Juego 2:"); printStack(pila, 2);
	printf("Pila de Juego 3:"); printStack(pila, 3);
	printf("Pila de Juego 4:"); printStack(pila, 4);
	printf("Pila de juego 5:"); printStack(pila, 5);
	printf("Pila de Juego 6:"); printStack(pila, 6);
	printf("Pila de Juego 7:"); printStack(pila, 7);
	printf("Pila de Juego 8:"); printStack(pila, 8);
	printf("\n+++++++++++++++++++++++\n");
	printf("Diamantes  (D)9 :"); printStack(pila, 9);
	printf("Corazones  (C)10:"); printStack(pila, 10);
	printf("Trebol     (T)11:"); printStack(pila, 11);
	printf("Espadas    (E)12:"); printStack(pila, 12);
}
int jugadaValidaPilasDeJuego(Pila pila[], int o, int d) {
	if (d < 2 || o == 1 || o < 0 || o > 8)  return 0;


	if (pilaVacia(pila, o)) return 0;

	if (pilaVacia(pila, d))
		if (V[pila[o].top].numeroCarta != 13) return 0;

	if (pilaVacia(pila, d) == 0) {

		if (V[pila[o].top].color == V[pila[d].top].color) return 0;
	
		if (V[pila[o].top].numeroCarta != (V[pila[d].top].numeroCarta - 1)) return 0;
	}
	return 1;
}
int jugadaValidaPilasDeSalida(Pila pila[], int o, int d) {
	if (d > 12) return 0;
	if (V[pila[o].top].paloCarta == 'D' && d != 9) return 0;
	if (V[pila[o].top].paloCarta == 'C' && d != 10) return 0;
	if (V[pila[o].top].paloCarta == 'T' && d != 11) return 0;
	if (V[pila[o].top].paloCarta == 'E' && d != 12) return 0;
	if (pilaVacia(pila, d) == 0)
		if (V[pila[o].top].numeroCarta != (V[pila[d].top].numeroCarta + 1)) return 0;

	return 1;
}
int identificarCartaNoTop(Pila pila[], int o, int d, int c) {
	int indice = -1;
	for (int i = pila[o].top; i >= pila[o].base + 1; i--) {
		if (V[i].estado == 0) break;
		if (V[i].numeroCarta == c) indice = i;
	}
	if (indice != -1) {

		if (pilaVacia(pila, d)) return indice;
		
		if (V[indice].numeroCarta == (V[pila[d].top].numeroCarta - 1)
			&& V[indice].color != V[pila[d].top].color)
			return indice;
	}
	return -1;
void pushVariasCartas(Pila pila[], int o, int d, int c) {
	Carta temp;
	int indice = identificarCartaNoTop(pila, o, d, c);
	if (indice != -1) {

	
		int count = 0;
		count = pila[o].top - indice;
		Carta cart[count + 1];
		for (int i = 0; i < count + 1; i++)
			cart[i] = pop(pila, o, temp);

		for (int i = 0; i < count + 1; i++)
			push(pila, d, cart[count - i]);

	
		if (pilaVacia(pila, o) == 0)
			V[pila[o].top].estado = 1;
	}
}
int lecturaEjecutarOrden(Pila pila[], int* contador) {
	int o, d, c;
	char opc;
	Carta aux;


	if (scanf("%d %d", &o, &d) == 2) {
	
		if (d < 9) {
		
			if (pilaVacia(pila, d)) {
				if (V[pila[o].top].numeroCarta == 13) {
					aux = pop(pila, o, aux);
					push(pila, d, aux);
					if (o != 0)
						V[pila[o].top].estado = 1;
					V[pila[d].top].estado = 1;
				}
			}
			if (jugadaValidaPilasDeJuego(pila, o, d) == 1) {

				aux = pop(pila, o, aux);
				push(pila, d, aux);
				V[pila[o].top].estado = 1;
				V[pila[d].top].estado = 1;
			}
		
		}
		else {
			if (jugadaValidaPilasDeSalida(pila, o, d) == 1) {
				aux = pop(pila, o, aux);
				push(pila, d, aux);
				V[pila[o].top].estado = 1;
				V[pila[d].top].estado = 1;
			}
		}

	}
	else if (scanf("%c", &opc) == 1) {
		
		if (opc == 'w' || opc == 'W') {
			return 1;
		}
		if (opc == 'd' || opc == 'D') {
		
			if (sizePila(pila, 1) != 0) {
				
				if (pilaVacia(pila, 0) == 1) {
					aux = pop(pila, 1, aux);
					push(pila, 0, aux);
					V[pila[0].top].estado = 1;
				}
				
				else {
					(*contador)++;
					exchangePosicion(pila, pila[0].top, pila[1].top -
						(*contador % (sizePila(pila, 1) - 1)));
					V[pila[0].top].estado = 1;
				}
			}
		}
		if (opc == 'c') {
			scanf("%d %d %d", &o, &d, &c);
			pushVariasCartas(pila, o, d, c);
		}
		if (opc == 'n') {
			system("clear");
			menuPrincipal(pila);
		}
		return 0;

	}
	if (pila)
		return 0;
}
void menuPrincipal(Pila pila[]) {
	int opc = 1;
	int value;
	while (opc) {
		printf("\t\tBienvenido al Juego El Solitario\n\n");
		
		printf("1. Reglas del Juego\n");
		printf("2. Comandos del Juego\n");
		printf("3. Empezar a jugar\n");
		printf("4. Salir\n");

		printf("Ingrese Opcion\n");

		scanf("%d", &opc);
		switch (opc) {

		case 1:	reglasDelJuego();
			break;

		case 2:	comandosDelJuego();
			break;
		case 3: menuJuego(pila);
			break;

		case 4:	opc = 0;
			break;

		default: printf("Ingrese opcion valida\n");
			break;
		}
	}
}
void push(Pila pila[], int i, Carta x) {
	pilas[13].base = MAX;
	if (pila[i].top == pila[i + 1].base)
		overflowLocal(pila, i);

	pila[i].top = pila[i].top + 1;
	V[pila[i].top] = x;
}


Carta pop(Pila pila[], int i, Carta x) {
	if (pila[i].top == pila[i].base)
		x.numeroCarta = 0; 
	else {
		x = V[pila[i].top];
		pila[i].top = pila[i].top - 1;
	}
	return x;
}
void crearCotas(Pila pila[]) {
	for (int i = 0; i <= 12; i++) 
		pila[i].base = pila[i].top = (int)(i * ((float)(MAX) / 13)); 
}
void overflowLocal(Pila pila[], int i) {
	int j = i;

	int flat = 0;
	while (pila[j].top < MAX) {
		j++;
		if (pila[j].top < pila[j + 1].base) {
			flat = 1; 
			break;
		}
	}

	if (flat == 1) {
		
		for (int k = pila[j].top; k >= pila[i + 1].base + 1; k--) // 
			V[k + 1] = V[k];

		for (int k = i + 1; k <= j; k++) {
			pila[k].base = pila[k].base + 1;
			pila[k].top = pila[k].top + 1;
		}
	}
	else {//si flat == 0
		j = i;
		while (1) {
			j--;
			if (pila[j].top < pila[j + 1].base) {
				break;
			}
		}
		for (int k = pila[j + 1].base; k < pila[i].top; k++)
			V[k] = V[k + 1];

		for (int k = j + 1; k <= i; k++) {
			pila[k].base = pila[k].base - 1;
			pila[k].top = pila[k].top - 1;
		}
	}
}
void mostrarCarta(Pila pila[], int j) {
	if (V[j].estado == 1)
		printf("[%d%c]", V[j].numeroCarta, V[j].paloCarta);
	else
		printf("[%c%c]", '*', '*');
}

void printStack(Pila pila[], int i) {
	for (int j = pila[i].base + 1; j <= pila[i].top; j++)
		mostrarCarta(pila, j);

	printf("\n");
}
void exchange(Carta cartas[], int i, int j) {
	Carta aux;
	aux = cartas[i];
	cartas[i] = cartas[j];
	cartas[j] = aux;
}
void exchangePosicion(Pila pila[], int a, int b) {
	Carta aux;
	aux = V[a];
	V[a] = V[b];
	V[b] = aux;
}
void barajar(Carta aux[]) {
	int i = 51;
	while (i >= 0) {
		srand(time(NULL));
		if (i == 0) {
			int randomPosition = rand() % 51 + 1;
			exchange(aux, randomPosition, i);
		}
		else {
			int randomPosition = rand() % i + 1;
			exchange(aux, randomPosition, i);
		}
		i--;
	}
}
void crearCartas(Carta cartas[]) {
	int a, b, c;
	a = b = c = 1;
	for (int i = 0; i < 52; i++) {
		if (i <= 12) {
			cartas[i].paloCarta = 'D';// Diamantes
			cartas[i].color = 1; //color rojo
			cartas[i].numeroCarta = i + 1;//Asigno desde el 1 al 13.
		}
		if (i > 12 && i <= 25) {
			cartas[i].paloCarta = 'C';// Corazones
			cartas[i].color = 1; //color rojo
			cartas[i].numeroCarta = a++;
		}
		if (i > 25 && i <= 38) {
			cartas[i].paloCarta = 'T';// Trebol
			cartas[i].color = 0; //color negro
			cartas[i].numeroCarta = b++;
		}
		if (i > 38) {
			cartas[i].paloCarta = 'E';// Espadas
			cartas[i].color = 0; //color negro
			cartas[i].numeroCarta = c++;
		}

	}
}
void repartirPilas(Pila pila[]) {
	crearCotas(pila);
	Carta cartas[52];
	crearCartas(cartas);
	barajar(cartas);


	// Pila descarte vacia
	// pila[0]

	// Pila reserva
	for (int k = 0; k < 24; k++) {
		push(pila, 1, cartas[k]);
		V[pila[1].base + k + 1].estado = 0;//El estado == 0, significa estan cerradas, no se ven.
	}

	// Pilas de juego.

	int aux = 24;
	for (int i = 2; i <= 8; i++) {
		for (int j = 0; j < i - 1; j++) {
			push(pila, i, cartas[aux]);
			V[pila[i].base + j + 1].estado = 0;
			aux++;
		}
		V[pila[i].top].estado = 1;
	}

}
int sizePila(Pila pila[], int i) {
	return (pila[i].top - pila[i].base);
}
int pilaLLena(Pila pila[], int i) {
	return sizePila(pila, i) == 13;
}
int pilaVacia(Pila pila[], int i) {
	return pila[i].base == pila[i].top;
}
int gano(Pila pila[]) {
	int k = 0;
	int i = 9;
	for (int j = 0; j < 4; j++)
		if (pilaLLena(pila, i + j)) k++;

	return k == 4 ? 1 : 0;
}
void menuJuego(Pila pila[]) {
	repartirPilas(pila);
	mostrarPilas(pila);
	int contador = -1;
	int flag = 0;
	while (flag != 1) {
		printf("Ingrese su jugada: \n");
		flag = lecturaEjecutarOrden(pila, &contador);
		mostrarPilas(pila);
	}
	printf("GANASTE EL JUEGO!!!, Felicitaciones!\n");

	

}

int main() {

	menuPrincipal(pilas);

}
