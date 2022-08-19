#ifndef __VALOROZINT_H
#define __VALOROZINT_H

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <math.h>

#include "ValorOz.h"

using namespace std;

class ValorOzInt : public ValorOz{
    private:
        int valor;
    public:
        ValorOzInt(string entrada);
        int getVal();
        string obtenerCadenaValor();
};

#endif