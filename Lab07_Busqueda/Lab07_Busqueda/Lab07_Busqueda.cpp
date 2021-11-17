#include "pch.h"

using namespace std;

int tamaño;
int Arreglo[];
int Hash[];

//Random Rnd;

System::Random Rnd;

int Binario(int valores[], int n, int x)
{
	int L = 0;
	int R = n - 1;
	while (L <= R)
	{
		int Mid = L + (R - L) / 2;
		if (valores[Mid] == x)
			return Mid;
		if (valores[Mid] > x)
			R = Mid - 1;
		else
			L = Mid + 1;
	}
	return -1;
}


int InsertaHash(int value)
{
	int Indice = value % 100;
	while (Hash[Indice] != 0 && Indice < 100)
		Indice++;
	Hash[Indice] = value;

	return Indice;
}

int BusquedaHash(int value)
{
	int Indice = value % 100;
	while (Hash[Indice] != value && Indice < 100)
	{
		Indice++;
	}

	if (Hash[Indice] == value)
		return Indice;
	else
		return -1;
}



using namespace System;

int main(array<System::String ^> ^args)
{
    Console::WriteLine("Que numero desea buscar");
	int x = Convert::ToInt16(Console::ReadLine());

	Console::WriteLine("numero solicitado" + BusquedaHash(x));

    return 0;
}
