#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sphere.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Camera.h"
#include "ColladaModel.h"


int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();


	//init objects
	ColladaModel colladaModel1 = ColladaModel("EM208_heavy.dae");
	renderer.addObject(&colladaModel1);
	Sphere sphere1;
	sphere1.setColor(255, 0, 0);
	//renderer.addObject(&sphere1);
	sphere1.setPosition(1, 0, 1);
	Sphere sphere2;
	sphere2.setColor(0, 255, 0);
	//renderer.addObject(&sphere2);
	Camera camera;
	camera.setPosition(0, 0, 5);
	renderer.addCamera(&camera);


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