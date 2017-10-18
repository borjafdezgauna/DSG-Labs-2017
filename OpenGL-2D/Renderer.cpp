#include "stdafx.h"
#include "Renderer.h"
#include "GraphicObject2D.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"

Renderer* Renderer::m_pRenderer = nullptr;

Renderer::Renderer()
{
	m_pRenderer = this;
}


Renderer::~Renderer()
{
}

void Renderer::initialize(int argc, char** argv)
{
	//INIT GLUT/////////////////////
	////////////////////////////////
	//init window and OpenGL context
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1024, 768);
	glutCreateWindow(argv[0]);
	//glutFullScreen();


	//callback functions
	glutDisplayFunc(__drawScene);
	glutReshapeFunc(__reshapeWindow);
}

void Renderer::set2DMatrix()
{
	//set projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, 20.0);

	//set modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void Renderer::reshapeWindow(int w, int h)
{
	//Reshape callback function
	m_windowHeight = h;
	m_windowWidth = w;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Renderer::addObject(GraphicObject2D* pObj)
{
	m_objects2D.push_back(pObj);
}

void Renderer::drawScene()
{
	//clean the backbuffer
	glClear(GL_COLOR_BUFFER_BIT);

	//set the 2d modelview matrix
	set2DMatrix();

	for (auto it = m_objects2D.begin(); it != m_objects2D.end(); ++it)
	{
		(*it)->draw();
	}
}
GraphicObject2D* Renderer::getObjetcByName(std::string name) {
	for (auto it = m_objects2D.begin(); it != m_objects2D.end(); ++it)
	{
		std::string nombre =(*it)->getname();
		if (nombre == name) {
			return (*it);
		}
	}
}



//Nevermind these static functions: auxiliary stuff to fit openGL's callbacks
void Renderer::__drawScene()
{
	if (m_pRenderer)
		m_pRenderer->drawScene();
}
void Renderer::__reshapeWindow(int x, int y)
{
	if (m_pRenderer)
		m_pRenderer->reshapeWindow(x, y);
}