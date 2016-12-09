#ifndef PARTICLE_H
#define PARTICLE_H

#include <GLEW/glew.h>
#include <GL/gl.h>
#include <iostream>

class Particle
{
	public:
		double x;
		double y;
		double z;
		double xSpeed;
		double ySpeed;
		double zSpeed;
		int lifespan;

		Particle();
		Particle(double _x, double _y, double _z, double _xSpeed, double _ySpeed, double _zSpeed, int _lifespan);
		void move();
		void applyForce(double fx, double fy, double fz);
		void draw();
		void tick();
};

#endif
