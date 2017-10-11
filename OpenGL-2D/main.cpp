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
	Quad a;
	Quad rect1;
	rect1.setColor(255, 0, 0);
	renderer.addObject(&rect1);
	Quad rect2;
	rect2.setColor(0, 255, 0);
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