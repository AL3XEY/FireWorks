#include "Particle.hpp"

Particle::Particle() {}

Particle::Particle(double _x, double _y, double _xSpeed, double _ySpeed, int _lifespan) :
	x(_x),
	y(_y),
	xSpeed(_xSpeed),
	ySpeed(_ySpeed),
	lifespan(_lifespan) { }

void Particle::move()
{
	x += xSpeed;
	y += ySpeed;
}

void Particle::applyForce(double fx, double fy)
{
	xSpeed += fx;
	ySpeed += fy;
}

void Particle::draw()
{
	if (lifespan > 0) {
		double vertices[] = { x, y };
		glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);
		glDrawArrays(GL_POINTS, 0, 1);
		glDisableVertexAttribArray(0);
	}	
}

void Particle::tick()
{
	lifespan--;
}