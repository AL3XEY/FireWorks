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
		double xSpeed;
		double ySpeed;
		int lifespan;

		Particle();
		Particle(double _x, double _y, double _xSpeed, double _ySpeed, int _lifespan);
		void move();
		void applyForce(double fx, double fy);
		void draw();
		void tick();
};

#endif
