#include "stack.h"

// DEFINICIONES

stack &Push(stack &pila, char valor){
	pila.seq.at(pila.top) = valor;
	pila.top++;
	return pila;
}

stack &Pop(stack &pila, char &valor){
	--pila.top;
	valor = pila.seq.at(pila.top);
	return pila;
}

bool Full(const stack &pila){
	return pila.top == 100;
}

bool Emply(const stack &pila){
	return pila.top == 0;
}
