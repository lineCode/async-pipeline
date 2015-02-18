#include "DummyProcess.h"
#include <iostream> //cout
#include <cstdlib> //rand
#include <unistd.h> //Sleep
#define TIME_FACTOR 200000
#define TIME_MOD 10

DummyProcess::~DummyProcess(){}

DummyProcess::DummyProcess(int id){
	std::cout << "Creando proceso " << id << std::endl;
	this->id = id;
}

int DummyProcess::getProcessId(){
	return this->id;
}

void DummyProcess::execute(){
	std::cout << "Corriendo el proceso " << this->id  << " con prioridad " << \
		this->priority << std::endl;
	int randTime = (rand() % TIME_MOD + 1) * TIME_FACTOR;
	std::cout << "Esperando " << randTime / 1000 << " microsegs" << std::endl;
	usleep(randTime);
	std::cout << "Proceso " << this->id << " Terminado" << std::endl;
}
