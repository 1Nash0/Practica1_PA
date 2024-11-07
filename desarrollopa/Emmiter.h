#pragma once
#include "Solid.h"
#include <GL/glut.h>
#include <chrono>
#include "EmmiterConfiguration.h"

using namespace std;
using namespace std::chrono;

class Emmiter : public Solid
{
private:
	EmmiterConfiguration config;     // Configuraci�n del emisor
	Solid* particula;                // Vector de punteros a part�culas generadas
	milliseconds initialMilliseconds;  
	milliseconds currentTime;;
	long lastUpdateTime;

public:
	Emmiter(const EmmiterConfiguration& config) {

		this->initialMilliseconds = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		this->lastUpdateTime = 0;
		//this->currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	}


	inline EmmiterConfiguration GetConfig() const { return this->config; }
	inline void SetConfig(const EmmiterConfiguration& configToSet) { this->config = configToSet; }




	void Render();
	void Update();
	void CrearParticula();
};

