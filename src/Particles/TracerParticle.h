#ifndef TRACERPARTICLE_H
#define TRACERPARTICLE_H

#include <GLEW/glew.h>
#include <GL/gl.h>
#include <iostream>
#include <src\Particles\AbstractParticle.h>

class TracerParticle : public AbstractParticle
{
public:
	TracerParticle();
	TracerParticle(double _x, double _y, double _z, double _xSpeed, double _ySpeed, double _zSpeed, int _lifespan);
};

#endif