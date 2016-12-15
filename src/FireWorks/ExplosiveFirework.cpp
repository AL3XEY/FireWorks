#include "ExplosiveFirework.h"
#include <iostream>

void ExplosiveFirework::explode()
{
	//std::cout << "E boom!" << std::endl;
	//initialise();
	for (int i = 0; i < nbParticlesExplosion; i++) {
		double vx = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		double vy = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		double vz = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		
		int lifespan = 5;
		int explolifespan = 10 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (100 - 10))); // entre 10 et 100
		particules.push_back(std::move(std::unique_ptr<AbstractParticle>(new ExplosiveParticle(x, y, z, vx, vy, vz, lifespan, explolifespan))));
		//particules.push_back(ExplosiveParticle(x, y, z, partXSpeed, partYSpeed, partZSpeed, 50));
	}
}