#include "DemoMode.h"

const int DemoMode::nbFirework = 30;
const int DemoMode::nbSphereFirework = 30;

DemoMode::DemoMode() 
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
	double r = (double(rand()) / double(RAND_MAX));
	if (r < 0.01)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new BoxFirework)));
	else if (r < 0.02)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new SphereFirework)));
	else if (r < 0.03)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new Firework)));

	for (int i = 0; i < vect_fw.size(); i++) {
		if (vect_fw.at(i)->done()) {
			vect_fw.erase(vect_fw.begin() + i);
			i--;
		}
	}
		
	for (auto fw(vect_fw.begin()), ite(vect_fw.end()); fw != ite; fw++) {
		(*fw)->tick();
		(*fw)->move();
		(*fw)->applyForce(0.0, AbstractFirework::GRAVITY, 0.0);	
	}
}