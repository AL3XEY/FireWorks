#include "TracerFirework.h"
#include <iostream>

TracerFirework::TracerFirework() {
	TracerFirework::initialise();
}

TracerFirework::TracerFirework(double launchDelay, double explodeDelay, double xx, double yy, double zz, double vxx, double vyy, double vzz, double rr, double gg, double bb, double aa) {
	TracerFirework::initialise(launchDelay, explodeDelay, xx, yy, zz, vxx, vyy, vzz, rr, gg, bb, aa);
}

TracerFirework::~TracerFirework() {
	delete[] m_vertices;
	glDeleteBuffers(1, &m_vboID);
}

void TracerFirework::initialise() {
	AbstractFirework::initialise();

	nbParticulesTraine = 0;
	lengthTraine = 50;

	m_vertices = new double[lengthTraine * 3];

	glGenBuffers(1, &m_vboID); // Récupération de l'ID
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID); // Verrouillage du VBO
	glBufferData(GL_ARRAY_BUFFER, lengthTraine * sizeof(double) * 3, m_vertices, GL_STREAM_COPY);  // Transfert des vertices
	glBindBuffer(GL_ARRAY_BUFFER, 0); // Déverrouillage de l'objet
	openGLGetErrors();
}

void TracerFirework::initialise(double launchDelay, double explodeDelay, double xx, double yy, double zz, double vxx, double vyy, double vzz, double rr, double gg, double bb, double aa) {
	AbstractFirework::initialise(launchDelay, explodeDelay, xx, yy, zz, vxx, vyy, vzz, rr, gg, bb, aa);
	
	nbParticulesTraine = 0;
	lengthTraine = 50;

	m_vertices = new double[lengthTraine * 3];

	glGenBuffers(1, &m_vboID); // Récupération de l'ID
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID); // Verrouillage du VBO
	glBufferData(GL_ARRAY_BUFFER, lengthTraine * sizeof(double) * 3, m_vertices, GL_STREAM_COPY);  // Transfert des vertices
	glBindBuffer(GL_ARRAY_BUFFER, 0); // Déverrouillage de l'objet
	openGLGetErrors();
}

void TracerFirework::explode()
{
}

int TracerFirework::draw()
{
	int nbParticules = 0;
	glColor3d(r, g, b);
	if (isLaunched)
	{
		if (!isExploding) {
			// Draw la fusée
			double vertices[] = { x, y , z };
			glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, vertices);
			glEnableVertexAttribArray(0);
			glPointSize(2.0);
			glDrawArrays(GL_POINTS, 0, 1);
			glDisableVertexAttribArray(0);
			nbParticules++;
		}

		// Draw les particules émises par la traine
		glBindBuffer(GL_ARRAY_BUFFER, m_vboID); // On bind 
		glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, 0); // Accès aux vertices dans la mémoire vidéo
		glEnableVertexAttribArray(0);
		glPointSize(1.0);
		glDrawArrays(GL_POINTS, 0, nbParticulesTraine);
		glDisableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		nbParticules+= nbParticulesTraine;
	}
	openGLGetErrors();
	return nbParticules;
}

void TracerFirework::updateData() {
	if (isLaunched) {
		// Création des particules de traine
		for (int i = 0; i < particules.size(); i++) {
			if (particules.at(i)->done()) {
				particules.erase(particules.begin() + i);
				i--;
				nbParticulesTraine--;
			}
		}
		if (!isExploding && nbParticulesTraine < lengthTraine) {
			double r = (double(rand()) / double(RAND_MAX));
			if (r > 0.5) {
				double vx = -explosionParticleSpeed*0.1 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 0.2)));
				double vy = -explosionParticleSpeed*0.1 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 0.2)));
				double vz = -explosionParticleSpeed*0.1 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (explosionParticleSpeed * 0.2)));

				particules.push_back(std::move(std::unique_ptr<AbstractParticle>(new Particle(x, y, z, vx, vy, vz, 50))));
				nbParticulesTraine++;
			}
		}

		// Envoi des vertices au VBO
		glBindBuffer(GL_ARRAY_BUFFER, m_vboID); // Verrouillage du VBO
		void *adresseVBO = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY); // Récupération de l'adresse du VBO

		if (adresseVBO == NULL) { // Si l'adresse retournée est nulle alors on arrête le transfert
			std::cout << "Erreur au niveau de la récupération du VBO" << std::endl;
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			return;
		}

		// ReGénère les points à donner au GPU
		for (int i = 0; i < nbParticulesTraine; i++) {
			m_vertices[i * 3 + 0] = particules.at(i)->x;
			m_vertices[i * 3 + 1] = particules.at(i)->y;
			m_vertices[i * 3 + 2] = particules.at(i)->z;
		}
		memcpy(adresseVBO, m_vertices, nbParticulesTraine * 3 * sizeof(double)); // Mise à jour des données

		glUnmapBuffer(GL_ARRAY_BUFFER); // Annulation du pointeur
		adresseVBO = 0;

		glBindBuffer(GL_ARRAY_BUFFER, 0); // Déverrouillage du VBO
	}	
}
