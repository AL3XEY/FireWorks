#ifndef FIREWORK_H
#define FIREWORK_H

#include <GLEW/glew.h>
#include <cstdlib>
#include <windows.h> // *** IMPORTANT: Uncomment for Win32 systems - This must come -BEFORE- gl.h in the include list! ***
#include <GL/gl.h>
#include <vector>
#include <src\Particles\Particle.h>
#include <src\Fireworks\AbstractFirework.h>
#include <src/Tweeks/openGLGetErrors.h>
#include <src/Modes/DemoMode.h>

class Firework : public AbstractFirework
{
	using AbstractFirework::AbstractFirework;
	~Firework();

	public:
		void explode();
		int draw();
		void updateData();

	private:
};

#endif