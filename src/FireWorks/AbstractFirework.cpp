#include "AbstractFirework.h"

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