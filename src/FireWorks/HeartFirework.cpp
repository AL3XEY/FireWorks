#include "HeartFirework.h"
#include <iostream>

void HeartFirework::explode()
{
	//initialise();
	for (int i = 0; i < nbParticlesExplosion; i++) {
		const double PI = 3.1415926535897;
		double angle = i*2*PI/nbParticlesExplosion;

		double vx = cos(angle) * heartFunction(angle) / 2.0;
		double vy = sin(angle) * heartFunction(angle) / 2.0;
		double vz = 0.0;

		particules.push_back(std::move(std::unique_ptr<AbstractParticle>(new Particle(x, y, z, vx, vy, vz, 50))));
	}
}

double HeartFirework::heartFunction(double angle) {
	return (2 - 2 * sin(angle) + sin(angle)*sqrt(abs(cos(angle))) / (sin(angle) + 1.4));
}