#ifndef SPHERE_FIREWORK_H
#define SPHERE_FIREWORK_H

#include <GLEW/glew.h>
#include <cstdlib>
#include <windows.h> // *** IMPORTANT: Uncomment for Win32 systems - This must come -BEFORE- gl.h in the include list! ***
#include <GL/gl.h>
#include <vector>
#include "Particle.h"
#include "AbstractFirework.h"

class SphereFirework : public AbstractFirework
{
	public:
		void explode();
};

#endif