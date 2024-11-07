#pragma once
#include "Solid.h"
class Camera : public Solid
{
private:

public:
	Camera() {}

	void Render();

	Camera* Clone() const override {
		return new Camera(*this);
	}
};

