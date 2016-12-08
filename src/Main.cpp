#include "OpenGlWindow/OpenGlWindow.hpp"

int main(int argc, char **argv) {
	// Création de la sène

	OpenGlWindow window("FireWorks", 800, 600);

	// Initialisation de la scène
	if (window.initialiserFenetre() == false)
		exit(EXIT_FAILURE);

	if (!window.initGL())
		exit(EXIT_FAILURE);


	// Boucle Principale
	window.bouclePrincipale();

	// Fin du programme
	exit(EXIT_SUCCESS);
}