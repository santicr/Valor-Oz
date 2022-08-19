#include "Almacen.h"

using namespace std;

Almacen::Almacen(){
    return;
}

///////////////  FUNCIONES AUXILIARES  //////////////////////////////////////////////////////////////
ValorOz* Almacen::recursion(ValorOz* entrada){
    if(entrada -> tipo != "var"){
        if(entrada -> tipo == "int"){
            cout << ((ValorOzInt*)(entrada)) -> getVal() << endl;
            return ((ValorOzInt*)(entrada));
        }
        else if(entrada -> tipo == "underscore"){
            cout << ((ValorOzUnderscore*)(entrada)) -> getVal() << endl;
            return ((ValorOzUnderscore*)(entrada));
        }
        else if(entrada -> tipo == "float"){
            cout << ((ValorOzFloat*)(entrada)) -> getVal() << endl;
            return ((ValorOzFloat*)(entrada));
        }
        else if(entrada -> tipo == "registro")
            imprimirRegistros((ValorOzRegistro*)(entrada));
    }
    else
        return recursion(almacen[((ValorOzVariable*)(entrada)) -> referencia]);
}

void Almacen::imprimirRegistros(ValorOzRegistro* reg){
    map<string, ValorOz*> registross = reg -> getRegistros();
    map<string, ValorOz*>::iterator it;
    for(it = registross.begin(); it != registross.end(); it++){
        if(it -> second -> tipo == "underscore")
            cout << it -> first << " -> " << ((ValorOzUnderscore*)it -> second) -> getVal() << endl;
        else if(it -> second -> tipo == "int")
            cout << it -> first << " -> " << ((ValorOzInt*)it -> second) -> getVal() << endl;
        else if(it -> second -> tipo == "float")
            cout << it -> first << " -> " << ((ValorOzFloat*)it -> second) -> getVal() << endl;
        else if(it -> second -> tipo == "registro"){
            cout << it -> first << " -> ";
            imprimirRegistros((ValorOzRegistro*)(it -> second));
            cout << endl;
        }
        else if(it -> second -> tipo == "var"){
            cout << it -> first << " -> ";
            recursion(it -> second);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////  Constructores  ///////////////////////////////////////////////////////////////////7////
void Almacen::crearAlmacenLleno(map <string, ValorOz*> variables){
    map <string, ValorOz*>::iterator it;
    for(it = variables.begin(); it != variables.end(); ++it){
        almacen[it -> first] = it -> second;
    }
}

void Almacen::imprimirAlmacen(){
    map <string, ValorOz*>::iterator it;
    for(it = almacen.begin(); it != almacen.end(); ++it){
        if(it -> second -> tipo == "underscore")
            cout << it -> first << " -> " << ((ValorOzUnderscore*)it -> second) -> getVal() << endl;
        else if(it -> second -> tipo == "int")
            cout << it -> first << " -> " << ((ValorOzInt*)it -> second) -> getVal() << endl;
        else if(it -> second -> tipo == "float")
            cout << it -> first << " -> " << ((ValorOzFloat*)it -> second) -> getVal() << endl;
        else if(it -> second -> tipo == "registro"){
            cout << it -> first << " -> ";
            imprimirRegistros((ValorOzRegistro*)(it -> second));
            cout << endl;
        }
        else if(it -> second -> tipo == "var"){
            cout << it -> first << " -> ";
            recursion(it -> second);
        }
    }
}

void Almacen::consultarVariable(string var){
    if(almacen[var] -> tipo == "int"){
        cout << ((ValorOzInt*)(almacen[var])) -> getVal() << endl;
    }
    else if(almacen[var] -> tipo == "float"){
        cout << ((ValorOzFloat*)(almacen[var])) -> getVal() << endl;
    }
    else if(almacen[var] -> tipo == "underscore"){
        cout << ((ValorOzUnderscore*)(almacen[var])) -> getVal() << endl;
    }
        
}


bool Almacen::consultarLigaduraVariable(string var){
    map<string, ValorOz*>::iterator it = almacen.begin();
    while (it != almacen.end()){
        if(it->first == var){
            if((it->second)->tipo != "underscore")
                return true;
            else
                return false;
        }
        it++;
    }
    return false;
}

void Almacen::modificarVariable(string var, ValorOz* val){
    if(almacen[var] -> tipo == "underscore"){
        almacen[var] = val;
    }
    else if(almacen[var] -> tipo == "int"){
        if(((ValorOzInt*)(almacen[var])) -> getVal() == ((ValorOzInt*)(val)) -> getVal())
            cout << "Done." << endl;
        else{
            cout << "Error." << endl;
            exit(1);
        }
    }
    else if(almacen[var] -> tipo == "float"){
        if(((ValorOzFloat*)(almacen[var])) -> getVal() == ((ValorOzFloat*)(val)) -> getVal())
            cout << "Done." << endl;
        else{
            cout << "Error." << endl;
            exit(1);
        }
    }
}

void Almacen::agregarVariable(string var){
    map <string, ValorOz*> :: iterator it = almacen.begin();
    for(; it != almacen.end(); it++){
        if(it -> first == var){
            cout << "Error." << endl;
            exit (1);
        }
    }
    ValorOzUnderscore* ent = new ValorOzUnderscore("_");
    almacen[var] = ent;
}

list<string> Almacen::obtenerListaVariables(){
    list<string> res;
    map<string, ValorOz*>::iterator it = almacen.begin();
    while(it != almacen.end()){
        res.push_back(it -> first);
        it++;
    }
    return res;
}


void Almacen::unificarVariables(string var1, string var2){
    map <string, ValorOz*> :: iterator it = almacen.begin();
    bool esta1 = false, esta2 = false;
    for(; it != almacen.end(); it++){
        if(it -> first == var1){
            esta1 = true;
        }
        else if(it -> first == var2){
            esta2 = true;
        }
    }
    if(esta1 == true && esta2 == true){
        if(almacen[var1] -> tipo == almacen[var2] -> tipo){
            if(almacen[var1] -> tipo == "int" && almacen[var2] -> tipo == "int"){
                if(((ValorOzInt*)(almacen[var1])) -> getVal() == ((ValorOzInt*)(almacen[var2])) -> getVal()){
                    ValorOzVariable* temp = new ValorOzVariable(var2);
                    almacen[var1] = temp;
                    cout << "Done." << endl;
                }
                else{
                    cout << "Error." << endl;
                    exit (1);
                }
            }
            else if(almacen[var1] -> tipo == "float" && almacen[var2] -> tipo == "float"){
                if(((ValorOzFloat*)(almacen[var1])) -> getVal() == ((ValorOzFloat*)(almacen[var2])) -> getVal()){
                    ValorOzVariable* temp = new ValorOzVariable(var2);
                    almacen[var1] = temp;
                    cout << "Done." << endl;
                }
                else{
                    cout << "Error." << endl;
                    exit (1);
                }
            }
            else if(almacen[var1] -> tipo == "underscore" && almacen[var2] -> tipo == "underscore"){
                ValorOzVariable* temp = new ValorOzVariable(var2);
                almacen[var1] = temp;
                cout << "Done." << endl;
            }
        }
        else if(almacen[var1] -> tipo == "underscore"){
            ValorOzVariable* temp = new ValorOzVariable(var2);
            almacen[var1] = temp;
            cout << "Done." << endl;
        }
        else{
            exit (1);
        }
    }
    else{
        exit (1);
    }
}