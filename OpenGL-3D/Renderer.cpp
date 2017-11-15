#include "stdafx.h"
#include "Renderer.h"
#include "GraphicObject3D.h"
#include "Camera.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Camera.h"
#include "ColladaModel.h"
#include "Luces.h"

Renderer* Renderer::m_pRenderer = nullptr;

Renderer::Renderer()
{
	m_pRenderer = this;
}


Renderer::~Renderer()
{
}

void Renderer::initialize(int argc, char** argv)
{

	//INIT GLUT/////////////////////
	////////////////////////////////
	//init window and OpenGL context
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1024, 768);
	glutCreateWindow(argv[0]);
	//glutFullScreen();

	//callback functions
	glutDisplayFunc(__drawScene);
	glutReshapeFunc(__reshapeWindow);
	glEnable(GL_DEPTH_TEST);
}



void Renderer::reshapeWindow(int w, int h)
{
	//Reshape callback function
	m_windowHeight = h;
	m_windowWidth = w;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Renderer::addObject(GraphicObject3D* pObj)
{
	m_objects3D.push_back(pObj);
}
void Renderer::activeNextCamera()
{
	indexCamera = (indexCamera + 1) % (m_cameras.size());
	m_pActiveCamera = m_cameras[indexCamera];

}


vector <Camera*> Renderer::getCameras()
{
	return m_cameras;
}

void Renderer::activeLight(int i)
{
	m_luces[i]->cambiarActivacion();
}

void Renderer::addLight(Luces* pLuz)
{
	m_luces.push_back(pLuz);
}

void Renderer::addCamera(Camera* pCamera)
{
	m_cameras.push_back(pCamera);
	m_pActiveCamera = pCamera;
	indexCamera = m_cameras.size() - 1;
}

Camera* Renderer::getActiveCamera()
{
	return m_pActiveCamera;
}

void Renderer::drawScene()
{
	//clean the backbuffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//set the 2d modelview matrix
	if (m_pActiveCamera!=nullptr)
		m_pActiveCamera->applyMatrix();

	for (auto it = m_objects3D.begin(); it != m_objects3D.end(); ++it)
	{
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		(*it)->applyMatrix();
		(*it)->draw();
		glPopMatrix();
	}
}


void Renderer::cargarEscena(char* path)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(path);
	tinyxml2::XMLElement* scene = doc.FirstChildElement("scene");
	tinyxml2::XMLElement* models = scene->FirstChildElement("Models");
	tinyxml2::XMLElement* model = models->FirstChildElement("Model");
	while (model != 0) {
		const char* path= model->Attribute("Path");
		ColladaModel* pNewModel = new ColladaModel((char*)path);
		const char* x = model->Attribute("x");
		const char* y = model->Attribute("y");
		const char* z = model->Attribute("z");
		const char* pitch = model->Attribute("pitch");
		const char* yaw = model->Attribute("yaw");
		const char* roll = model->Attribute("roll");
		pNewModel->setPosition(atof(x), atof(y), atof(z));
		pNewModel->setRotation(atof(yaw), atof(pitch), atof(roll));

		//add the model to the list
		addObject(pNewModel);
		model = model->NextSiblingElement("Model");
	}
	tinyxml2::XMLElement* camaras = scene->FirstChildElement("Camaras");
	tinyxml2::XMLElement* camara = camaras->FirstChildElement("Camara");
	while (camara != 0) {
		Camera* camera=new Camera();
		const char* x = camara->Attribute("x");
		const char* y = camara->Attribute("y");
		const char* z = camara->Attribute("z");
		const char* pitch = camara->Attribute("pitch");
		const char* yaw = camara->Attribute("yaw");
		const char* roll = camara->Attribute("roll");
		camera->setPosition(atof(x), atof(y), atof(z));
		camera->setRotation(atof(yaw), atof(pitch), atof(roll));
		addCamera(camera);
		camara = camara->NextSiblingElement("Camara");
	}
	tinyxml2::XMLElement* luces = scene->FirstChildElement("Luces");
	tinyxml2::XMLElement* luz = luces->FirstChildElement("Luz");
	while (luz != 0) {
		const char* amb_r = luz->Attribute("amb_r");
		const char* amb_g = luz->Attribute("amb_g");
		const char* amb_b = luz->Attribute("amb_b");
		const char* dif_r = luz->Attribute("dif_r");
		const char* dif_g = luz->Attribute("dif_g");
		const char* dif_b = luz->Attribute("dif_b");
		Luces* luces = new Luces(atof(amb_r), atof(amb_g), atof(amb_b), atof(dif_r), atof(dif_g), atof(dif_b));
		addLight(luces);

		luz = luz->NextSiblingElement("Luz");
	}
	
}


//Nevermind these static functions: auxiliary stuff to fit openGL's callbacks
void Renderer::__drawScene()
{
	if (m_pRenderer)
		m_pRenderer->drawScene();
}
void Renderer::__reshapeWindow(int x, int y)
{
	if (m_pRenderer)
		m_pRenderer->reshapeWindow(x, y);
}