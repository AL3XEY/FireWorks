#include "HeartFirework.h"
#include <iostream>

void HeartFirework::explode()
{
	std::cout << "boom!" << std::endl;
	//initialise();
	for (int i = 0; i < nbParticlesExplosion; i++) {
		const double PI = 3.1415926535897;
		double angle = i*2*PI/nbParticlesExplosion;

		double partXSpeed = cos(angle) * heartFunction(angle);
		double partYSpeed = sin(angle) * heartFunction(angle);
		double partZSpeed = 0.0;

		particules.push_back(Particle(x, y, z, partXSpeed, partYSpeed, partZSpeed, 50));
	}
}

double HeartFirework::heartFunction(double angle) {
	return (2 - 2 * sin(angle) + sin(angle)*sqrt(abs(cos(angle))) / (sin(angle) + 1.4));
}