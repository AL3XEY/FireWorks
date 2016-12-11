#ifndef EXPLOSIVEFIREWORK_H
#define EXPLOSIVEFIREWORK_H

#include <GLEW/glew.h>
#include <cstdlib>
#include <windows.h> // *** IMPORTANT: Uncomment for Win32 systems - This must come -BEFORE- gl.h in the include list! ***
#include <GL/gl.h>
#include <vector>
#include <src\Particles\ExplosiveParticle.h>
#include <src\Fireworks\AbstractFirework.h>

class ExplosiveFirework : public AbstractFirework
{
	using AbstractFirework::AbstractFirework;

public:
	void explode();
};

#endif