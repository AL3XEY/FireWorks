#ifndef FIREWORK_H
#define FIREWORK_H

#include <GLEW/glew.h>
#include <cstdlib>
#include <windows.h> // *** IMPORTANT: Uncomment for Win32 systems - This must come -BEFORE- gl.h in the include list! ***
#include <GL/gl.h>
#include <vector>
#include "Particle.h"

class Firework
{
	public:
		double x;
		double y;
		double xSpeed;
		double ySpeed;
		double xAccel;
		double yAccel;

		Firework();
		void initialise();
		void move();
		void applyForce(double fx, double fy);
		void explode();
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

		std::vector<Particle> particules;
};

#endif