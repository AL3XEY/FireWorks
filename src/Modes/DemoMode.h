#ifndef DEF_SANBOXMODE
#define DEF_SANBOXMODE


#include <GLEW/glew.h>
#include <src\FireWorks\Firework.h>
#include <src\FireWorks\SphereFirework.h>
#include <vector>
#include <memory>

class DemoMode
{
	public:
		std::vector<std::unique_ptr<AbstractFirework>> vect_fw; // Create our array of fireworks
		DemoMode();
		void drawScene();
		void drawTest();
		void update();

	private:
		static const int nbFirework, nbSphereFirework;
};


#endif