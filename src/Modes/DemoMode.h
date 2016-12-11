#ifndef DEF_DEMOMODE
#define DEF_DEMOMODE


#include <GLEW/glew.h>
#include <src\FireWorks\AbstractFirework.h>
#include <src\FireWorks\Firework.h>
#include <src\FireWorks\SphereFirework.h>
#include <src\FireWorks\BoxFirework.h>
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