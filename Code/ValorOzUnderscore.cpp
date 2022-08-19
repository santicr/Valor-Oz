#include "ValorOz.h"
#include "ValorOzUnderscore.h"
#include "Almacen.h"


ValorOzUnderscore::ValorOzUnderscore(string entrada):ValorOz(){
    tipo = "underscore";
	string val = "_";
	valor = val;
}

string ValorOzUnderscore::getVal(){
	return valor;
}

string ValorOzUnderscore::obtenerCadenaValor(){
    return valor;
}