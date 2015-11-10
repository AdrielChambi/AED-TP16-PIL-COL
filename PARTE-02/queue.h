#ifndef _queue_h
#define _queue_h

#include <iostream>
#include <array>    // Se necesita activar C++11

using namespace std;

//DECLARACIONES:

struct queue {														//Tipo de Dato Pila
	array<char,10> seq;
	unsigned frente,cant;
};

queue &Enqueue(queue &cola, char valor);								//Poner algo en la Pila
queue &Dequeue(queue &cola, char &valor);								//Sacar algo de la Pila
bool Full(const queue &cola);										//Verificar si esta llena
bool Emply(const queue &cola);										//Verificar si esta vacia

#endif
