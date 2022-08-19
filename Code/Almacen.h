#ifndef __ALMACEN
#define __ALMACEN

#include "ValorOz.h"
#include "ValorOzInt.h"
#include "ValorOzFloat.h"
#include "ValorOzRegistro.h"
#include "ValorOzVariable.h"
#include "ValorOzUnderscore.h"

using namespace std;

class Almacen{
    public:
        map<string, ValorOz*> almacen;
        Almacen();
        ValorOz* recursion(ValorOz*);
        void crearAlmacenLleno(map <string, ValorOz*>);
        void imprimirAlmacen();
        void imprimirRegistros(ValorOzRegistro*);
        void consultarVariable(string);
        bool consultarLigaduraVariable(string);
        void modificarVariable(string, ValorOz*);
        void agregarVariable(string);
        list<string> obtenerListaVariables();
        void unificarVariables(string, string);
};

#endif