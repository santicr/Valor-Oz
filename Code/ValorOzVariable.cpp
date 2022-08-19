#include "ValorOz.h"
#include "ValorOzVariable.h"
#include "Almacen.h"

ValorOzVariable::ValorOzVariable(string entrada):ValorOz(){
    tipo = "var";
    referencia = entrada;
}

string ValorOzVariable::obtenerCadenaValor(){
    return referencia;
}