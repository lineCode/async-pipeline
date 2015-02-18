#ifndef PIPELINE_H
#define PIPELINE_H
#include <queue>

#include "ProcessQueue.h"

class Process;

class Pipeline{
public:
	virtual void start() = 0;
	virtual void addProcess(Process* process);
protected:
	/**
	 * Máximo de trabajos en paralelo
	 */
	int pipelineSize;
	/**
	 * Heap con los trabajos ordenado en
	 */
	ProcessQueue processQueue;
};

#endif
