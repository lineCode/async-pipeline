#ifndef PROCESSQUEUE_H
#define PROCESSQUEUE_H
#include <queue>
#include <vector>
#include "Process.h"

/**
 * Contenedor de objetos del tipo proceso
 */
class ProcessQueue{
public:
	/**
	 * Agrega un proceso a la cola
	 */
	void pushProcess(Process* process);
	/**
	 * Retira un proceso de la cola
	 */
	Process* popProcess();
	/**
	 * Verifica si está vacío.
	 */
	bool isEmpty();
	/**
	 * Devuelve la cantidad de procesos contenidos.
	 */
	unsigned int size();

private:
	/**
	 * Contenedor de los procesos.
	 */
	std::priority_queue<Process*,
		std::vector<Process*>,
		DefaultProcessComparator> processQueue;
};

#endif
