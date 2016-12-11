#ifndef DEF_DEMOMODE
#define DEF_DEMOMODE


#include <GLEW/glew.h>
#include <src\FireWorks\AbstractFirework.h>
#include <src\FireWorks\Firework.h>
#include <src\FireWorks\SphereFirework.h>
#include <src\FireWorks\BoxFirework.h>
#include <src\FireWorks\HeartFirework.h>
#include <vector>
#include <memory>
#include <algorithm>
#include <SDL/SDL.h>

class DemoMode
{
	public:
		DemoMode();
		void drawScene();
		void drawTest();
		void update();
		void manageEvents();
		void manageCamera();
		void addRandomFireworks();

	private:
		std::vector<std::unique_ptr<AbstractFirework>> vect_fw; // Create our array of fireworks
		static const int nbFirework, nbSphereFirework;

		double camDist, camLookY, camAngleX;
		bool mouseButtonRight;
};


#endif