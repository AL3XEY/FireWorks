#ifndef DEF_OPENGLWINDOW
#define DEF_OPENGLWINDOW

// Includes 
#include <GLEW/glew.h>
#include <SDL/SDL.h>
#include <iostream>
#include <string>

const int maxFPS = 60;
// Classe
class SDL_GLEW_Window {
public:
	SDL_GLEW_Window(std::string titreFenetre, int largeurFenetre, int hauteurFenetre);
	~SDL_GLEW_Window();

	bool initialiserFenetre();
	bool initGL();
	void bouclePrincipale();

private:
	std::string m_titreFenetre;
	int m_largeurFenetre;
	int m_hauteurFenetre;

	SDL_Window* m_fenetre;
	SDL_GLContext m_contexteOpenGL;
	SDL_Event m_evenements;	

	void drawTest();
};

#endif