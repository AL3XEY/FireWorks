#ifndef TRACER_FIREWORK_H
#define TRACER_FIREWORK_H

#include <GLEW/glew.h>
#include <cstdlib>
#include <windows.h> // *** IMPORTANT: Uncomment for Win32 systems - This must come -BEFORE- gl.h in the include list! ***
#include <GL/gl.h>
#include <vector>
#include <src\Particles\Particle.h>
#include <src\Fireworks\AbstractFirework.h>
#include <src/Tweeks/openGLGetErrors.h>
#include <src/Modes/DemoMode.h>

class TracerFirework : public AbstractFirework
{
	public:
		TracerFirework();
		TracerFirework(double launchDelay, double explodeDelay, double xx, double yy, double zz, double vxx, double vyy, double vzz, double rr, double gg, double bb, double aa);
		~TracerFirework();

		void initialise();
		void initialise(double launchDelay, double explodeDelay, double xx, double yy, double zz, double vxx, double vyy, double vzz, double rr, double gg, double bb, double aa);
		int draw();
		void explode();
		void updateData();

	private:
		int nbParticulesTraine, lengthTraine;
};

#endif