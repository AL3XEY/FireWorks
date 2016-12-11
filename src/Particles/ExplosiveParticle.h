#ifndef EXPLOSIVEPARTICLE_H
#define EXPLOSIVEPARTICLE_H

#include <GLEW/glew.h>
#include <GL/gl.h>
#include <iostream>
#include <src\Particles\AbstractParticle.h>
#include <src\Particles\Particle.h>
#include <vector>

class ExplosiveParticle : public AbstractParticle
{
	public:
		ExplosiveParticle();
		ExplosiveParticle(double _x, double _y, double _z, double _xSpeed, double _ySpeed, double _zSpeed, int _lifespan);

		void explode();

		void move() override;
		void applyForce(double fx, double fy, double fz) override;
		void draw() override;
		void tick() override;
		bool done() override;

	protected:
		static const int nbParticlesExplosion;
		static const double explosionParticleSpeed;


		bool isExploding, isDone;
		std::vector<Particle> sousParticules;
};

#endif