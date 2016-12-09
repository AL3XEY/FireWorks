#include "SphereFirework.h"
#include <iostream>


// Set our static (per class NOT per object!) variable values
const double SphereFirework::GRAVITY = -0.00004;
const double SphereFirework::HI_launchYSpeed = 0.012;
const double SphereFirework::LO_launchYSpeed = 0.008;
const double SphereFirework::HI_X = 1.0;
const double SphereFirework::LO_X = -1.0;
const int SphereFirework::HI_delayBeforeLaunch = 500;
const int SphereFirework::LO_delayBeforeLaunch = 0;
const int SphereFirework::HI_delayBeforeExplosion = 350;
const int SphereFirework::LO_delayBeforeExplosion = 150;
const int SphereFirework::nbParticlesExplosion = 50;
const double SphereFirework::explosionParticleSpeed = 0.01;
const int SphereFirework::lifespanExplosionParticles = 50;

// Constructor implementation
SphereFirework::SphereFirework()
{
	// We call a function to perform the constructor's job here so that we can re-initialise the same firework
	// later on without having to destroy the object and recreate it!
    initialise();
}

void SphereFirework::initialise()
{
	x = LO_X + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (HI_X - LO_X)));
	y = -1.0;
	z = LO_X + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (HI_X - LO_X)));
	xSpeed = 0.0;
	ySpeed = LO_launchYSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (HI_launchYSpeed - LO_launchYSpeed)));
	zSpeed = 0.0;

	r = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX));
	g = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX));
	b = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX));

	delayBeforeLaunch = LO_delayBeforeLaunch + static_cast <int> (rand()) / (static_cast <int> (RAND_MAX / (HI_delayBeforeLaunch - LO_delayBeforeLaunch)));
	delayBeforeExplosion = LO_delayBeforeExplosion + static_cast <int> (rand()) / (static_cast <int> (RAND_MAX / (HI_delayBeforeExplosion - LO_delayBeforeExplosion)));
	isLaunched = false;
	isExploding = false;

	particules.resize(0);

    //std::cout << "Initialised a firework." << std::endl;
}

void SphereFirework::tick()
{
	if (isLaunched) {
		if (!isExploding && delayBeforeExplosion == 0) {
			isExploding = true;
			explode();
		}
		else {
			delayBeforeExplosion--;
		}
	}

	if (!isLaunched && delayBeforeLaunch == 0) {
		isLaunched = true;
		std::cout << "launched ! " << std::endl;
	}
	else {
		delayBeforeLaunch--;
	}	
	
	for (Particle &p : particules) {
		p.tick();
	}
}

void SphereFirework::move()
{
	if (isLaunched)
	{
		x += xSpeed;
		y += ySpeed;

		for (Particle &p : particules) {
			p.move();
		}
	}	
}

void SphereFirework::applyForce(double fx, double fy, double fz) {
	if (isLaunched)
	{
		xSpeed += fx;
		ySpeed += fy;
		for (Particle &p : particules) {
			p.applyForce(fx, fy, fz);
		}		
	} 
}

void SphereFirework::explode()
{
	std::cout << "boom ! " << std::endl;
	//initialise();
	for (int i = 0; i < nbParticlesExplosion; i++) {
		double partXSpeed = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		double partYSpeed = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		double partZSpeed = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		particules.push_back(Particle(x, y, 0, partXSpeed, partYSpeed, partZSpeed, 50));
	}
}

void SphereFirework::draw()
{
	glColor3d(r, g, b);
	if (isLaunched)
	{
		if (!isExploding) {
			//std::cout << "draw : x=" << x << " y=" << y << std::endl;
			double vertices[] = { x, y , z };
			glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, vertices);
			glEnableVertexAttribArray(0);
			glDrawArrays(GL_POINTS, 0, 1);
			glDisableVertexAttribArray(0);
		}
		
		for (Particle &p : particules) {
			p.draw();
		}	
	}		
}