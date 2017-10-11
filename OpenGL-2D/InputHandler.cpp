#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "GraphicObject2D.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"

InputHandler* InputHandler::m_pInputHandler = nullptr;

InputHandler::InputHandler(Renderer& renderer): m_renderer(renderer)
{
	m_pInputHandler = this;
	objectListening = "Q_Rect1";
}


InputHandler::~InputHandler()
{
}

void InputHandler::initialize()
{
	glutKeyboardFunc(__processKeyboard);
}


void InputHandler::processKeyboard(unsigned char key, int x, int y)
{
	//keyboard callback function
	switch (key)
	{
	case '1':
		objectListening = "Q_Rect1";
		break;

	case '2':
		objectListening = "Q_Rect2";
		break;
		
		//TODO
	case 'q':
	case 'Q':
		m_renderer.getObjectByName(objectListening)->rotateAmount(10, 0, 0, 1);
		break;

	case 'e':
	case 'E':
		m_renderer.getObjectByName(objectListening)->rotateAmount(-10, 0, 0, 1);
		break;


	case 'w':
	case 'W':
		m_renderer.getObjectByName(objectListening)->moveAmount(0, 0.1,0);
		break;

	case 's':
	case 'S':
		m_renderer.getObjectByName(objectListening)->moveAmount(0, -0.1, 0);
		break;

	case 'd':
	case 'D':
		m_renderer.getObjectByName(objectListening)->moveAmount(0.1, 0, 0);
		break;

	case 'a':
	case 'A':
		m_renderer.getObjectByName(objectListening)->moveAmount(-0.1, 0, 0);
		break;

	case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}