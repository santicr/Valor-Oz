#ifndef __VALOROZVARIABLE_H
#define __VALOROZVARIABLE_H

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <math.h>

#include "ValorOz.h"

using namespace std;

class ValorOzVariable : public ValorOz{
    public:
        string referencia;
        ValorOzVariable(string entrada);
        string obtenerCadenaValor();
};

#endif