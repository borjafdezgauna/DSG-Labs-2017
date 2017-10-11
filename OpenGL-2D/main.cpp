#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Quad.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"



int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();


	//init objects
	Quad rect1 ("Q_Rect1");
	rect1.setColor(255, 0, 0);
	rect1.setPosition(-0.5,-0.5,-2);
	rect1.setRotation(45, 0, 0, 1);
	renderer.addObject(&rect1);

	Quad rect2 ("Q_Rect2");
	rect2.setColor(0, 255, 0);
	rect2.setPosition(0.5, 0.5, -2);
	renderer.addObject(&rect2);


	while (1)
	{
		//UPDATE////////////////////
		////////////////////////////
		//process queued events
		glutMainLoopEvent();


		//RENDER////////////////////
		////////////////////////////
		glutPostRedisplay();
		glutSwapBuffers();
	}
   return 0;
   

}