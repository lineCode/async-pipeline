#include "AsyncPipelineThread.h"

AsyncPipelineThread::AsyncPipelineThread(ProcessQueue &processQueue,
										 Mutex& mutex):
	processQueue(processQueue), mutex(mutex){}

void AsyncPipelineThread::runFunction(){
	bool hasProcess = true;
	while (hasProcess){
		mutex.lock();
		hasProcess = !this->processQueue.isEmpty();
		Process* process = 0;
		if (hasProcess){
			process = this->processQueue.popProcess();
		}
		mutex.unlock();
		if (process){
			process->execute();
		}
	}
}
