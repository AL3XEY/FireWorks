#ifndef ABSTRACT_PARTICLE_H
#define ABSTRACT_PARTICLE_H

#include <GLEW/glew.h>
#include <GL/gl.h>
#include <iostream>


class AbstractParticle {
	public:
		AbstractParticle();
		AbstractParticle(double _x, double _y, double _z, double _xSpeed, double _ySpeed, double _zSpeed, int _lifespan);
		
		virtual void move();
		virtual void applyForce(double fx, double fy, double fz);
		virtual void draw();
		virtual void tick();
		virtual bool done();

	protected:
		double x;
		double y;
		double z;
		double xSpeed;
		double ySpeed;
		double zSpeed;
		int lifespan;	
};

#endif
