#include "stdafx.h"
#include "InputHandler.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Renderer.h"
#include "GraphicObject2D.h"
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
	GraphicObject2D* pObj;
	//keyboard callback function
	switch (key)
	{
		//TODO

	case '8': 
		pObj= m_renderer.getObjectByName("rectangle2");
		pObj->setPosition(pObj->getX(),pObj->getY()+0.1,0);
	break;
		
	case '2': 
		pObj = m_renderer.getObjectByName("rectangle2");
		pObj->setPosition(pObj->getX(), pObj->getY()-0.1, 0);
		break;

	case '6':
		pObj = m_renderer.getObjectByName("rectangle2");
		pObj->setPosition(pObj->getX()+0.1, pObj->getY(), 0);
		break;
		
	case '4': 
		pObj = m_renderer.getObjectByName("rectangle2");
		pObj->setPosition(pObj->getX()-0.1, pObj->getY(), 0);
		break;

	case '9':
		pObj = m_renderer.getObjectByName("rectangle2");
		pObj->setRotate(pObj->getRotate() - 1);
		break;

	case '7':
		pObj = m_renderer.getObjectByName("rectangle2");
		pObj->setRotate(pObj->getRotate() + 1);
		break;


	case 'w':
		pObj = m_renderer.getObjectByName("rectangle1");
		pObj->setPosition(pObj->getX(), pObj->getY() + 0.1, 0);
		break;

	case 'x':
		pObj = m_renderer.getObjectByName("rectangle1");
		pObj->setPosition(pObj->getX(), pObj->getY() - 0.1, 0);
		break;

	case 'd':
		pObj = m_renderer.getObjectByName("rectangle1");
		pObj->setPosition(pObj->getX() + 0.1, pObj->getY(), 0);
		break;

	case 'a':
		pObj = m_renderer.getObjectByName("rectangle1");
		pObj->setPosition(pObj->getX() - 0.1, pObj->getY(), 0);
		break;

	case 'e':
		pObj = m_renderer.getObjectByName("rectangle1");
		pObj->setRotate(pObj->getRotate() - 1);
		break;

	case 'q':
		pObj = m_renderer.getObjectByName("rectangle1");
		pObj->setRotate(pObj->getRotate() + 1);
		break;
	case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}