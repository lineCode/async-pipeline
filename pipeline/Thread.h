#ifndef THREAD_H
#define THREAD_H
#include <pthread.h>

/**
 * Clase abstracta para crear threads.
 */
class Thread{
public:
	Thread();
	/**
	 * Inicia el thread.
	 */
	int run();
	/**
	 * Espera a que el thread termine y libera recursos.
	 */
	void join();
	/**
	 * Función que correrá en un el thread.
	 */
	virtual void runFunction() = 0;
	/**
	 * Destructor
	 */
	virtual ~Thread();

private:
	/**
	 * Constructor copia
	 */
	Thread(const Thread& otherThread);
	/**
	 * Evito copia por operador =
	 */
	const Thread& operator=(const Thread& otherThread);
	/**
	 * Thread C
	 */
	pthread_t thread;
	/**
	 * Función auxiliar que inicia el thread.
	 */
	static void* starter(void* arg);
};

#endif
