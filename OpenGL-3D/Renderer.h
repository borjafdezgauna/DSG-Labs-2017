#pragma once

#include "../3rd-party/tinyxml2/tinyxml2.h"
#include "Luces.h"

class GraphicObject3D;
class Camera;
#include <vector>
using namespace std;

class Renderer
{
	static Renderer* m_pRenderer;
	int m_windowWidth = 0, m_windowHeight = 0;
	int indexCamera;

	vector <Luces*> m_luces;

	vector <GraphicObject3D*> m_objects3D;

	vector <Camera*> m_cameras;
	Camera* m_pActiveCamera = nullptr;

public:
	Renderer();
	~Renderer();

	void initialize(int argc, char** argv);

	void drawScene();
	void activeNextCamera();
	void activeLight(int i);
	void addLight(Luces* pLuz);

	void addObject(GraphicObject3D* pObj);
	vector <Camera*> Renderer::getCameras();

	void addCamera(Camera* pCamera);
	Camera* getActiveCamera();

	void reshapeWindow(int x, int y);

	void cargarEscena(char* path);

	static void __drawScene();
	static void __reshapeWindow(int x, int y);
	};

