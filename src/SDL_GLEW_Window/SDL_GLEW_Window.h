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

	double eyeX = 0.0;
	double eyeY = 0.0;
	double eyeZ = -3.0;
	double centerX = 0.0;
	double centerY = 0.0;
	double centerZ = 0.0;
	double upX = 0.0;
	double upY = 1.0;
	double upZ = 0.0;

	bool mouseButtonRight = false;

	void drawTest();
};

#endif