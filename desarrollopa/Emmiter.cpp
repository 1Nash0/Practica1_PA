#include "Emmiter.h"
#include <chrono>
#include "EmmiterConfiguration.h"


using namespace std;
using namespace std::chrono;


void Emmiter::CrearParticula(Solid* particulaReferencia)
{
	// Clona la partícula de referencia
	Solid* nuevaParticula = particulaReferencia->Clone();

	// Modifica las propiedades de la nueva partícula (posiciones, color, velocidad, etc.)
	nuevaParticula->SetPosition(this->GetPosition());
	// Aquí puedes aplicar números aleatorios o variaciones personalizadas para modificar la velocidad, color, etc.

	// Añade la partícula al vector
	this->particulas.push_back(nuevaParticula);
}

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

