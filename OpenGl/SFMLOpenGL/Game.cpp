#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{

}

void Game::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES); { 
	glColor3f(0, 255, 255);
	glVertex3f(-1.5, 2.0, -5.0);
	glColor3f(0, 255, 255);
	glVertex3f(-2.0, 1.0, -5.0);
	glColor3f(0, 255, 255);
	glVertex3f(-1.0, 1.0, -5.0);
	} glEnd();

	glBegin(GL_POINTS);
	{
		glVertex3f(1.5f, 0.0f, -5.0f);
	}
	glEnd();

	glBegin(GL_LINES);
	{
		glColor3f(255, 0, 255);
		glVertex3f(0.0f, 0.5f, -5.0f); // origin of the FIRST line
		glColor3f(255, 0, 255);
		glVertex3f(1.0f, 0.5f, -5.0f);
	}// ending point of the FIRST line
	glEnd();

	glBegin(GL_LINE_STRIP);
	{
		glColor3f(255, 255, 255);
		glVertex3f(-1.5, -2.0, -5.0); // origin of the FIRST line
		glColor3f(255, 255, 255);
		glVertex3f(-2.0, -1.0, -5.0);
		glColor3f(255, 255, 255);
		glVertex3f(-1.0, -1.0, -5.0);
	}// ending point of the FIRST line
	glEnd();

	glBegin(GL_LINE_LOOP);
	{
		glColor3f(255, 255, 0);
		glVertex3f(1.5, -2.0, -5.0); // origin of the FIRST line
		glColor3f(255, 255, 0);
		glVertex3f(2.0, -1.0, -5.0);
		glColor3f(255, 255, 0);
		glVertex3f(1.0, -1.0, -5.0);
	}// ending point of the FIRST line
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	{
		glColor3f(0, 255, 0);
		glVertex3f(0.5f, 1.75f, -5.0f);
		glColor3f(0, 255, 0);
		glVertex3f(0.5f, 0.75f, -5.0f);
		glColor3f(0, 255, 0);
		glVertex3f(1.0f, 1.75f, -5.0f);
		glColor3f(0, 255, 0);
		glVertex3f(1.0f, 0.75f, -5.0f);
		glColor3f(0, 255, 0);
		glVertex3f(1.5, 1.75f, -5.0f);
		glColor3f(0, 255, 0);
		glVertex3f(1.5, 0.75f, -5.0f);
	} glEnd();

	glBegin(GL_TRIANGLE_FAN);
	{
		glColor3f(255, 255, 0);
		glVertex3f(-1.0f, -0.5f, -8.0f);
		glColor3f(255, 0, 255);
		glVertex3f(1.0f, -0.5f, -8.0f);
		glColor3f(0, 255, 255);
		glVertex3f(0.0f, 0.5f, -8.0f);
		glColor3f(0, 0, 255);
		glVertex3f(-1.5f, 0.0f, -8.0f);
		glColor3f(0, 255, 0);
		glVertex3f(-1.8f, -1.0f, -8.0f);
		glColor3f(255, 0, 0);
		glVertex3f(0.2f, -1.5f, -8.0f);
	}glEnd();

	glBegin(GL_QUADS);//not done
	{
		glVertex3f(-2.0f, 0.5f, -8.0f);
		glVertex3f(-2.0f, 1.0f, -8.0f);
		glVertex3f(-1.0f, 1.0f, -8.0f);
		glVertex3f(-1.0f, 0.5f, -8.0f);
	}glEnd();


	window.display();
}

void Game::unload()
{
}

