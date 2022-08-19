#include "ValorOz.h"
#include "ValorOzFloat.h"
#include "Almacen.h"


float ValorOzFloat::getVal(){
	return valor;
}

ValorOzFloat::ValorOzFloat(string entrada):ValorOz(){
    tipo = "float";
    float res = 0;
	int indice = 0, primer_entero = 0, segundo_entero = 0;
	string p_entero, s_entero;

	for(int i = 0; i < entrada.size(); i++){
		if(entrada[i] == '.'){
			p_entero = entrada.substr(indice, i - indice);
			s_entero = entrada.substr(i + 1, entrada.size() - i - 1);
			break;
		}
	}

	int potencia1 = p_entero.size(), potencia2 = s_entero.size();
	
	for(int i = 0; i < p_entero.size(); i++){
		int diez = pow(10,potencia1 - 1);
		int temp = p_entero[i] - '0';
		primer_entero += diez*temp;
		potencia1--;
	}

	for(int i = 0; i < s_entero.size(); i++){
		int diez = pow(10,potencia2 - 1);
		int temp = s_entero[i] - '0';
		segundo_entero += diez*temp;
		potencia2--;
	}
	potencia2 = s_entero.size();

	float tempp = segundo_entero/pow(10,potencia2);
	res += primer_entero;
	res += tempp;
    valor = res;
}

string ValorOzFloat::obtenerCadenaValor(){
    return to_string(valor);
}