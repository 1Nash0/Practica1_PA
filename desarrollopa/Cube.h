#pragma once
#include <GL/glut.h>
#include "Solid.h"

class Cube : public Solid
{
private:

	float size;

public:

	Cube() : Solid()
	{
		this->size = 0.3;
	}

	inline float GetSize() { return this->size; }
	void SetSize(float sizeToSet) { this->size = sizeToSet; }

	void Render();

	Solid* Clone() const override {
		return new Cube(*this);  // Constructor copia para clonar
	}

};
	

