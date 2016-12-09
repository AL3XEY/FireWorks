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
	void resizeWindow(int width, int height);
	bool initGL();
	void bouclePrincipale();

private:
	std::string m_titreFenetre;
	int m_largeurFenetre;
	int m_hauteurFenetre;

	SDL_Window* m_window;
	SDL_GLContext m_contexteOpenGL;
	SDL_Event m_evenements;	

	double camDist = 3.0;
	double camAngleX = 0.0;
	double camAngleY = 0.0;

	bool mouseButtonRight = false;

	void drawTest();
};

#endif