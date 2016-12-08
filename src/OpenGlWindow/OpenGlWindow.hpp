#ifndef DEF_SCENEOPENGL
#define DEF_SCENEOPENGL

// Includes 
#include <GLEW/glew.h>
#include <SDL/SDL.h>
#include <iostream>
#include <string>


// Classe
class OpenGlWindow {
public:
	OpenGlWindow(std::string titreFenetre, int largeurFenetre, int hauteurFenetre);
	~OpenGlWindow();

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