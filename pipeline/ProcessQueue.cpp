#include "ProcessQueue.h"

bool ProcessQueue::isEmpty(){
	return this->processQueue.empty();
}

Process* ProcessQueue::popProcess(){
	Process* process = this->processQueue.top();
	this->processQueue.pop();
	return process;
}

void ProcessQueue::pushProcess(Process* process){
	this->processQueue.push(process);
}

unsigned int ProcessQueue::size(){
	return this->processQueue.size();
}
