#include "AbstractParticle.h"

AbstractParticle::AbstractParticle() {}

AbstractParticle::AbstractParticle(double _x, double _y, double _z, double _xSpeed, double _ySpeed, double _zSpeed, int _lifespan) :
	x(_x),
	y(_y),
	z(_z),
	xSpeed(_xSpeed),
	ySpeed(_ySpeed),
	zSpeed(_zSpeed),
	lifespan(_lifespan) { }

void AbstractParticle::move()
{
	x += xSpeed;
	y += ySpeed;
	z += zSpeed;
}

void AbstractParticle::applyForce(double fx, double fy, double fz)
{
	xSpeed += fx;
	ySpeed += fy;
	zSpeed += fz;
}

int AbstractParticle::draw()
{
	if (lifespan > 0) {
		double vertices[] = { x, y, z };
		glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);
		glDrawArrays(GL_POINTS, 0, 1);
		glDisableVertexAttribArray(0);
		return 1;
	}
	return 0;
}

void AbstractParticle::tick()
{
	lifespan--;
}

bool AbstractParticle::done() {
	return lifespan < 0;
}