#include "queue.h"

// DEFINICIONES

queue &Enqueue(queue &cola, char valor){
	cola.seq.at((cola.frente + cola.cant) % 10) = valor;
	cola.cant++;
	return cola;
}

queue &Dequeue(queue &cola, char &valor){
	valor = cola.seq.at(cola.frente);
	cola.frente = (cola.frente + 1) % 10;
	--cola.cant;
	return cola;
}

bool Full(const queue &cola){
	return cola.cant == 10;
}

bool Emply(const queue &cola){
	return cola.cant == 0;
}
