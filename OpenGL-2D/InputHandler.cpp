#include "stdafx.h"
#include "InputHandler.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Renderer.h"
#include "GraphicObject2D.h"
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
	MovingQuad* mov1;
	//keyboard callback function
	switch (key)
	{
		double x, y, z, rotation, escalax, escalay;
		GraphicObject2D* objeto, *objeto2;

		//TODO
	case '8': objeto=m_renderer.getObjetcByName("rect1");
		 y = objeto->getY();
		 x = objeto->getX();
	 z = objeto->getZ();


		y = y + 0.1;
		objeto->setPosicion(x, y, z);
		break;
	case '4': 
		objeto = m_renderer.getObjetcByName("rect1");
		y = objeto->getY();
		x = objeto->getX();
		z = objeto->getZ();


		x =  x - 0.1;
		objeto->setPosicion(x, y, z);
		break;
	case '6': 
		objeto = m_renderer.getObjetcByName("rect1");
		y = objeto->getY();
		x = objeto->getX();
		z = objeto->getZ();


		x = x + 0.1;
		objeto->setPosicion(x, y, z);
		break;
	case '2': objeto = m_renderer.getObjetcByName("rect1");
		y = objeto->getY();
		x = objeto->getX();
		z = objeto->getZ();

		y = y - 0.1;
		objeto->setPosicion(x, y, z); break;

	case 'r': objeto = m_renderer.getObjetcByName("rect1");
		rotation = objeto->getRotacion();
		rotation = rotation + 15;
		objeto->rotate(rotation); break;
	case 'q': objeto2 = m_renderer.getObjetcByName("rect2");
		rotation = objeto2->getRotacion();
		rotation = rotation + 15;
		objeto2->rotate(rotation); break;
	case 'p': 
		objeto = m_renderer.getObjetcByName("rect1");
		y = objeto->getY();
		x = objeto->getX();
		z = objeto->getZ();
		rotation = objeto->getRotacion();
		mov1 = new MovingQuad (x, y, -5, cos(rotation), sin(rotation));
		m_renderer.addObject(mov1);
		break;
		//mov1.setColor(255, 0, 0);
		//renderer.addObject(&mov1);

	case 'w': objeto2 = m_renderer.getObjetcByName("rect2");
		y = objeto2->getY();
		x = objeto2->getX();
		z = objeto2->getZ();

		y = y + 0.1;
		objeto2->setPosicion(x, y, z); break;

	case 'a': objeto2 = m_renderer.getObjetcByName("rect2");
		y = objeto2->getY();
		x = objeto2->getX();
		z = objeto2->getZ();

		x = x - 0.1;
		objeto2->setPosicion(x, y, z); break;

	case 's': objeto2 = m_renderer.getObjetcByName("rect2");
		y = objeto2->getY();
		x = objeto2->getX();
		z = objeto2->getZ();

		y = y - 0.1;
		objeto2->setPosicion(x, y, z); break;

	case 'd': objeto2 = m_renderer.getObjetcByName("rect2");
		y = objeto2->getY();
		x = objeto2->getX();
		z = objeto2->getZ();

		x = x + 0.1;
		objeto2->setPosicion(x, y, z); break;
	case 'e': objeto2 = m_renderer.getObjetcByName("rect2");
		y = objeto2->getY();
		x = objeto2->getX();
		z = objeto2->getZ();

		
		objeto2->setPosicion(x, y, z); break;

	case 27: exit(0);
	}
}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
		m_pInputHandler->processKeyboard(key, x, y);
}