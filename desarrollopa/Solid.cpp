#include "Solid.h"

void Solid::Update()
{

	this->orientation = this->orientation + this->orientationSpeed;
	position = position + velocity; // Movimiento de la partícula
	orientation = orientation + orientationSpeed;

	//this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed());
}


