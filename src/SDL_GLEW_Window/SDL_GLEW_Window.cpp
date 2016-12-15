#include "SDL_GLEW_Window.h"


// Constructor
SDL_GLEW_Window::SDL_GLEW_Window(std::string titreFenetre, int largeurFenetre, int hauteurFenetre) :
	m_titreFenetre(titreFenetre),
	m_largeurFenetre(largeurFenetre),
	m_hauteurFenetre(hauteurFenetre),
	m_window(0),
	m_contexteOpenGL(0),
	ticksBeforeUpdateMetrics(ticksBeetweenMetricsUpdate) {
}

// Destructor
SDL_GLEW_Window::~SDL_GLEW_Window() {
	SDL_GL_DeleteContext(m_contexteOpenGL);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

// Methods

// InitialiserFenetre
bool SDL_GLEW_Window::initialiserFenetre() {
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
	m_window = SDL_CreateWindow(m_titreFenetre.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_largeurFenetre, m_hauteurFenetre, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (m_window == 0)
	{
		std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	// Création du contexte OpenGL
	m_contexteOpenGL = SDL_GL_CreateContext(m_window);
	if (m_contexteOpenGL == 0)
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	return true;
}

bool SDL_GLEW_Window::initGL() {
	// On initialise GLEW
	GLenum initialisationGLEW(glewInit());
	if (initialisationGLEW != GLEW_OK)
	{
		std::cout << "Erreur d'initialisation de GLEW : " << glewGetErrorString(initialisationGLEW) << std::endl;
		SDL_GL_DeleteContext(m_contexteOpenGL);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	return true;
}

void SDL_GLEW_Window::resizeWindow(int width, int height) 
{
	m_largeurFenetre = width;
	m_hauteurFenetre = height;

	SDL_SetWindowSize(m_window, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double)width / height, 0, 1000); 
}

void SDL_GLEW_Window::bouclePrincipale()
{
	resizeWindow(800, 600);

	Uint32 dt = 0;					// delta time in ms
	Uint32 clock = SDL_GetTicks();	// last time sample in ms

	srand(static_cast <unsigned> (clock)); // Sets the random seed (for future rand())

	DemoMode demoMode; // Initialize a SandBox Mode

	// Boucle principale
	bool continueLoop = true;
	while (continueLoop)
	{
		// Gestion des évènements
		//SDL_WaitEvent(&m_evenements);
		if (m_evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			continueLoop = false;

		// Limite le Frame Rate à maxFPS
		clock = SDL_GetTicks(); //updates the clock to check the next delta time

		// Update values
		demoMode.update();

		//std::cout << "tick" << std::endl;
		dt = SDL_GetTicks() - clock; //get the current delta time for this frame

		if (dt < 1000 / maxFPS) // if timerFps is < 16.6666...7 ms (meaning it loaded the frame too fast)
		{
			//std::cout << "delai" << std::endl;
			SDL_Delay((1000 / maxFPS) - dt); //delay the frame to be in time
		}

		// Rendering
		int nbParticules = demoMode.drawScene();
		
		// Affichage des metriques (fps, nbParticules)
		int tick = SDL_GetTicks();
		double fps = double(1.0 / double(double(tick) - double(clock))) * 1000.0;
		if (ticksBeforeUpdateMetrics == 0) {
			std::cout << "fps: " << int(fps) << "\t\tparticules: " << nbParticules << std::endl;
			ticksBeforeUpdateMetrics = ticksBeetweenMetricsUpdate;
		}
		ticksBeforeUpdateMetrics--;
			


		// Actualisation de la fenêtre
		SDL_GL_SwapWindow(m_window);
	}
}

void SDL_GLEW_Window::drawTest() {
	double vertices[] = { -0.5, -0.5, 0.0, 0.5, 0.5, 0.0, 0.5, -0.5, 0.0 };
	glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, vertices);
	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}