#include <cstdlib> // rand
#include <ctime> // time
#include <iostream> // Salida por consola
#include <pipeline/AsyncPipeline.h>
#include <vector>
#include "DummyProcess.h"
#define MAX_PROCESS 20
#define MAX_PRIORITY 5

int getRand(int cap);

int main(int argc, char** argv){
	//Inicio seed para rand
	srand(time(NULL));

	int threadNum = 1;
	if (argc > 1){
		threadNum = atoi(argv[1]);
		std::cout << "Obtenido el primer parámetro. Utilizando "\
					<< threadNum << " hilos" << std::endl;
	} else {
		std::cout << "Sin parámetros. Utilizando un solo hilo" << std::endl;
	}

	AsyncPipeline asyncPipe;
	int i;
	std::vector<DummyProcess*> processVector;
	asyncPipe.setMaxThreads(threadNum);
	for (i = 0; i < MAX_PROCESS; ++i){
		//Agrego prioridades aleatorias, para probar
		int randPriority = getRand(MAX_PRIORITY) + 1;
		DummyProcess* proc = new DummyProcess(i);
		processVector.push_back(proc);
		proc->setPriority(randPriority);
		asyncPipe.addProcess(proc);
	}
	asyncPipe.start();
	std::vector<DummyProcess*>::iterator it;
	for (it = processVector.begin(); it < processVector.end(); ++it){
		delete (*it);
	}
}

int getRand(int cap){
	int randInt = rand();
	return randInt % cap;
}

