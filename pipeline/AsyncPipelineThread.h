#ifndef ASYNCPIPELINETHREAD_H
#define ASYNCPIPELINETHREAD_H

#include "Mutex.h"
#include "ProcessQueue.h"
#include "Thread.h"

class AsyncPipelineThread : public Thread
{
public:
	AsyncPipelineThread(ProcessQueue &processQueue, Mutex& mutex);
	virtual void runFunction();
private:
	ProcessQueue &processQueue;
	/**
	 * Mutex para sincronizar todos los threads que corren operaciones
	 */
	Mutex& mutex;
};

#endif // ASYNCPIPELINETHREAD_H
