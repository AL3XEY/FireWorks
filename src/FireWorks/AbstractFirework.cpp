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

AbstractFirework::AbstractFirework(double launchDelay, double xx, double yy, double zz, double vxx, double vyy, double vzz, double rr, double gg, double bb, double aa)
{
	// We call a function to perform the constructor's job here so that we can re-initialise the same firework
	// later on without having to destroy the object and recreate it!
	initialise(launchDelay, xx, yy, zz, vxx, vyy, vzz, rr, gg, bb, aa);
}

AbstractFirework::~AbstractFirework()
{

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

void AbstractFirework::initialise(double launchDelay, double xx, double yy, double zz, double vxx, double vyy, double vzz, double rr, double gg, double bb, double aa)
{
	std::cout << "initialise with parameters" << std::endl;
	x = xx;
	y = yy;
	z = zz;
	xSpeed = vxx;
	ySpeed = vyy;
	zSpeed = vzz;

	r = rr;
	g = gg;
	b = bb;
	a = aa;

	//delayBeforeLaunch = LO_delayBeforeLaunch + static_cast <int> (rand()) / (static_cast <int> (RAND_MAX / (HI_delayBeforeLaunch - LO_delayBeforeLaunch)));
	delayBeforeLaunch = launchDelay;
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
		//std::cout << "launched ! " << std::endl;
	}
	else {
		delayBeforeLaunch--;
	}

	bool allParticlesDone = true;
	for (auto p(particules.begin()), ite(particules.end()); p != ite; p++) {
		(*p)->tick();
		if (!(*p)->done())
			allParticlesDone = false;
	}

	if (isExploding && allParticlesDone) {
		isDone = true;
	}
}

void AbstractFirework::move()
{
	if (isLaunched)
	{
		x += xSpeed;
		y += ySpeed;

		for (auto p(particules.begin()), ite(particules.end()); p != ite; p++) {
			(*p)->move();
		}
	}
}

void AbstractFirework::applyForce(double fx, double fy, double fz) {
	if (isLaunched)
	{
		xSpeed += fx;
		ySpeed += fy;
		for (auto p(particules.begin()), ite(particules.end()); p != ite; p++) {
			(*p)->applyForce(fx, fy, fz);
		}
	}
}

bool AbstractFirework::done() {
	return isDone;
}

void AbstractFirework::updateData()
{
}

int AbstractFirework::draw()
{
	int nbParticulesDrawn = 0;
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
			nbParticulesDrawn++;
		}

		for (auto p(particules.begin()), ite(particules.end()); p != ite; p++) {
			nbParticulesDrawn += (*p)->draw();
		}
	}
	return nbParticulesDrawn;
}