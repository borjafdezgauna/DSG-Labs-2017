#include "stdafx.h"
#include "ColladaModel.h"
#include "../3rd-party/SOIL/src/SOIL.h"


ColladaModel::ColladaModel(char* textura)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(textura);
	tinyxml2::XMLElement* pRoot = doc.FirstChildElement("COLLADA");
	tinyxml2::XMLElement* init_from = pRoot->FirstChildElement("library_images")->FirstChildElement("image")->FirstChildElement("init_from");
	const char* ptextura = init_from->GetText();
	textureId = SOIL_load_OGL_texture(&ptextura[8], 0, 0, 0);
	tinyxml2::XMLElement* pMesh = pRoot->FirstChildElement("library_geometries")->FirstChildElement("geometry")->FirstChildElement("mesh");
	tinyxml2::XMLElement* pSource1 = pMesh->FirstChildElement("source");
	tinyxml2::XMLElement* float_array1 = pSource1->FirstChildElement("float_array");
	parseXMLFloatArray(float_array1, m_positions);
	tinyxml2::XMLElement* float_array2 = pSource1->NextSiblingElement("source")->FirstChildElement("float_array");
	parseXMLFloatArray(float_array2, m_normals);
	tinyxml2::XMLElement* float_array3 = pSource1->NextSiblingElement("source")->NextSiblingElement("source")->FirstChildElement("float_array");
	parseXMLFloatArray(float_array3, m_texCoords);
	tinyxml2::XMLElement* triangles = pMesh->FirstChildElement("triangles")->FirstChildElement("p");
	parseXMLIntArray(triangles, m_triangles);
	m_pitch = 270;
}


ColladaModel::~ColladaModel()
{
}

void ColladaModel::parseXMLFloatArray(tinyxml2::XMLElement *pFloatArray, std::vector<double> & vector) {
	char* pCharArray = (char*)pFloatArray->GetText();
	char* nextToken;
	char* pt = strtok_s(pCharArray, " ", &nextToken);
	while (pt != 0)
	{
		vector.push_back(atof(pt));
		pt = strtok_s(0, " ", &nextToken);
	}
}
void ColladaModel::parseXMLIntArray(tinyxml2::XMLElement *pFloatArray, std::vector<int> &vector)
{
	char* pCharArray = (char*)pFloatArray->GetText();
	char* nextToken;
	char* pt = strtok_s(pCharArray, " ", &nextToken);
	while (pt != 0)
	{
		vector.push_back(atoi(pt));
		pt = strtok_s(0, " ", &nextToken);
	}
}
void ColladaModel::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexEnvf(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBegin(GL_TRIANGLES);
	int tamaño = m_triangles.size();
	for (int j = 0; j <tamaño; j++)
	{	
		int numTriangulo = m_triangles[j];
		int offset3 = numTriangulo * 3;
		int offset2 = numTriangulo * 2;
		glNormal3f(m_normals[offset3], m_normals[offset3 + 1], m_normals[offset3 + 2]);

		glTexCoord2f(m_texCoords[offset2], 1-m_texCoords[offset2 + 1]);
		glVertex3f(m_positions[offset3], m_positions[offset3 + 1], m_positions[offset3 + 2]);
	}
	glEnd();
}