#ifndef BOXFIREWORK_H
#define BOXFIREWORK_H

#include <GLEW/glew.h>
#include <cstdlib>
#include <windows.h> // *** IMPORTANT: Uncomment for Win32 systems - This must come -BEFORE- gl.h in the include list! ***
#include <GL/gl.h>
#include <vector>
#include "Particle.h"
#include "AbstractFirework.h"

class BoxFirework : public AbstractFirework
{
public:
	void explode();
};

#endif