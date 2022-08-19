#include <iostream>
#include "Almacen.h"
using namespace std;


list <string> identificarTipo(string entrada, Almacen temp){
	string ValorOz_Nombre; //Guarda el nombre de la variable de acuerdo a la entrada
	string ValorOz_Valor; //Guarda el valor, despues o antes del "="
    string ValorOz_Tipo; //Guarda el tipo de la variable ingresada
	int Input_Size = entrada.size(); //Coge el tamano de la cadena
    int Hay_Parentesis = 0, Hay_Punto = 0, Hay_Underscore = 0;
    list <string> lista;
    map <string, ValorOz*> alm_temp = temp.almacen;
    map <string, ValorOz*>::iterator it = alm_temp.begin();

	if(entrada[0] >= 'A' && entrada[0] <= 'Z'){ //Verifica si el nombre de la variable esta a la izquierda
		for(int i = 0; i < Input_Size; i++){
			if(entrada[i] == '='){
				ValorOz_Nombre = entrada.substr(0, i);
                ValorOz_Valor = entrada.substr(i+1, Input_Size-1-i);
			}
		}
	}

    else{
        for(int i = 0; i < Input_Size; i++){
            if(entrada[i] == '='){
                ValorOz_Nombre = entrada.substr(i+1, Input_Size-1-i);
                ValorOz_Valor = entrada.substr(0, i);
            }
        }
    }

    for(int i = 0; i < ValorOz_Valor.size(); i++){
        if(ValorOz_Valor[i] == '.'){
            Hay_Punto++;
            ValorOz_Tipo = "float";
        }
        
        else if(ValorOz_Valor[i] == '_'){
            Hay_Underscore++;
            ValorOz_Tipo = "underscore";
        }

        else if(ValorOz_Valor[i] == '(' || (ValorOz_Valor[0] >= 'a' && ValorOz_Valor[0] <= 'z') ){
            Hay_Parentesis++;
            ValorOz_Tipo = "registro";
        }

        else if(Hay_Punto == 0 && Hay_Parentesis == 0 && Hay_Underscore == 0)
            ValorOz_Tipo = "entero";
    }

    lista.push_back(ValorOz_Tipo);
    lista.push_back(ValorOz_Nombre);
    lista.push_back(ValorOz_Valor);

    for(list <string> :: iterator itt = lista.begin(); itt != lista.end(); itt++){
        cout << *itt << endl;
    }

    for(; it != alm_temp.end(); it++){
        if(it -> first == ValorOz_Nombre){ //Intenta encontrar la variable en el almacen
            if(alm_temp[ValorOz_Nombre] -> tipo == ValorOz_Tipo && ValorOz_Tipo != "underscore"){ //Verifica que el tipo sea el mismo.
                if(ValorOz_Tipo == "entero"){ // Verifica si el tipo es entero
                    cout << ((ValorOzInt*)(alm_temp[ValorOz_Nombre])) -> getVal() << " IMPRIMIO"<< endl;
                }
            }
        }
    }

    return lista;
}

int main(){
    Almacen almacen1;
    ValorOzInt* entero = new ValorOzInt("110"), *entero1 = new ValorOzInt("11");
    ValorOzUnderscore* nada = new ValorOzUnderscore("_");
    ValorOzRegistro* reg = new ValorOzRegistro("f(c1:f2(c2:10.2) u:X)");
    almacen1.almacen.insert({"R", nada});
    almacen1.almacen.insert({"Z", nada});
    almacen1.almacen.insert({"Y", nada});
    almacen1.imprimirAlmacen();
    cout << endl;
    almacen1.consultarVariable("Z");
    almacen1.agregarVariable("X");
    almacen1.imprimirAlmacen();
    cout << endl;
    almacen1.unificarVariables("X","Y");
    almacen1.unificarVariables("Y","Z");
    almacen1.modificarVariable("Z",entero);
    almacen1.modificarVariable("R",reg);
    almacen1.imprimirAlmacen();
    cout << endl;

    list <string> lista = almacen1.obtenerListaVariables();
    for(auto it = lista.begin(); it != lista.end(); it++){
        cout << *it << endl;
    }

    /* string entrada = "X=10";
    list <string> lista = identificarTipo(entrada, almacen1);
    list <string> :: iterator it = lista.begin();
    string tipo = *it;
    ValorOzRegistro rg("reg1(i:75 r:reg2(inn:5) fl:3.1415 u:_ r2:reg3(r3:reg4(fo:23.3 in:23 inception:reg5(rekt:reg6(underr:_ itt:45 flr:54.12))) und:_) f23:23.22 entero:45654)");
    list<string> tempCamp = rg.obtenerListaCampos();
    map<string, ValorOz*> tempReg = rg.getRegistros();
    // prueba impresion
    for(auto it = tempCamp.begin(); it != tempCamp.end(); it++){
        cout << *it << " -> " << tempReg[*it] << endl;
    } */

    /* if(tipo == "entero"){
        advance(it,2);
        //cout << *it <<endl; //Verificacion
        ValorOzInt I(*it);

    }
    
    else if(tipo == "float"){
        //cout << *it << endl; //Imprime el tipo
        advance(it,2);       //Avanza 2 posiciones en la lista
        //cout << *it << endl; //Verificacion, imprime el valor en string
        ValorOzFloat f(*it);
    }

    else if(tipo == "registro"){
        advance(it,2);
        //cout << *it <<endl; //Verificacion
        ValorOzRegistro(*it);
    }

    else if(tipo == "underscore"){
        advance(it,2);
        //cout << *it <<endl; //Verificacion
        ValorOzUnderscore(*it);
    } */
    return 0;
}