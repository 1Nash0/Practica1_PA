#pragma once
#include <GL/glut.h>
#include "Solid.h"

class EmmiterConfiguration
{
private:
	int numParticulas;
	int tiempoEmision;
	Solid* particula;

public:

	//Constructor que recibe el n�mero de part�culas, el periodo de emisi�n y una part�cula de referencia 

	EmmiterConfiguration() : numParticulas(100), tiempoEmision(10), particula(){}

	inline int GetNumParticulas() const { return this->numParticulas; }
	inline void SetNumParticulas(const int& numParticulasToSet) { this->numParticulas = numParticulasToSet; }
	inline int GetTiempoEmision() const { return this->tiempoEmision; }
	inline void SetTiempoEmision(const int& tiempoEmisionToSet) { this->tiempoEmision = tiempoEmisionToSet; }
	inline Solid* GetTParticula() const { return this->particula; }
	inline void SetParticula(Solid* particulaToSet) {
		delete particula;         // Libera la memoria de la part�cula anterior
		this->particula = particulaToSet;
	}


};

