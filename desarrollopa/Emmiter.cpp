#include "Emmiter.h"
#include <chrono>


void Emmiter::Render()
{
	
}

void Emmiter::Update()
{
	std::chrono::milliseconds currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	//if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdateTime > this->configuration.GetEmissionIntervalMilliseconds())
	{

	}
}