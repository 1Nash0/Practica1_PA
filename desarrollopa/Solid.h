#pragma once
#include "Vector3D.h"
#include "Color.h"
#include <iostream>

class Solid
{
private:
	Vector3D position;
	Vector3D orientation;
	Vector3D orientationSpeed;
	Vector3D velocity;
	Color color;
	bool wired;
	
public:
	Solid() :position(Vector3D(0.0, 0.0, -2.0)),
		orientation(Vector3D(0, 0, 0)),
		orientationSpeed(Vector3D(0, 0, 0)),
		velocity(Vector3D(0, 0, 0)),
		color(Color(0.2, 0.3, 0.4, 1.0)),
		wired(false) {}

	inline Vector3D GetPosition() { return this->position; }
	inline Vector3D GetOrientation() { return this->orientation; }
	inline Vector3D GetOrientationSpeed() { return this->orientationSpeed; }
	inline Vector3D GetVelocity() { return this->velocity; }
	inline Color GetColor() { return this->color; }
	inline bool GetWired() const { return this->wired; }

	void SetPosition(Vector3D coordsToSet) { this->position = coordsToSet; }
	void SetOrientation(Vector3D orientationToSet) { this->orientation = orientationToSet; }
	void SetOrientationSpeed(Vector3D orientationSpeedToSet) { this->orientationSpeed = orientationSpeedToSet; }
	void SetVelocity(Vector3D velocityToSet) { this->velocity = velocityToSet; }
	void SetColor(Color colorToSet) { this->color = colorToSet; }
	inline void SetWired(const bool wiredToSet) { this->wired = wiredToSet; }

	virtual void Render() = 0;
	virtual void Update();
	
	virtual Solid* Clone() const = 0;

};



