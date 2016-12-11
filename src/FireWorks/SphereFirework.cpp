#include "SphereFirework.h"
#include <iostream>


void SphereFirework::explode()
{
	std::cout << "boom ! " << std::endl;
	//initialise();
	for (int i = 0; i < nbParticlesExplosion; i++) {
		double vx = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		double vy = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		double vz = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));

		double length = sqrt(vx*vx + vy*vy + vz*vz);

		vx = vx / length;
		vy = vy / length;
		vz = vz / length;

		particules.push_back(Particle(x, y, z, vx, vy, vz, 50));
	}
}