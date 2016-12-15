#include "ExplosiveParticle.h"

const int ExplosiveParticle::nbParticlesExplosion = 5;
const double ExplosiveParticle::explosionParticleRadius = 1.0;

ExplosiveParticle::ExplosiveParticle() : AbstractParticle(),
	isExploding(false),
	isDone(false)
{
	
}

ExplosiveParticle::ExplosiveParticle(double _x, double _y, double _z, double _xSpeed, double _ySpeed, double _zSpeed, int _lifespan, int _exploLifespan)
	: AbstractParticle(_x, _y, _z, _xSpeed, _ySpeed, _zSpeed, _lifespan),
	isExploding(false),
	isDone(false),
	explodingLifespan(_exploLifespan)
{

}

void ExplosiveParticle::tick()
{
	if (lifespan > 0) {
		lifespan--;
	} else {
		isExploding = true;

		explodingLifespan--;
		if (explodingLifespan == 0) {
			isDone = true;
		}
	}				
}

bool ExplosiveParticle::done() {
	return isDone;
}

void ExplosiveParticle::move()
{
	x += xSpeed;
	y += ySpeed;
	z += zSpeed;
}

void ExplosiveParticle::applyForce(double fx, double fy, double fz)
{
	xSpeed += fx;
	ySpeed += fy;
	zSpeed += fz;
}

int ExplosiveParticle::draw()
{
	if (!isExploding) {
		double vertices[] = { x, y, z };
		glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);
		glDrawArrays(GL_POINTS, 0, 1);
		glDisableVertexAttribArray(0);
		return 1;
	} else if (explodingLifespan > 0) {
		double r = (double(rand()) / double(RAND_MAX));
		if (r > 0.5) {
			double vertices[] = { x, y, z };
			glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, vertices);
			glEnableVertexAttribArray(0);
			glDrawArrays(GL_POINTS, 0, 1);
			glDisableVertexAttribArray(0);
			return 1;
		}
	}	
	return 0;
}