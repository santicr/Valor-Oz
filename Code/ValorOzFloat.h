#ifndef __VALOROZFLOAT_H
#define __VALOROZFLOAT_H

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <math.h>

#include "ValorOz.h"

using namespace std;

class ValorOzFloat : public ValorOz{
    private:
        float valor;
    public:
        ValorOzFloat(string entrada);
        float getVal();
        string obtenerCadenaValor();
};

#endif