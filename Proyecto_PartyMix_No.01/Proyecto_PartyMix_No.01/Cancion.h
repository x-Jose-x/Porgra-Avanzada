#pragma once
#include <string>

using std::string;

class Cancion
{
	int no;
	string cancion;
	string artista;


public:
	Cancion(int no, string cancion, string artista);

	int getId();
	string getCancion();
	string getArtista();

};

