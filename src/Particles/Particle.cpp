#include "Particle.h"

Particle::Particle() : AbstractParticle() {}

Particle::Particle(double _x, double _y, double _z, double _xSpeed, double _ySpeed, double _zSpeed, int _lifespan)
	: AbstractParticle(_x, _y, _z, _xSpeed, _ySpeed, _zSpeed, _lifespan) { }
