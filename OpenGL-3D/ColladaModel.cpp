#include "ColladaModel.h"
#include "stdafx.h"

#include "../3rd-party/SOIL/src/SOIL.h"


ColladaModel::ColladaModel(char* modelURL)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(modelURL);
	tinyxml2::XMLElement* pRoot = doc.FirstChildElement("COLLADA");
	tinyxml2::XMLElement* init_from = pRoot->FirstChildElement("library_images")->FirstChildElement("image")->FirstChildElement("init_from");


	const char* texture = init_from->GetText();

	//usaremos SOIL para cargar la textura y guardaremos el	identicador que nos devuelva
	textureId = SOIL_load_OGL_texture(&texture[8], 0, 0,0);


	tinyxml2::XMLElement* pSource = pRoot->FirstChildElement("library_geometries")->FirstChildElement("geometry")->FirstChildElement("mesh")->FirstChildElement("source");

	//Coordenadas
	tinyxml2::XMLElement* floatArray1 = pSource->FirstChildElement("float_array");
	parseXMLFloatArray(floatArray1, m_positions);
	//Normales
	tinyxml2::XMLElement* floatArray2 = pSource->NextSiblingElement("source")->FirstChildElement("float_array");
	parseXMLFloatArray(floatArray2, m_normals);
	//Coordenadas Textura
	tinyxml2::XMLElement* floatArray3 = pSource->NextSiblingElement("source")->NextSiblingElement("source")->FirstChildElement("float_array");
	parseXMLFloatArray(floatArray3, m_texCoords);

	//Triángulos
	tinyxml2::XMLElement* pTriangles = pRoot->FirstChildElement("library_geometries")->FirstChildElement("geometry")->FirstChildElement("mesh")->FirstChildElement("triangles")->FirstChildElement("p");
	parseXMLIntArray(pTriangles, m_triangles);
	
}


ColladaModel::~ColladaModel()
{
}

void ColladaModel::draw()
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glBegin(GL_TRIANGLES);
	int tSize = m_triangles.size();
	for (int i = 0; i <tSize; i++)
	{
		int indTriangulo = m_triangles[i];
		int offsetTipo2 = indTriangulo * 2;
		int offsetTipo3 = indTriangulo * 3;
		
		glNormal3f(m_normals[offsetTipo3], m_normals[offsetTipo3 + 1], m_normals[offsetTipo3 + 2]);

		glTexCoord2f(m_texCoords[offsetTipo2], 1-(m_texCoords[offsetTipo2 + 1]));
		glVertex3f(m_positions[offsetTipo3], m_positions[offsetTipo3 + 1], m_positions[offsetTipo3 + 2]);
	}
	glEnd();
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
