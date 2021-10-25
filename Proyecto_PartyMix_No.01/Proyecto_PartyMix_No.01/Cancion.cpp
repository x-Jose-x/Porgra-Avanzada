#include "pch.h"
#include "Cancion.h"

Cancion::Cancion(int no, string cancion, string artista)
{
	this->cancion = cancion;
	this->artista = artista;
	this->no = no;

}

int Cancion::getId()
{
	return this->no;
}

string Cancion::getCancion()
{
	return this->cancion;
}

string Cancion::getArtista()
{
	return this->artista;
}
