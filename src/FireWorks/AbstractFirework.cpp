#include "AbstractFirework.h"

// Set our static (per class NOT per object!) variable values
const double AbstractFirework::GRAVITY = -0.004;
const double AbstractFirework::HI_launchYSpeed = 2.0;
const double AbstractFirework::LO_launchYSpeed = 1.5;
const double AbstractFirework::HI_X = 200.0;
const double AbstractFirework::LO_X = -200.0;
//const int AbstractFirework::HI_delayBeforeLaunch = 500;
//const int AbstractFirework::LO_delayBeforeLaunch = 0;
const int AbstractFirework::HI_delayBeforeExplosion = 350;
const int AbstractFirework::LO_delayBeforeExplosion = 150;
const int AbstractFirework::nbParticlesExplosion = 500;
const double AbstractFirework::explosionParticleSpeed = 1.0;
const int AbstractFirework::lifespanExplosionParticles = 50;

// Constructor implementation
AbstractFirework::AbstractFirework()
{
	// We call a function to perform the constructor's job here so that we can re-initialise the same firework
	// later on without having to destroy the object and recreate it!
	initialise();
}

void AbstractFirework::initialise()
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

	//delayBeforeLaunch = LO_delayBeforeLaunch + static_cast <int> (rand()) / (static_cast <int> (RAND_MAX / (HI_delayBeforeLaunch - LO_delayBeforeLaunch)));
	delayBeforeLaunch = 0;
	delayBeforeExplosion = LO_delayBeforeExplosion + static_cast <int> (rand()) / (static_cast <int> (RAND_MAX / (HI_delayBeforeExplosion - LO_delayBeforeExplosion)));
	isLaunched = false;
	isExploding = false;

	particules.resize(0);
}

void AbstractFirework::tick()
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

	for (AbstractParticle &p : particules) {
		p.tick();
	}
}

void AbstractFirework::move()
{
	if (isLaunched)
	{
		x += xSpeed;
		y += ySpeed;

		for (AbstractParticle &p : particules) {
			p.move();
		}
	}
}

void AbstractFirework::applyForce(double fx, double fy, double fz) {
	if (isLaunched)
	{
		xSpeed += fx;
		ySpeed += fy;
		for (AbstractParticle &p : particules) {
			p.applyForce(fx, fy, fz);
		}
	}
}

void AbstractFirework::draw()
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

		for (AbstractParticle &p : particules) {
			p.draw();
		}
	}
}