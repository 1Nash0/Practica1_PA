#pragma once
#include "Solid.h"
#include <GL/glut.h>
#include <chrono>
#include "EmmiterConfiguration.h"

class Emmiter : public Solid
{
private:
	EmmiterConfiguration config;     // Configuración del emisor
	Solid* particula;                // Vector de punteros a partículas generadas
	std::chrono::milliseconds initialMilliseconds;  
	std::chrono::milliseconds currentTime;;
	long lastUpdateTime;

public:
	Emmiter(const EmmiterConfiguration& config) {

		this->initialMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		this->lastUpdateTime = 0;
		this->currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	}


	void Render();
	void Update();
};

