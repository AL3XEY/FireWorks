#include "Particle.h"

Particle::Particle() {}

Particle::Particle(double _x, double _y, double _z, double _xSpeed, double _ySpeed, double _zSpeed, int _lifespan) :
	x(_x),
	y(_y),
	z(_z),
	xSpeed(_xSpeed),
	ySpeed(_ySpeed),
	zSpeed(_zSpeed),
	lifespan(_lifespan) { }

void Particle::move()
{
	x += xSpeed;
	y += ySpeed;
	z += zSpeed;
}

void Particle::applyForce(double fx, double fy, double fz)
{
	xSpeed += fx;
	ySpeed += fy;
	zSpeed += fz;
}

void Particle::draw()
{
	if (lifespan > 0) {
		double vertices[] = { x, y, z };
		glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);
		glDrawArrays(GL_POINTS, 0, 1);
		glDisableVertexAttribArray(0);
	}	
}

void Particle::tick()
{
	lifespan--;
}