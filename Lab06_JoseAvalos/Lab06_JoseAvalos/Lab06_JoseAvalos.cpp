#include "pch.h"

int max;
int min;
array<String^>^  readArchvio(String^ filepath) {

	array<String^>^ lines = System::IO::File::ReadAllLines(filepath);

	for (int i = 0; i < lines->Length; i++)
	{
		array<String^>^ line = lines[i]->Split('-');

		string name;
		MarshalString(line[0], name);

	}

	return Pokemons;
}


int Particion(int valores[], int bajo, int alto)
{
	int Pivote = valores[alto];
	int i = bajo - 1;
	for (int j = bajo; j <= alto; j++)
	{
		if (valores[j] < Pivote)
		{
			i++;
			Intercambio(&valores[i], &valores[j]);
		}
	}
	Intercambio(&valores[i + 1], &valores[alto]);
	return i + 1;
}

void Intercambio(int* a, int* b)
{
	int Temp = *a;
	*a = *b;
	*b = Temp;
}

void Selection(int valores[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (valores[min] > valores[j])
				min = j;
		}

		int aux = valores[i];
		valores[i] = valores[min];
		valores[min] = aux;
	}
	for (int i = 0; i < n; i++)
	{
		Console::WriteLine(valores[i]);
	}
}

void Shell(int valores[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int Temp = valores[i];
			int j;
			for (j = i; j >= gap && valores[j - gap] > Temp; j -= gap)
				valores[j] = valores[j - gap];
			valores[j] = Temp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		Console::WriteLine(valores[i]);
	}
}

void QuickSort(int valores[], int bajo, int alto)
{
	if (bajo < alto)
	{
		int Pi = Particion(valores, bajo, alto);
		QuickSort(valores, bajo, Pi - 1);
		QuickSort(valores, Pi + 1, alto);
	}
	for (int i = bajo; i <= alto; i++)
	{
		Console::WriteLine(valores[i]);
	}
	Console::WriteLine("");

}
using namespace System;

int main(array<System::String ^> ^args)
{
	int x =  0;
	Console::WriteLine("\n0. Selectio sort:\n");
	Console::WriteLine("\n1. QuickSort:\n");
	Console::WriteLine("\n2. Shell sort"\n );
	x = Convert::ToInt16(Console::ReadLine());
	switch (x)
	{
	case 0:
		Selection(rreadArchvio(), max);
		break;
	case 1:
		QuickSort(readArchvio(), max, min)
		break;

	case 2:
		Shell(readArchvio(), max)
		break;
	}
} while (x != 3);

    return 0;
}
