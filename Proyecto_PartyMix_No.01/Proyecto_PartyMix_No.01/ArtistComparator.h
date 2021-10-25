#pragma once
#include "Cancion.h"
#include "Comparador.h"
#include <string>

using std::string;

class ArtistComparator :
    public Comparador<Cancion>
{
public:
    virtual int compare(Cancion a, Cancion b) {
        return a.getCancion().compare(b.getCancion());
    }
};


