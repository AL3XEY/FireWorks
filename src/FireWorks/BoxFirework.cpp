#include "BoxFirework.h"
#include <iostream>



void BoxFirework::explode()
{
	//initialise();
	for (int i = 0; i < nbParticlesExplosion; i++) {
		double vx = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		double vy = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		double vz = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		
		if (i < (nbParticlesExplosion / 6))
			vx = -1.0;
		else if (i < (nbParticlesExplosion / 6) * 2)
			vx = 1.0;
		else if (i < (nbParticlesExplosion / 6) * 3)
			vy = -1.0;
		else if (i < (nbParticlesExplosion / 6) * 4)
			vy = 1.0;
		else if (i < (nbParticlesExplosion / 6) * 5)
			vz = -1.0;
		else
			vz = 1.0;


		particules.push_back(std::move(std::unique_ptr<AbstractParticle>(new Particle(x, y, z, vx, vy, vz, 50))));
	}
}