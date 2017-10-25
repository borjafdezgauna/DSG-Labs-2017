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
	case '8': activeCamera = m_renderer.getActiveCamera();
		activeCamera->addPositionOffset(0, 0.1, 0);
		break;
	case '2': 
		activeCamera = m_renderer.getActiveCamera();
		activeCamera->addPositionOffset(0, -0.1, 0); break;
	case '6': activeCamera = m_renderer.getActiveCamera();
		activeCamera->addPositionOffset(0.1, 0, 0);
		break;
	case '4': activeCamera = m_renderer.getActiveCamera();
		activeCamera->addPositionOffset(-0.1, 0, 0);
		break;
	case '+': activeCamera = m_renderer.getActiveCamera();
		activeCamera->addPositionOffset(0, 0, -0.1);
		break;
	case '-': activeCamera = m_renderer.getActiveCamera();
		activeCamera->addPositionOffset(0, 0, 0.1);
		break;
	case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}