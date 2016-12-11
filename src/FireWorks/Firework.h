#ifndef FIREWORK_H
#define FIREWORK_H

#include <GLEW/glew.h>
#include <cstdlib>
#include <windows.h> // *** IMPORTANT: Uncomment for Win32 systems - This must come -BEFORE- gl.h in the include list! ***
#include <GL/gl.h>
#include <vector>
#include "Particle.h"
#include "AbstractFirework.h"

class Firework : public AbstractFirework
{
	public:
		void explode();
};

#endif