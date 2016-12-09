#ifndef DEF_SANBOXMODE
#define DEF_SANBOXMODE


#include <GLEW/glew.h>
#include "../FireWorks/Firework.h"
#include <vector>

class DemoMode
{
	public:
		std::vector<Firework> vect_fw; // Create our array of fireworks
		DemoMode();
		void drawScene();
		void drawTest();
		void update();

	private:
		static const int nbMaxFirework;
};


#endif