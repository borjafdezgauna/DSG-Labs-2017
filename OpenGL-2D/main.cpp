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
	Quad rect1("rectangle1");
	rect1.setColor(255, 0, 0);
	renderer.addObject(&rect1);
	rect1.setPosition(0.5,0.5,0);
	rect1.setTexture("img/alien-01.png");
	MovingQuad disparo1("disparo1", 1, 1);
	disparo1.setTexture("img/shot.png");
	renderer.addObject(&disparo1);
	Quad rect2("rectangle2");
	rect2.setColor(0, 255, 0);
	renderer.addObject(&rect2);
	rect2.setPosition(-0.5,-0.5, 0);
	rect2.setTexture("img/alien-02.png");
	MovingQuad disparo2("disparo2", -1, -1);
	disparo2.setTexture("img/shot.png");
	renderer.addObject(&disparo2);


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