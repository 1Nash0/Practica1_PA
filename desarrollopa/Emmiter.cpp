#include "Emmiter.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

void Emmiter::Render()
{
	
}

void Emmiter::Update()
{
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdateTime > this->config.GetTiempoEmision())
		//if (Tiempo de reloj actual - Momento donde se ejecutó el emisor - tiempo que lleva la ultima partícula > Intervalo entre partículas)
		//if (currentTime - initialMiliseconds - lastUpdateTime - tiempoEmisión)
	{

	}
	this->lastUpdateTime = currentTime.count() - this->initialMilliseconds.count();
}