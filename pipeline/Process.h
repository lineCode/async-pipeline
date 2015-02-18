#ifndef PROCESS_H
#define PROCESS_H

/**
 * Clase abstracta que representa a un proceso, es decir una unidad de trabajo
 * paralelizable. Esto puede ser, por ejemplo, parsear un archivo, calcular
 * estadísticas de un mapa, etc.
 */
class Process{
public:
	Process();
	virtual ~Process();
	/**
	 * Prioridad con la que se ejecuta el proceso en la cola de procesos.
	 */
	int getPriority() const;
	void setPriority(int priority);
	virtual void execute() = 0;
protected:
	int priority;
};

class DefaultProcessComparator{
public:
	bool operator()(const Process* proc, const Process* otherProc) const;
};

#endif
