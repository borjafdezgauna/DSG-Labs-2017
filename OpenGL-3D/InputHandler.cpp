#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Camera.h"
#include "GraphicObject3D.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"

InputHandler* InputHandler::m_pInputHandler = nullptr;

InputHandler::InputHandler(Renderer& renderer): m_renderer(renderer)
{
	m_pInputHandler = this;
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
		//TODO
	case 'a': 
		m_renderer.getActiveCamera()->addPositionOffset(0.5, 0, 0);
		break;
		
	case 'd': 
		m_renderer.getActiveCamera()->addPositionOffset(-0.5, 0, 0);
		break;
	case 'w': 
		m_renderer.getActiveCamera()->addPositionOffset(0, 0.5, 0);
		break;
	case 's': 
		m_renderer.getActiveCamera()->addPositionOffset(0, -0.5, 0);
		break;
	case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}