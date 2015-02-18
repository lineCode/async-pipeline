#include "Process.h"

Process::Process(): priority(1){}

Process::~Process(){}

int Process::getPriority() const{
	return this->priority;
}

void Process::setPriority(int priority){
	this->priority = priority;
}

bool DefaultProcessComparator::operator()(const Process* proc,
										  const Process* otherProc) const{
	return proc->getPriority() < otherProc->getPriority();
}
