#ifndef _stack_h
#define _stack_h

#include <iostream>
#include <array>    // Se necesita activar C++11

using namespace std;

//DECLARACIONES:

struct stack {														//Tipo de Dato Pila
	array<char,100> seq;
	unsigned top;
};

stack &Push(stack &pila, char valor);								//Poner algo en la Pila
stack &Pop(stack &pila, char &valor);								//Sacar algo de la Pila
bool Full(const stack &pila);										//Verificar si esta llena
bool Emply(const stack &pila);										//Verificar si esta vacia

#endif
