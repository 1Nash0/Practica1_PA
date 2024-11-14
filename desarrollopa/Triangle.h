#pragma once
#include "Solid.h"

class Triangle : public Solid
{
private:

	Vector3D vertex0, vertex1, vertex2;
	Color color0, color1, color2;
	Vector3D normal0, normal1, normal2;

public:

	Triangle(
		Vector3D vertex0Argument = Vector3D(),
		Vector3D vertex1Argument = Vector3D(),
		Vector3D vertex2Argument = Vector3D(),
		Vector3D normal0Argument = Vector3D(),
		Vector3D normal1Argument = Vector3D(),
		Vector3D normal2Argument = Vector3D(),
		Color color0Argument = Color(1, 0, 0, 1),
		Color color1Argument = Color(0, 1, 0, 1),
		Color color2Argument = Color(0, 0, 1, 1)) :
		vertex0(vertex0Argument), vertex1(vertex1Argument), vertex2(vertex2Argument),
		normal0(normal0Argument), normal1(normal1Argument), normal2(normal2Argument),
		color0(color0Argument), color1(color1Argument), color2(color2Argument)
	)
};

