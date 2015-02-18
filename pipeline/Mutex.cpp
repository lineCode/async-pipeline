#include "Mutex.h"


Mutex:: Mutex(){
	pthread_mutex_init(&mutex,NULL);
}

void Mutex::lock(){
	pthread_mutex_lock(&mutex);
}


void Mutex::unlock(){
	pthread_mutex_unlock(&mutex);
}

Mutex::~Mutex(){
	pthread_mutex_destroy(&mutex);
}

Lock::Lock(Mutex &mutex) : mutex(mutex){
	mutex.lock();
}

Lock::~Lock(){
	mutex.unlock();
}
