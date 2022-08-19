#ifndef __VALOROZREGISTRO_H
#define __VALOROZREGISTRO_H

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <math.h>

#include "ValorOz.h"

using namespace std;

class ValorOzRegistro : public ValorOz{
    private:
        string etiqueta;
        map<string, ValorOz*> registros;
    public:
        map<string, ValorOz*> getRegistros();
        ValorOzRegistro(string entrada);
        string obtenerCadenaValor();
        string obtenerEtiqueta();
        list<string> obtenerListaCampos();
};

#endif