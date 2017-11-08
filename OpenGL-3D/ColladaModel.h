#pragma once

#include "GraphicObject3D.h"
#include <vector>
#include "../3rd-party/tinyxml2/tinyxml2.h"

class ColladaModel : public GraphicObject3D
{
	std::vector<double> m_positions;
	std::vector<double> m_normals;
	std::vector<double> m_texCoords;
	int textureId;

public:
	ColladaModel();
	~ColladaModel();


	void ColladaModel::parseXMLFloatArray(tinyxml2::XMLElement *pFloatArray, std::vector<double> & vector);
	void ColladaModel::parseXMLIntArray(tinyxml2::XMLElement *pFloatArray, std::vector<int> &vector);
};

