#include "DemoMode.h"

const int DemoMode::nbFirework = 30;
const int DemoMode::nbSphereFirework = 30;

DemoMode::DemoMode():
	camDist(500),
	camLookY(250),
	camAngleX(0),
	mouseButtonRight(false)
{

	/*for (int i = 0; i < nbFirework; i++) {
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new Firework)));
	}
		
	for (int i = 0; i < nbSphereFirework; i++)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new SphereFirework)));*/
}

void DemoMode::drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	for(auto fw(vect_fw.begin()), ite(vect_fw.end()); fw != ite; ++fw) {
		(*fw)->draw();
	}	
}

void DemoMode::drawTest() {
	double vertices[] = { -0.5, -0.5, 0.2, 0.5, 0.5, -0.5 };
	glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, 0, vertices);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}

void DemoMode::update()
{
	manageEvents();

	manageCamera();

	addRandomFireworks();
		
	for (auto fw(vect_fw.begin()), ite(vect_fw.end()); fw != ite; fw++) {
		(*fw)->tick();
		(*fw)->move();
		(*fw)->applyForce(0.0, AbstractFirework::GRAVITY, 0.0);	
	}
}

void DemoMode::manageEvents() {
	// Gestion des évènements
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_RIGHT)
				mouseButtonRight = true;
			break;

		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_RIGHT)
				mouseButtonRight = false;
			break;

		case SDL_MOUSEMOTION:
			if (mouseButtonRight) {
				camAngleX += event.motion.xrel * 0.1;
				camLookY += event.motion.yrel;
				if (camLookY < 250)
					camLookY = 250;
			}
			break;

		case SDL_MOUSEWHEEL:
			camDist -= event.wheel.y * 10.0;
			break;

		default:
			break;
		}
	}
}

void DemoMode::manageCamera() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, (camDist / 2.0), camDist, 0, camLookY, 0, 0, 1, 0);
	camAngleX += 0.3;
	glRotated(camAngleX, 0, 1, 0);
}

void DemoMode::addRandomFireworks() {
	// Ajout de Fireworks
	double r = (double(rand()) / double(RAND_MAX));
	/*if (r < 0.01)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new HeartFirework)));
	else if (r < 0.02)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new SphereFirework)));
	else if (r < 0.03)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new Firework)));
	else if (r < 0.04)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new BoxFirework)));
	else */if (r < 0.05)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new ExplosiveFirework())));

	for (unsigned int i = 0; i < vect_fw.size(); i++) {
		if (vect_fw.at(i)->done()) {
			vect_fw.erase(vect_fw.begin() + i);
			i--;
		}
	}
}