#include "indexesVbo.h"

const int IndexesVBO::minimumIndex = 5;
std::vector<vbo> IndexesVBO::mvbos = std::vector<vbo>();

std::vector<vbo>* IndexesVBO::getvbos()
{
	return &mvbos;
}

int IndexesVBO::getNewVbo(int nbParticules)
{
	// Retourne le premier index disponible.
	int i = minimumIndex;
	while (true) {
		if (!contains(i))
		{
			mvbos.push_back(vbo(i, nbParticules));
			return i;
		}
		i++;
	}
}

void IndexesVBO::freeVbo(int index)
{
	for (unsigned int i = 0; i < mvbos.size(); i++) {
		if (mvbos.at(i).indexVBO == index)
		{
			mvbos.erase(mvbos.begin()+i);
			return;
		}
	}	
}

bool IndexesVBO::contains(int index)
{
	for (unsigned int i = 0; i < mvbos.size(); i++) {
		if (mvbos.at(i).indexVBO == index)
		{
			return true;
		}
	}
	return false;
}
