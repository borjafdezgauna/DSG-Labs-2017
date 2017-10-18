#pragma once

class GraphicObject2D;
#include <vector>
using namespace std;

class Renderer
{
	static Renderer* m_pRenderer;
	int m_windowWidth = 0, m_windowHeight = 0;

	vector <GraphicObject2D*> m_objects2D;

	void set2DMatrix();
public:
	Renderer();
	~Renderer();

	void initialize(int argc, char** argv);

	void drawScene();
	void addObject(GraphicObject2D* pObj);
	void reshapeWindow(int x, int y);

	static void __drawScene();
	static void __reshapeWindow(int x, int y);
	GraphicObject2D* Renderer::getObjetcByName(string name);
};

