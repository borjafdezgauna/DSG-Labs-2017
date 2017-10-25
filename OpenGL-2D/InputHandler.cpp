#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "GraphicObject2D.h"
#include "Quad.h"
#include "MovingQuad.h"

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
	MovingQuad* mv;
	float pX, pY, pZ, rot;
	//keyboard callback function
	switch (key)
	{
		//TODO
	case '8': pObj= m_renderer.getObjectByName("quad1") ;
		pObj->setTranslate( pObj->getX(), pObj->getY()+0.1, 0); break;

	case '2': pObj = m_renderer.getObjectByName("quad1");
		pObj->setTranslate( pObj->getX(), pObj->getY() - 0.1, 0); break;

	case '6': pObj = m_renderer.getObjectByName("quad1");
		pObj->setTranslate(pObj->getX() +0.1, pObj->getY(), 0); break;

	case '7': pObj = m_renderer.getObjectByName("quad1");
		pObj->setRotation(pObj->getRotation() + 10.0); break;

	case '9': pObj = m_renderer.getObjectByName("quad1");
		pObj->setRotation(pObj->getRotation() - 10.0); break;

	case 'a': pObj = m_renderer.getObjectByName("quad2");
		pObj->setTranslate(pObj->getX() - 0.1, pObj->getY(), 0); break;

	case 'w': pObj = m_renderer.getObjectByName("quad2");
		pObj->setTranslate(pObj->getX(), pObj->getY() + 0.1, 0); break;

	case 's': pObj = m_renderer.getObjectByName("quad2");
		pObj->setTranslate(pObj->getX(), pObj->getY() - 0.1, 0); break;

	case 'd': pObj = m_renderer.getObjectByName("quad2");
		pObj->setTranslate(pObj->getX() + 0.1, pObj->getY(), 0); break;

	case 'q': pObj = m_renderer.getObjectByName("quad2");
		pObj->setRotation(pObj->getRotation() + 10.0); break;

	case 'e': pObj = m_renderer.getObjectByName("quad2");
		pObj->setRotation(pObj->getRotation() - 10.0); break;

	case '4': pObj = m_renderer.getObjectByName("quad1");
		pObj->setTranslate(pObj->getX() - 0.1, pObj->getY(), 0); break;


	case '1':  pObj = m_renderer.getObjectByName("quad1");
		 pX = pObj->getX();
		 pY = pObj->getY();
		 pZ = pObj->getY();	
		 rot =pObj->getRotation();
		mv = new MovingQuad("img/shot.png", pX, pY, pZ, cos(rot), sin(rot));

		m_renderer.addObject(mv);

	//case 'r':  pObj = m_renderer.getObjectByName("quad2");
	//	pX = pObj->getX();
	//	pY = pObj->getY();
	//	pZ = pObj->getY();
	//	rot = pObj->getRotation();
	//	mv = new MovingQuad("img/shot.png", pX, pY, pZ, cos(rot), sin(rot));

	//	m_renderer.addObject(mv);
		break;
		 break;

	case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}