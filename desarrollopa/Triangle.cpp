#include "Triangle.h"

void Triangle::Render()
{
	glEnable(GL_COLOR_MATERIAL);

	glBegin(GL_TRIANGLES);

	glColor4f(this->GetColor0().GetRed())


}

Solid* Triangle::Clone()
{
	return new Triangle(*this);
}