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


	tinyxml2::XMLDocument doc;
	doc.LoadFile("MiProyecto3D.xml");
	tinyxml2::XMLElement* pRoot = doc.FirstChildElement("PROJECT");
	tinyxml2::XMLElement* Objects = pRoot->FirstChildElement("scene")->FirstChildElement("Objects");
	tinyxml2::XMLElement* Object = Objects->FirstChildElement("Object");
	
	//Sacar Esto a otra clase
	while(Object)
	{ 
	ColladaModel *colladaModel1 = new ColladaModel(Object->FirstChildElement("url")->GetText());

	tinyxml2::XMLElement* posArray1 = Object->FirstChildElement("position_float_array");
	std::vector<double> m_positions;
	colladaModel1->parseXMLFloatArray(posArray1, m_positions);
	colladaModel1->setPosition(m_positions[0], m_positions[1], m_positions[2]);

	tinyxml2::XMLElement* posArray2 = Object->FirstChildElement("rotation_float_array");
	std::vector<double> m_rotation;
	colladaModel1->parseXMLFloatArray(posArray2, m_rotation);
	colladaModel1->setRotation(m_rotation[0], m_rotation[1], m_rotation[2]);

	tinyxml2::XMLElement* posArray3 = Object->FirstChildElement("scale_float_array");
	std::vector<double> m_scale;
	colladaModel1->parseXMLFloatArray(posArray3, m_scale);
	colladaModel1->setScale(m_scale[0], m_scale[1], m_scale[2]);

	renderer.addObject(colladaModel1);

	Object = Object->NextSiblingElement("Object");
	}
	
	//ToDo Varias cameras

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