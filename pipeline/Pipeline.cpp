#include "Pipeline.h"

void Pipeline::addProcess(Process* process){
	this->processQueue.pushProcess(process);
}
