#ifndef ABSTRACT_PARTICLE_H
#define ABSTRACT_PARTICLE_H

#include <GLEW/glew.h>
#include <GL/gl.h>
#include <iostream>

class AbstractParticle
{
public:
	double x;
	double y;
	double z;
	double xSpeed;
	double ySpeed;
	double zSpeed;
	int lifespan;

	AbstractParticle();
	AbstractParticle(double _x, double _y, double _z, double _xSpeed, double _ySpeed, double _zSpeed, int _lifespan);
	void move();
	void applyForce(double fx, double fy, double fz);
	void draw();
	void tick();
};

#endif
