#include "Thread.h"

Thread::Thread(){
	this->thread = 0; //Inicializo
}

const Thread& Thread::operator=(const Thread& otherThread){
	return otherThread;
}

Thread::Thread(const Thread&){}

Thread::~Thread(){
}

void Thread::join(){
	pthread_join(this->thread, NULL);
}

int Thread::run(){
	return pthread_create(&this->thread, NULL, starter , this);
}

void* Thread::starter(void* arg){
    Thread* thread = static_cast<Thread *>(arg);
    thread->runFunction();
    return NULL;
}
