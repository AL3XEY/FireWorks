#include "BouquetFirework.h"
#include <iostream>

const int BouquetFirework::nbParticlesExplosion = 100;

BouquetFirework::~BouquetFirework() {
	delete[] m_vertices;
	glDeleteBuffers(1, &m_vboID);
}

void BouquetFirework::explode()
{
	//std::cout << "boom!" << std::endl;
	//initialise();
	for (int i = 0; i < nbParticlesExplosion; i++) {
		double vy = explosionParticleSpeed*0.2 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 1.0)));
		double vx = -vy * 0.5 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (vy)));
		double vz = -vy * 0.5 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (vy)));
		
		particules.push_back(std::move(std::unique_ptr<AbstractParticle>(new Particle(x, y, z, vx, vy, vz, 50))));
	}

	// G�n�re les points � donner au GPU
	m_vertices = new double[nbParticlesExplosion * 3];
	for (int i = 0; i < nbParticlesExplosion; i++) {
		m_vertices[i * 3 + 0] = particules.at(i)->x;
		m_vertices[i * 3 + 1] = particules.at(i)->y;
		m_vertices[i * 3 + 2] = particules.at(i)->z;
	}

	glGenBuffers(1, &m_vboID); // R�cup�ration de l'ID
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID); // Verrouillage du VBO
	glBufferData(GL_ARRAY_BUFFER, nbParticlesExplosion * sizeof(double) * 3, m_vertices, GL_STREAM_COPY);  // Transfert des vertices
	glBindBuffer(GL_ARRAY_BUFFER, 0); // D�verrouillage de l'objet

	openGLGetErrors();
}

int BouquetFirework::draw()
{
	int nbParticules = 0;
	glColor3d(r, g, b);
	if (isLaunched)
	{
		if (!isExploding) {
			// Draw la fus�e
			double vertices[] = { x, y , z };
			glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, vertices);
			glEnableVertexAttribArray(0);
			glPointSize(2.0);
			glDrawArrays(GL_POINTS, 0, 1);
			glDisableVertexAttribArray(0);
			nbParticules++;
		} else {
			// Draw les particules �mises par l'explosion
			glBindBuffer(GL_ARRAY_BUFFER, m_vboID); // On bind 
			glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, 0); // Acc�s aux vertices dans la m�moire vid�o
			glEnableVertexAttribArray(0);
			glDrawArrays(GL_POINTS, 0, nbParticlesExplosion);
			glDisableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			nbParticules+= nbParticlesExplosion;
		}
	}
	openGLGetErrors();
	return nbParticules;
}

void BouquetFirework::updateData() {
	if (isExploding) {
		glBindBuffer(GL_ARRAY_BUFFER, m_vboID); // Verrouillage du VBO
		void *adresseVBO = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY); // R�cup�ration de l'adresse du VBO

		if (adresseVBO == NULL) { // Si l'adresse retourn�e est nulle alors on arr�te le transfert
			std::cout << "Erreur au niveau de la r�cup�ration du VBO" << std::endl;
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			return;
		}

		// ReG�n�re les points � donner au GPU
		for (int i = 0; i < nbParticlesExplosion; i++) {
			m_vertices[i * 3 + 0] = particules.at(i)->x;
			m_vertices[i * 3 + 1] = particules.at(i)->y;
			m_vertices[i * 3 + 2] = particules.at(i)->z;
		}
		memcpy(adresseVBO, m_vertices, nbParticlesExplosion * 3 * sizeof(double)); // Mise � jour des donn�es

		glUnmapBuffer(GL_ARRAY_BUFFER); // Annulation du pointeur
		adresseVBO = 0;

		glBindBuffer(GL_ARRAY_BUFFER, 0); // D�verrouillage du VBO
	}	
}
