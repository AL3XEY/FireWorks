#include "Firework.h"
#include <iostream>

void Firework::explode()
{
	std::cout << "boom!" << std::endl;
	//initialise();
	for (int i = 0; i < nbParticlesExplosion; i++) {
		double partXSpeed = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		double partYSpeed = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		double partZSpeed = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		particules.push_back(Particle(x, y, z, partXSpeed, partYSpeed, partZSpeed, 50));
	}
}