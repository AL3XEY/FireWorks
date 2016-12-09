#ifndef ABSTRACT_FIREWORK_H
#define ABSTRACT_FIREWORK_H

#include <GLEW/glew.h>
#include <windows.h> // *** IMPORTANT: Uncomment for Win32 systems - This must come -BEFORE- gl.h in the include list! ***
#include <GL/gl.h>
#include <vector>
#include <iostream>
#include "AbstractParticle.h"

class AbstractFirework
{
public:
	double x, y, z;
	double xSpeed, ySpeed, zSpeed;
	double r, g, b, a;
	
	virtual void initialise() = 0;
	virtual void explode() = 0;

	void applyForce(double fx, double fy, double fz);	
	void move();
	void draw();
	void tick();

	static const double GRAVITY;

private:
	static const double HI_launchYSpeed;
	static const double LO_launchYSpeed;
	static const double HI_X;
	static const double LO_X;
	static const int HI_delayBeforeLaunch;
	static const int LO_delayBeforeLaunch;
	static const int HI_delayBeforeExplosion;
	static const int LO_delayBeforeExplosion;
	static const int nbParticlesExplosion;
	static const double explosionParticleSpeed;
	static const int lifespanExplosionParticles;

	int delayBeforeLaunch;
	int delayBeforeExplosion;
	bool isLaunched;
	bool isExploding;

	std::vector<AbstractParticle> particules;
};

#endif