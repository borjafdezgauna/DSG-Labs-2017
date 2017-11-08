#include "ColladaModel.h"



ColladaModel::ColladaModel()
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile("modelo.dae");
	tinyxml2::XMLElement* pRoot = doc.FirstChildElement(COLLADA);
	tinyxml2::XMLElement* pLibraryImages = pRoot->FirstChildElement(library_images);
}


ColladaModel::~ColladaModel()
{
}
