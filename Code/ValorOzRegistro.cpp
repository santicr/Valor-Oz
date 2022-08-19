#include "ValorOz.h"
#include "ValorOzRegistro.h"
#include "Almacen.h"


list <string> identificarTipos(string entrada){
	int indice = 0;
	list <string> res;
	string campo;
	string valor;
	string tipo;
	for(int i = 0; i <entrada.size(); i++){
		if(entrada[i] == ':'){
			campo = entrada.substr(indice, i - indice);
			indice = i;
			valor = entrada.substr(indice+1, entrada.size() - i-1);
			break;
		}
	}

	int es_flotante = 0, es_underscore = 0, es_registro = 0, es_variable = 0; 
	
	for(int i = 0; i < valor.size(); i++){
		if(valor[i] == '.'){
			es_flotante++;
		}
		else if(valor[i] == '_'){
			es_underscore++;
		}
		else if(valor[i] == '('){
			es_registro++;
		}
		else if(valor[i] >= 'A' && valor[i] <= 'Z'){
			es_variable++;
		}
	}
	if(es_flotante > 0 && es_registro == 0)
		tipo = "float";
	else if(es_underscore > 0 && es_registro == 0)
		tipo = "underscore";
	else if(es_registro > 0)
		tipo = "registro";
	else if(es_variable > 0)
		tipo = "var";
	else
		tipo = "int";
	
	res.push_back(campo);
	res.push_back(tipo);
	res.push_back(valor);

	return res;
}

list<pair<string, bool>> separarRegistros(string entrada){
	bool abre = false;
	int par = 0;
	list<pair<string, bool>> regs;
	string buff = "";
	int i = 0;
	string current;
	while(i < entrada.size()){
		current = entrada[i];
		if(current == "(") par++;
		else if(current == ")") par--;
		if(current == " " && par == 0){
			regs.push_back(make_pair(buff, false));
			buff = "";
		}else{
			buff += current;
		}
		i++;
	}
	regs.push_back(make_pair(buff, false));
	return regs;
}

ValorOzRegistro::ValorOzRegistro(string entrada):ValorOz(){
	tipo = "registro";
	string buff = "";
	int pos = -1;
	for(int i = 0; i < entrada.size(); i++){
		if(entrada[i] != '('){
			buff += entrada[i];
		}else{
			etiqueta = buff;
			pos = i+1;
			break;
		}
	}
	string temp = entrada.substr(pos, entrada.size()-1-pos);
	cout << "Etiqueta -> " << etiqueta << endl << "Valor -> " << temp << endl;
	list<pair<string, bool>> regList = separarRegistros(temp);
	for(auto it = regList.begin(); it != regList.end(); it++){
		list<string> temp = identificarTipos(it -> first);
		list<string>::iterator nombre = temp.begin();
		list<string>::iterator tipo = temp.begin();
		advance(tipo, 1);
		list<string>::iterator valor = temp.begin();
		advance(valor, 2);
		if(*tipo == "int"){
			ValorOzInt temp(*valor);
			registros.insert({*nombre, &temp});
			cout << *tipo << " " << *nombre << " = " << *valor << endl;
		}
		else if(*tipo == "float"){
			ValorOzFloat temp(*valor);
			registros.insert({*nombre, &temp});
			cout << *tipo << " " << *nombre << " = " << *valor << endl;
		}
		else if(*tipo == "underscore"){
			ValorOzUnderscore temp(*valor);
			registros.insert({*nombre, &temp});
			cout << *tipo << " " << *nombre << " = " << *valor << endl;
		}
		else if(*tipo == "registro"){
			ValorOzRegistro temp(*valor);
			registros.insert({*nombre, &temp});
			cout << *tipo << " " << *nombre << " = " << *valor << endl;
		}
		else if(*tipo == "var"){
			ValorOzVariable temp(*valor);
			registros.insert({*nombre, &temp});
			cout << *tipo << " " << *nombre << " = " << *valor << endl;
		}
	}
}

map<string, ValorOz*> ValorOzRegistro::getRegistros(){
	return registros;
}

string ValorOzRegistro::obtenerCadenaValor(){
    return "";
}

string ValorOzRegistro::obtenerEtiqueta(){
    return etiqueta;
}

list<string> ValorOzRegistro::obtenerListaCampos(){
    list<string> campos;
	map<string, ValorOz*>::iterator it = registros.begin();
	while(it != registros.end()){
		campos.push_back(it -> first);
		it++;
	}
    return campos;
}