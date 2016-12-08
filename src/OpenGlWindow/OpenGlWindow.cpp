#include "OpenGLWindow.hpp"

// Constructor
OpenGlWindow::OpenGlWindow(std::string titreFenetre, int largeurFenetre, int hauteurFenetre) : 
	m_titreFenetre(titreFenetre), 
	m_largeurFenetre(largeurFenetre),
	m_hauteurFenetre(hauteurFenetre), 
	m_fenetre(0), 
	m_contexteOpenGL(0) { 
}

// Destructor
OpenGlWindow::~OpenGlWindow() {
	SDL_GL_DeleteContext(m_contexteOpenGL);
	SDL_DestroyWindow(m_fenetre);
	SDL_Quit();
}

// Methods

// InitialiserFenetre
bool OpenGlWindow::initialiserFenetre() {
	// Initialisation de la SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	// Version d'OpenGL
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	// Double Buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


	// Création de la fenêtre
	m_fenetre = SDL_CreateWindow(m_titreFenetre.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_largeurFenetre, m_hauteurFenetre, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (m_fenetre == 0)
	{
		std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	// Création du contexte OpenGL
	m_contexteOpenGL = SDL_GL_CreateContext(m_fenetre);
	if (m_contexteOpenGL == 0)
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_DestroyWindow(m_fenetre);
		SDL_Quit();
		return false;
	}

	return true;
}

bool OpenGlWindow::initGL() {
	// On initialise GLEW
	GLenum initialisationGLEW(glewInit());
	if (initialisationGLEW != GLEW_OK)
	{
		std::cout << "Erreur d'initialisation de GLEW : " << glewGetErrorString(initialisationGLEW) << std::endl;
		SDL_GL_DeleteContext(m_contexteOpenGL);
		SDL_DestroyWindow(m_fenetre);
		SDL_Quit();
		return false;
	}

	return true;
}

void OpenGlWindow::bouclePrincipale()
{

	// Boucle principale
	bool continueLoop = true;
	while (continueLoop)
	{
		// Gestion des évènements
		SDL_WaitEvent(&m_evenements);
		if (m_evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			continueLoop = false;

		// Nettoyage de l'écran
		glClear(GL_COLOR_BUFFER_BIT);

		// Rendering
		drawTest();

		// Actualisation de la fenêtre
		SDL_GL_SwapWindow(m_fenetre);
	}
}

void OpenGlWindow::drawTest() {
	double vertices[] = { -0.5, -0.5, 0.2, 0.5, 0.5, -0.5 };
	glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, 0, vertices);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}