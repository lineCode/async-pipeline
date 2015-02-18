#ifndef ASYNC_PIPELINE_H
#define ASYNC_PIPELINE_H
#include "Pipeline.h"
#include "Mutex.h"

/**
 * Pipeline asincrónico
 * Ejecuta los procesos que se han encolado, hasta MaxThreads procesos
 * en paralelo. 
 */
class AsyncPipeline : public Pipeline{
public:
	AsyncPipeline();
	void start();
	void setMaxThreads(unsigned int threads);
private:
	Mutex processMutex;
	unsigned int maxThreads;
};

#endif
