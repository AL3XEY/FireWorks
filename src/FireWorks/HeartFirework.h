#ifndef HEARTFIREWORK_H
#define HEARTFIREWORK_H

#include <GLEW/glew.h>
#include <cstdlib>
#include <windows.h> // *** IMPORTANT: Uncomment for Win32 systems - This must come -BEFORE- gl.h in the include list! ***
#include <GL/gl.h>
#include <vector>
#include <src\Particles\Particle.h>
#include <src\Fireworks\AbstractFirework.h>

class HeartFirework : public AbstractFirework
{
	using AbstractFirework::AbstractFirework;

	public:
		void explode();
		double heartFunction(double angle);
};

#endif