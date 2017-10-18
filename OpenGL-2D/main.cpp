#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Quad.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "MovingQuad.h"



int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();


	//init objects
	/*MovingQuad mov1(0, 0, -5, 25, 25);
	mov1.setColor(255, 0, 0);
	renderer.addObject(&mov1);*/
	Quad rect1 ("rect1");
	rect1.setColor(255, 0, 0);
	rect1.escalar(-0.1, -0.1);
	renderer.addObject(&rect1);
	Quad rect2 ("rect2");
	rect2.setColor(0, 255, 0);
	renderer.addObject(&rect2);

	rect1.setPosicion(-0.5, -0.5, 0);
	rect2.setPosicion(0.5, 0.5, 0);
	
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