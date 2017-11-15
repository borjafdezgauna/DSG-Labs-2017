#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Camera.h"
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
	
	Camera* activeCamera;
	//keyboard callback function
	switch (key)
	{
		//TODO
	case 'w': activeCamera = m_renderer.getActiveCamera();
		activeCamera->addPositionOffset(0, 0.1, 0);
		break;
	case 'a': 
		activeCamera = m_renderer.getActiveCamera();
		activeCamera->addPositionOffset(0, -0.1, 0); break;
	case 'd': activeCamera = m_renderer.getActiveCamera();
		activeCamera->addPositionOffset(0.1, 0, 0);
		break;
	case 's': activeCamera = m_renderer.getActiveCamera();
		activeCamera->addPositionOffset(-0.1, 0, 0);
		break;
	case '+': activeCamera = m_renderer.getActiveCamera();
		activeCamera->addPositionOffset(0, 0, -0.1);
		break;
	case '-': activeCamera = m_renderer.getActiveCamera();
		activeCamera->addPositionOffset(0, 0, 0.1);
		break;
	case 'c': 
		m_renderer.activeNextCamera();
		break;
	case '0':
		m_renderer.activeLight(0);
		break;
	case '1':
		m_renderer.activeLight(1);
		break;
	case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}