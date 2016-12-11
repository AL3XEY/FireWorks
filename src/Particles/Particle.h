#ifndef PARTICLE_H
#define PARTICLE_H

#include <GLEW/glew.h>
#include <GL/gl.h>
#include <iostream>
#include "AbstractParticle.h"

class Particle : public AbstractParticle
{
	public:
		Particle();
		Particle(double _x, double _y, double _z, double _xSpeed, double _ySpeed, double _zSpeed, int _lifespan);
};

#endif
