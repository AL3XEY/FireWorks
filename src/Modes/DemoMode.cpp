#include "DemoMode.h"

const int DemoMode::nbMaxFirework = 30;

DemoMode::DemoMode() 
{
	vect_fw.resize(nbMaxFirework);
}

void DemoMode::drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	for(Firework &fw : vect_fw) {
		fw.draw();
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
	for(Firework &fw : vect_fw) {
		fw.tick();
		fw.move();
		fw.applyForce(0, Firework::GRAVITY);
	}
}