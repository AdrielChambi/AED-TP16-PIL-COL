#include <array>
#include <iostream>
#include <windows.h>		//retardo con Sleep
#include "queue.h"

/* Trabajo Practico N16 - COLAS

REQUISITO:
Implementar los modulos Stack y Queue

PRE-CONDICIONES:
Los clientes se van encolando cada 3 segundos, Exise una sola Caja que desencola cada 7 segundos
Si la cola esta llena, el cliente se pierde.

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
	
	queue Cola;
	Cola.cant = 0;
	Cola.frente = 0;
	
	unsigned ContadorCliente = 0;
	char IdCliente = 'A';
	
	unsigned ContadorCaja = 0;
	char Atendido;
	
	unsigned CantSegundo = 0;
	while (CantSegundo < 200){
		//Cada un segundo se ejecuta esto
		Sleep(1000);	
		CantSegundo++;
		
		//Cada 3 segundos encola, si la cola esta llena pierde el cliente
		ContadorCliente++;
		if (ContadorCliente == 3){
			ContadorCliente = 0;
			if (not Full(Cola)){			
				Cola = Enqueue(Cola,IdCliente);
				cout<<"Cliente "<<IdCliente<<" Encolado"<<endl;
				IdCliente++;
			}
			else{
				cout<<"Cola llena, Cliente Perdido"<<endl;
			}
		}
		
		//Cada 7 segundos la caja atiende si existe alguien en la cola
		ContadorCaja++;
		if(ContadorCaja == 7){
			ContadorCaja = 0;
			if (not Emply(Cola)){
				Cola = Dequeue(Cola,Atendido);
				cout<<"Cliente "<<Atendido<<" Atendido"<<endl;
			}
		}	
	}
}
