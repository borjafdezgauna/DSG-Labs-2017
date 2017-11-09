#include "stdafx.h"
#include "ColladaModel.h"
#include "../3rd-party/SOIL/src/SOIL.h"



ColladaModel::ColladaModel(const char *filename)
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(filename);
	
	tinyxml2::XMLElement* pRoot = doc.FirstChildElement("COLLADA");
	tinyxml2::XMLElement* init_from = pRoot->FirstChildElement("library_images") -> FirstChildElement("image") -> FirstChildElement("init_from");
	const char* textura = init_from->GetText();
	textureId = SOIL_load_OGL_texture(&textura[8], 0, 0, 0);

	
	tinyxml2::XMLElement* mesh = pRoot->FirstChildElement("library_geometries")->FirstChildElement("geometry")->FirstChildElement("mesh");
	tinyxml2::XMLElement* source1 = mesh-> FirstChildElement("source");
	tinyxml2::XMLElement* float_array1 = source1 -> FirstChildElement("float_array");
	parseXMLFloatArray(float_array1,m_positions);

	tinyxml2::XMLElement* source2 = source1->NextSiblingElement("source");
	tinyxml2::XMLElement* float_array2 = source2->FirstChildElement("float_array");
	parseXMLFloatArray(float_array2, m_normals);


	tinyxml2::XMLElement* source3 = source2->NextSiblingElement("source");
	tinyxml2::XMLElement* float_array3 = source3->FirstChildElement("float_array");
	parseXMLFloatArray(float_array3, m_texCoords);

	tinyxml2::XMLElement* triangles = mesh->FirstChildElement("triangles");
	tinyxml2::XMLElement* input = triangles ->FirstChildElement("p");
	parseXMLIntArray(input, m_triangles);

	m_pitch = 270;

}



void ColladaModel::parseXMLFloatArray(tinyxml2::XMLElement *pFloatArray, std::vector<double> &vector)
{
	char* pCharArray = (char *)pFloatArray->GetText();
	char* nextToken;
	char* pt = strtok_s(pCharArray, " ", &nextToken);
	while (pt != 0)
	{
		vector.push_back( atof(pt));
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
		vector.push_back( atoi(pt));
		pt = strtok_s(0, " ", &nextToken);
	}
}
ColladaModel::~ColladaModel()
{
}

void ColladaModel::draw() 
{
	glEnable(GL_TEXTURE);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glBegin(GL_TRIANGLES);
	int n = m_triangles.size();
	for (int i = 0; i < n;i++) {

		int offset2 = m_triangles[i]*2;
		int offset3 = m_triangles[i]*3;

		glNormal3f(m_normals[offset3],m_normals[offset3+1],m_normals[offset3 +2]);
		glTexCoord2f(m_texCoords[offset2],1- m_texCoords[offset2+1]);
		glVertex3f(m_positions[offset3], m_positions[offset3 + 1], m_positions[offset3 + 2]);
	
	}


	glEnd();
}