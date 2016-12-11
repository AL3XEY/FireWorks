#include "ExplosiveParticle.h"

const int ExplosiveParticle::nbParticlesExplosion = 5;
const double ExplosiveParticle::explosionParticleSpeed = 0.5;

ExplosiveParticle::ExplosiveParticle() : AbstractParticle(),
	isExploding(false),
	isDone(false)
{
	
}

ExplosiveParticle::ExplosiveParticle(double _x, double _y, double _z, double _xSpeed, double _ySpeed, double _zSpeed, int _lifespan)
	: AbstractParticle(_x, _y, _z, _xSpeed, _ySpeed, _zSpeed, _lifespan),
	isExploding(false),
	isDone(false)
{

}

void ExplosiveParticle::tick()
{
	if (lifespan > 0) {
		lifespan--;
	} else if (!isExploding) {
		isExploding = true;
		explode();
	} else {
		bool allParticlesDone = true;
		for (Particle &p : sousParticules) {
			p.tick();
			if (!p.done())
				allParticlesDone = false;
		}
		if (isExploding && allParticlesDone) {
			isDone = true;
		}
	}				
}

void ExplosiveParticle::explode()
{
	//std::cout << "BOOM BOOM! " << std::endl;
	//initialise();
	for (int i = 0; i < nbParticlesExplosion; i++) {
		double partXSpeed = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		double partYSpeed = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		double partZSpeed = -explosionParticleSpeed + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 2)));
		sousParticules.push_back(Particle(x, y, z, partXSpeed, partYSpeed, partZSpeed, 50));
	}
}

bool ExplosiveParticle::done() {
	return isDone;
}

void ExplosiveParticle::move()
{
	if (!isExploding) {
		x += xSpeed;
		y += ySpeed;
		z += zSpeed;
	} else {
		for (Particle &p : sousParticules) {
			p.move();
		}
	}	
}

void ExplosiveParticle::applyForce(double fx, double fy, double fz)
{
	if (!isExploding) {
		xSpeed += fx;
		ySpeed += fy;
		zSpeed += fz;
	} else {
		for (Particle &p : sousParticules) {
			p.applyForce(fx, fy, fz);
		}
	}	
}

void ExplosiveParticle::draw()
{
	if (!isExploding) {
		double vertices[] = { x, y, z };
		glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);
		glDrawArrays(GL_POINTS, 0, 1);
		glDisableVertexAttribArray(0);
	}
	else {
		for (Particle &p : sousParticules) {
			p.draw();
		}
	}
}