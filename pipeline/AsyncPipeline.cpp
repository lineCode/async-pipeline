#include "AsyncPipeline.h"
#include "AsyncPipelineThread.h"
#include "Process.h"
#include <vector>

AsyncPipeline::AsyncPipeline(){
	this->maxThreads = 1;
}

void AsyncPipeline::start(){
	std::vector<AsyncPipelineThread*> threads;
	bool hasProcess = true;
	if (this->maxThreads < 1){
		throw "Bad MaxThreads number";
	}
	// Levanto hilos en paralelo
	for (unsigned int i = 1; i < this->maxThreads; ++i){
		AsyncPipelineThread* thread = new AsyncPipelineThread(
			this->processQueue, this->processMutex);
		threads.push_back(thread);
		thread->run();
	}
	// Corro procesos
	while (hasProcess){
		this->processMutex.lock();
		hasProcess = !this->processQueue.isEmpty();
		Process* process = 0;
		if (hasProcess){
			process = this->processQueue.popProcess();
		}
		// Destrabo mutex para que puedan seguir levantando procesos
		// los otros hilos
		this->processMutex.unlock();
		if (process){
			process->execute();
		}
	}
	// Libero recursos
	std::vector<AsyncPipelineThread*>::iterator it;
	for (it = threads.begin(); it < threads.end(); ++it){
		(*it)->join();
		delete (*it);
	}
}

void AsyncPipeline::setMaxThreads(unsigned int threads){
	this->maxThreads = threads;
}
