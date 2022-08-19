#ifndef __VALOROZUNDERSCORE_H
#define __VALOROZUNDERSCORE_H

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <math.h>

#include "ValorOz.h"

using namespace std;

class ValorOzUnderscore : public ValorOz{
    private:
        string valor = "_";
    public:
        string getVal();
        ValorOzUnderscore(string entrada);
        string obtenerCadenaValor();
};

#endif