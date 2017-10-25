#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Quad.h"
#include "MovingQuad.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "../3rd-party/SOIL/src/SOIL.h"


int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();


	//init objects
	Quad rect1("quad1","img/fighter-01.png");
	rect1.setColor(255, 0, 0);
	rect1.setTranslate(0.5,0.5,0);
	renderer.addObject(&rect1);

	Quad rect2("quad2", "img/fighter-02.png");
	rect2.setColor(0, 255, 0);
	rect2.setTranslate(-0.5, -0.5, 0);
	renderer.addObject(&rect2);

	//MovingQuad rect3("img/shot.png",0,1);
	/*rect3.setColor(0, 255, 0);
	//rect3.setTranslate(-0.5, -0.5, 0);*/
	//renderer.addObject(&rect3);
	


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