#ifndef DUMMYPROCESS_H
#define DUMMYPROCESS_H
#include <pipeline/Process.h>

class DummyProcess : public Process{
public:
	/**
	 * Constructor. Toma un id para ser mostrado en pantalla
	 */
	explicit DummyProcess(int id);
	virtual ~DummyProcess();
	/**
	 * Devuelve el número de id con el que fue creado
	 */
	int getProcessId();
	/**
	 * Imprime en pantalla la espera y número de id.
	 */
	virtual void execute();
private:
	int id;
};

#endif // DUMMYPROCESS_H
