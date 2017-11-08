#pragma once

#include "GraphicObject3D.h"
#include <vector>
#include "tinyxml2/tinyxml2.h"
#include "Debug/tinyxml2.lib"

class ColladaModel : public GraphicObject3D
{
	std::vector<double> m_positions;
	std::vector<double> m_normals;
	std::vector<double> m_texCoords;
	int textureId;

public:
	ColladaModel();
	~ColladaModel();
};

