#include "SDL_GLEW_Window/SDL_GLEW_Window.h"

int main(int argc, char **argv) {
	// Cr�ation de la s�ne

	SDL_GLEW_Window window("FireWorks", 800, 600);

	// Initialisation de la sc�ne
	if (window.initialiserFenetre() == false)
		exit(EXIT_FAILURE);

	if (!window.initGL())
		exit(EXIT_FAILURE);

	// Boucle Principale
	window.bouclePrincipale();

	// Fin du programme
	exit(EXIT_SUCCESS);
}