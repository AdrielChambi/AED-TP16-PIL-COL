#include <array>
#include <iostream>
#include <cstdlib>
//#include <ciso646>		//Para usar NOT
#include "stack.h"

/* Trabajo Practico N16 - PILAS

REQUISITO:
Implementar los modulos Stack y Queue

PRE-CONDICIONES:
El usuario ingresa una expresion, se considera que no puede cerrar una llave, corchete o parentecis sin antes haberlo abierto

MATERIA:
Algoritmos y Estructura de Datos

INTEGRANTES:
Martin AGUEL
Adriel CHAMBI
Federico BUSTAMANTE
Augusto SCHMID

*/
using namespace std;

int main(int argc, char** argv) {
	stack Expresion;
	Expresion.top = 0;
	
	stack LlavesCorchetesParentesis;
	LlavesCorchetesParentesis.top = 0;
	
	char DatoIngresado;
	while (cin>>DatoIngresado){
		
		//Si es una llave, corechete o parentesis abierto lo sumo
		if (DatoIngresado == '{' or DatoIngresado == '[' or DatoIngresado == '(') {
			LlavesCorchetesParentesis = Push(LlavesCorchetesParentesis,DatoIngresado);	
		}
		
		//Pero si es una llave, corchete o parentesis cerrada tiene que estar previamente abierta
		if (DatoIngresado == '}' or DatoIngresado == ']' or DatoIngresado == ')') {
			//Verifico que no este vacia:
			if (Emply(LlavesCorchetesParentesis)) {
				cout<<"Error de expresion";
			}
			else{
				char DatoExtraido;
				LlavesCorchetesParentesis = Pop(LlavesCorchetesParentesis,DatoExtraido);
				if (DatoIngresado == '}' and DatoExtraido == '{'){
					cout<<"Cierre de llaves correcto"<<endl;
				}
				else{
					if (DatoIngresado == ']' and DatoExtraido == '['){
						cout<<"Cierre de corchetes correcto"<<endl;
					}
					else{
						if (DatoIngresado == ')' and DatoExtraido == '('){
							cout<<"Cierre de parentesis correcto"<<endl;
						}
						else{
							cout<<"Error de expresion"<<endl;
						}	
					}
				}
			}
		}
	}
	
	if (Emply(LlavesCorchetesParentesis)) {
		cout<<"Expresion correcta";
	}
	else{
		cout<<"Expresion incorrecta";
	}
	
	return 0;
}
