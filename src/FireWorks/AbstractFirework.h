#ifndef ABSTRACT_FIREWORK_H
#define ABSTRACT_FIREWORK_H

#include <GLEW/glew.h>
#include <windows.h> // *** IMPORTANT: Uncomment for Win32 systems - This must come -BEFORE- gl.h in the include list! ***
#include <GL/gl.h>
#include <vector>
#include <iostream>
#include <src\Particles\AbstractParticle.h>
#include <src\Particles\Particle.h>
#include <memory>

class AbstractFirework
{
public:
	double x, y, z;
	double xSpeed, ySpeed, zSpeed;
	double r, g, b, a;

	explicit AbstractFirework();
	explicit AbstractFirework(double launchDelay, double xx, double yy, double zz, double vxx, double vyy, double vzz, double rr, double gg, double bb, double aa);
	~AbstractFirework();

	virtual void explode() = 0;
	virtual int draw();
	virtual void updateData();

	void initialise();
	void initialise(double launchDelay, double xx, double yy, double zz, double vxx, double vyy, double vzz, double rr, double gg, double bb, double aa);
	void tick();
	void applyForce(double fx, double fy, double fz);	
	void move();	
	bool done();	

	static const double GRAVITY;

protected:
	static const double HI_launchYSpeed;
	static const double LO_launchYSpeed;
	static const double HI_X;
	static const double LO_X;
	//static const int HI_delayBeforeLaunch;
	//static const int LO_delayBeforeLaunch;
	static const int HI_delayBeforeExplosion;
	static const int LO_delayBeforeExplosion;
	static const int nbParticlesExplosion;
	static const double explosionParticleSpeed;
	static const int lifespanExplosionParticles;

	int delayBeforeLaunch;
	int delayBeforeExplosion;
	bool isLaunched, isExploding, isDone;

	GLuint m_vboID;
	double* m_vertices;

	std::vector<std::unique_ptr<AbstractParticle>> particules;
};

#endif