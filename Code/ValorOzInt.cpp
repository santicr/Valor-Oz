#include "ValorOz.h"
#include "ValorOzInt.h"
#include "Almacen.h"


int ValorOzInt::getVal(){
	return valor;
}

ValorOzInt::ValorOzInt(string entrada):ValorOz(){
    tipo = "int";
    
	int numero = 0;
	int indice = entrada.size();
	int i = 0;

	while(indice != -1){
		char temps = entrada[i];
		int temp = temps - '0';
		int diez = pow(10,indice-1);
		numero += diez*temp;
		i++;
		indice--;
	}
    valor = numero;
}

string ValorOzInt::obtenerCadenaValor(){
	return to_string(valor);
}